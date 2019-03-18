#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

I2C_HandleTypeDef I2C_handle;        // defining the I2C configuration structure
TIM_HandleTypeDef TimHandle;
GPIO_InitTypeDef SCL_SDA_config; // configure GPIOs for I2C data and clock lines
static void Error_Handler(void);
static void SystemClock_Config(void);
volatile uint8_t read_temp_reg = 0;
volatile uint8_t read_temp_val;
uint8_t write_out_value[8];

/* 7 bit address of an I2C sensor shifted to left 1 bit, leaving place for W/R bit,
 * which is inserted by the HAL_I2C_Master_Transmit and HAL_I2C_Master_Receive */
#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define LED_MATRIX_ADDRESS  (0b1110000 << 1)
uint8_t system_setup_register = 0x21;
uint8_t row_int_set_register = 0xA0;
uint8_t display_setup_register = 0x81;

void led_matrix() {
	//HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_reg, sizeof(read_temp_reg), 100);

	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS,
			&system_setup_register, sizeof(system_setup_register), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS,
			&display_setup_register, sizeof(display_setup_register), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS,
			&system_setup_register, sizeof(system_setup_register), 100);
}

void init_tim2() {

	/* configuring the basic mode of your timer (which direction should it count, what is the maximum value, etc.) */
	//initialize TIM2
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	//giving clock
	// configuriation of the basic mode of the timer (which direction should it count, what is the maximum value, etc.)
	HAL_TIM_Base_DeInit(&TimHandle);
	TimHandle.Instance = TIM2;			//register base address
	TimHandle.Init.Prescaler = 10800 - 1; // 108000000 / 10800 = 10000 -> speed of 1 count-up: 1 /10000 s = 0.1 ms
	TimHandle.Init.Period = 10000 - 1; // 10000 x 0.1 ms = 1000 ms = 1.0 s period */
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&TimHandle); 	 //configure the timer
	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0); //set TIM2 interrupt priority
	HAL_NVIC_EnableIRQ(TIM2_IRQn); //enable the interrupt to HAL
}

void light_on(int number) {
	uint8_t chars[][8] = { { 0x00, 0x00, 0xbf, 0xa0, 0xa0, 0xbf, 0x00, 0x00 }, //0
			{ 0x00, 0x00, 0x00, 0xa0, 0xbf, 0x80, 0x00, 0x00 }, //1
			{ 0x00, 0x00, 0xa7, 0xa4, 0xa4, 0xbc, 0x00, 0x00 }, //2
			{ 0x00, 0x00, 0xa4, 0xa4, 0xa4, 0xbf, 0x00, 0x00 }, //3
			{ 0x00, 0x00, 0x3c, 0x04, 0x04, 0xbf, 0x00, 0x00 }, //4
			{ 0x00, 0x00, 0xbc, 0xa4, 0xa4, 0xa7, 0x00, 0x00 }, //5
			{ 0x00, 0x00, 0xbf, 0xa4, 0xa4, 0xa7, 0x00, 0x00 }, //6
			{ 0x00, 0x00, 0x38, 0x20, 0x20, 0xbf, 0x00, 0x00 }, //7
			{ 0x00, 0x00, 0xbf, 0xa4, 0xa4, 0xbf, 0x00, 0x00 }, //8
			{ 0x00, 0x00, 0xbc, 0xa4, 0xa4, 0xbf, 0x00, 0x00 }, //9
			{ 0x00, 0x60, 0x60, 0x9f, 0x90, 0x90, 0x90, 0x00 }, //°C
			{ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff }, //all
			{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } //clear
	};

	for (int i = 0; i < 8; i++) {
		write_out_value[i] = chars[number][i];
	}
}

void write_temp_on_slide() {
	uint8_t temp[3];
	temp[0] = read_temp_val / 10;
	temp[1] = read_temp_val % 10;
	temp[2] = 10;

	int value[24];
	for (int k = 0; k < 24; k++) {
		value[k] = k;
	}
	int one_line = 0;
	while (one_line < 24) { // 3*8writing
		int counter = 0;
		int led_line = 0;
		while (counter < 24) { // 3*8 value
			for (int j = 0; j < 3; j++) {
				light_on(temp[j]);
				for (int i = 0; i < 8; i++) {
					if (value[counter] < 8) {
						HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS,
								led_line * 2, sizeof(uint8_t),
								&write_out_value[i], 1, 100);
						led_line++;
					}
					counter++;
				}
			}
			HAL_Delay(100);
			for (int k = 0; k < 24; k++) {
				if (value[k] == 0)
					value[k] = 23;
				else
					value[k]--;
			}

		}
		one_line++;
	}
}

/*void temp_write() {
	uint8_t temp[3];
	temp[0] = read_temp_val / 10;
	temp[1] = read_temp_val % 10;
	temp[2] = 10;

	for (int j = 0; j < 3; j++) {
		light_on(temp[j]);
		for (int i = 0; i < 8; i++) {
			HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, i * 2,
					sizeof(uint8_t), &write_out_value[i], 1, 100);
		}
		HAL_Delay(500);
	}
}
*/
int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_tim2();

	__HAL_RCC_GPIOB_CLK_ENABLE()
	; /* enable GPIO clock */

	SCL_SDA_config.Pin = GPIO_PIN_8 | GPIO_PIN_9; /* PB8: SCL, PB9: SDA */
	SCL_SDA_config.Pull = GPIO_PULLUP;
	SCL_SDA_config.Mode = GPIO_MODE_AF_OD; /* configure in pen drain mode */
	SCL_SDA_config.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

	__HAL_RCC_I2C1_CLK_ENABLE()
	; /* enable the clock of the used peripheral */

	/* defining the UART configuration structure */
	I2C_handle.Instance = I2C1;
	I2C_handle.Init.Timing = 0x40912732;
	I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2C_handle);

	HAL_TIM_Base_Start_IT(&TimHandle);
	led_matrix();

	while (1) {
		write_temp_on_slide();
	}

}
void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TimHandle.Instance) {
		HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS,
				&read_temp_reg, sizeof(read_temp_reg), 100);
		HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_val,
				sizeof(read_temp_val), 100);
	}
}

static void Error_Handler(void) {
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

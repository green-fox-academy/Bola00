#ifndef COMMANDS_H_
#define COMMANDS_H_

char* get_morse (char* checking){
	if (checking == 'A'){
		return  "01";
	}else if (checking == 'B'){
		return  "1000";
	}else if (checking == 'C'){
		return  "1010";
	}else if (checking == 'D'){
		return  "100";
	}else if(checking == 'E'){
		return  "1";
	}else if (checking == 'F'){
		return  "0010";
	}else if (checking == 'G'){
		return  "110";
	}else if (checking == 'H'){
		return  "0000";
	}else if (checking == 'I'){
		return  "00";
	}else if (checking == 'J'){
		return  "0111";
	}else if (checking == 'K'){
		return  "101";
	}else if (checking == 'L'){
		return  "0100";
	}else if (checking == 'M'){
		return  "11";
	}else if (checking == 'N'){
		return  "10";
	}else if (checking == 'O'){
		return  "111";
	}else if (checking == 'P'){
		return  "0110";
	}else if (checking == 'Q'){
		return  "1101";
	}else if (checking == 'R'){
		return  "010";
	}else if (checking == 'S'){
		return  "000";
	}else if (checking == 'T'){
		return  "1";
	}else if (checking == 'U'){
		return  "001";
	}else if (checking == 'V'){
		return  "0001";
	}else if (checking == 'W'){
		return  "011";
	}else if (checking == 'X'){
		return  "1001";
	}else if (checking == 'Y'){
		return  "1011";
	}else if (checking == 'Z'){
		return  "1100";
	}else if (checking == '0'){
		return  "11111";
	}else if (checking == '1'){
		return  "01111";
	}else if (checking == '2'){
		return  "00111";
	}else if (checking == '3'){
		return  "00011";
	}else if (checking == '4'){
		return  "00001";
	}else if (checking == '5'){
		return  "00000";
	}else if (checking == '6'){
		return  "10000";
	}else if (checking == '7'){
		return  "11000";
	}else if (checking == '8'){
		return  "11100";
	}else if (checking == '9'){
		return  "11110";
	}else{
	 return "2";
	}
}

#endif /* COMMANDS_H_ */

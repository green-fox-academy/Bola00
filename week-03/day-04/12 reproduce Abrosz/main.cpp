#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

//Draws geometry on the canvas
void draw();


//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;


void draw(int widthmin, int widthmax, int heightmin, int heightmax, int counter)
{if (counter  > 0){
    int vertical_one = widthmin + ((widthmax - widthmin)/3);
    int vertical_two = widthmin + ((widthmax - widthmin)/3*2);
    int horizontal_one = heightmin + ((heightmax - heightmin)/3);
    int horizontal_two = heightmin + ((heightmax - heightmin)/3*2);



        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
        SDL_RenderDrawLine(gRenderer, vertical_one, heightmin, vertical_one, heightmax);
        SDL_RenderDrawLine(gRenderer, vertical_two, heightmin, vertical_two, heightmax);
        SDL_RenderDrawLine(gRenderer, widthmin, horizontal_one, widthmax, horizontal_one);
        SDL_RenderDrawLine(gRenderer, widthmin, horizontal_two, widthmax, horizontal_two);

        draw((vertical_one), (vertical_two), (heightmin), (horizontal_one),
             counter - 1);
        draw((widthmin), (vertical_one), (horizontal_one),(horizontal_two),
             counter - 1);
        draw((vertical_two), (widthmax), (horizontal_one),(horizontal_two),
             counter - 1);
        draw((vertical_one), (vertical_two), (horizontal_two), (heightmax),
             counter - 1);

    }
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Line in the middle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{

    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 255);
        SDL_RenderClear(gRenderer);

        draw(0, SCREEN_WIDTH,0, SCREEN_HEIGHT, 5);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
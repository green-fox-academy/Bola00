#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 520;
const int SCREEN_HEIGHT = 520;

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

void draw(int x_minimum, int x_maximum, int y_minimum,int y_maximum, int counter)
{ if (counter > 0){

        SDL_Point points[7] =
                {
                {(x_minimum + (x_maximum - x_minimum) / 4),     y_minimum},
                {(x_minimum + (x_maximum - x_minimum) / 4 * 3), y_minimum},
                {x_maximum, (y_minimum +(y_maximum-y_minimum)/2) },
                {x_minimum + (x_maximum - x_minimum) / 4 * 3, y_maximum},
                {(x_minimum + (x_maximum - x_minimum) / 4),     y_maximum},
                {x_minimum, (y_minimum +(y_maximum-y_minimum)/2)},
                {(x_minimum + (x_maximum - x_minimum) / 4),     y_minimum},
                };
      //  int point_one[2] = { (x_minimum + (x_maximum - x_minimum)/4) , y_maximum};
  //  int point_two[2] = { (x_minimum + (x_maximum - x_minimum)/4*3) , y_maximum};


        SDL_SetRenderDrawColor(gRenderer, 0x00 /*R*/, 0x00 /*G*/, 0x00 /*B*/, 0xFF /*A*/);
      //  SDL_RenderDrawLine (gRenderer, point_one[0],point_one[1],point_two[0],point_two[1]);
       SDL_RenderDrawLines (gRenderer, points, 7);
        draw( (x_minimum + (x_maximum - x_minimum) / 8) ,(x_minimum + (x_maximum - x_minimum) / 8*5) , y_minimum,
            (y_minimum +(y_maximum-y_minimum)/2),counter-1);

    draw( (x_minimum + (x_maximum - x_minimum) / 8) ,(x_minimum + (x_maximum - x_minimum) / 8*5) ,
            (y_minimum +(y_maximum-y_minimum)/2),  y_maximum,counter-1);
    draw( (x_minimum + (x_maximum - x_minimum) / 2) ,x_maximum,
              (y_minimum +(y_maximum-y_minimum)/4),  y_maximum - (y_maximum-y_minimum)/4, counter-1);

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
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        int Counter = 5;
        draw(0, 512, 0, 512,  Counter);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}
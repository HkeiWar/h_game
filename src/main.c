#include "SDL.h"
extern int printf1();
int main( int argc, char* args[] ) 
{ 
    // SDL_Surface* hello = NULL;
    SDL_Window * screen = NULL;
    // //启动SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
    // hello = SDL_LoadBMP("");

    screen = SDL_CreateWindow("SDL2 Displaying Image",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    printf1();
    SDL_Delay(2000);
    // //退出SDL 
    SDL_Quit();
    return 0;
} 
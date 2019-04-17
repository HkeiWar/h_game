#include <string.h>
#include "SDL.h"
#include "SDL_image.h"

/**
 * 加载图片
 **/
SDL_Texture * Load_Imgage(SDL_Renderer * renderer,const char * text)
{
    IMG_Init();
    SDL_Surface * bmp = NULL;
    bmp = SDL_LoadBMP(text);
    if(!bmp){
        return NULL;
    }
    return SDL_CreateTextureFromSurface(renderer,bmp);
}

int main( int argc, char * args[] ) 
{ 
    
    SDL_Window * screen = NULL;

    //渲染器
    SDL_Renderer * renderer = NULL;

    //硬件加速
    SDL_Texture * t = NULL;

    SDL_Rect * rect = NULL;


    // //启动SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
    
    screen = SDL_CreateWindow("test",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED);
    
    t = Load_Imgage(renderer,"assets\\test.bmp");
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,t,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(20000);

    SDL_DestroyTexture(t);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);

    // //退出SDL 
    SDL_Quit();
    return 0;
} 
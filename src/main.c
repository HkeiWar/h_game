#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "config.h"
#include <stdio.h>

//主界面
static SDL_Window *game_window = NULL;

//渲染器
static SDL_Renderer *game_renderer = NULL;

//纹理
static SDL_Texture *game_texture = NULL;

//游戏状态
static int game_status = 1;

/**
 * 加载图片
 **/
SDL_Texture *load_image(SDL_Renderer *renderer, const char *text)
{
    IMG_Init(0);
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, text);
    if (!texture)
    {
        return NULL;
    }
    IMG_Quit();
    return texture;
}

SDL_Surface *load_image1(const char *text)
{
    IMG_Init(0);
    SDL_Surface *surface = NULL;
    surface = IMG_Load(text);
    if (!surface)
    {
        return NULL;
    }
    IMG_Quit();
    return surface;
}

//初始化界面
static void init();
//开始
static void start_game();
//退出
static void quit();

int main(int argc, char *args[])
{
    init();
    while (game_status)
    {
        start_game();
        SDL_Delay(100);
    }

    quit();
    return 0;
}

static void init()
{

    //启动SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    game_window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

    game_renderer = SDL_CreateRenderer(game_window, -1, SDL_RENDERER_ACCELERATED);

    game_texture = SDL_CreateTexture(game_renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

static void start_game()
{
    SDL_Event sdl_event;

    // SDL_Surface *su = load_imgage1("assets\\test.jpg");
    // SDL_RenderClear(game_renderer);
    // SDL_UpdateTexture(game_texture, NULL, su->pixels, su->pitch);
    // SDL_RenderCopy(game_renderer, load_image(game_renderer,"./assets/test.jpg"), NULL, NULL);
    SDL_SetRenderDrawColor(game_renderer, 0, 255, 0, 255);
    SDL_Rect rect = {200, 300, 100, 100};
    SDL_RenderDrawRect(game_renderer, &rect);
    SDL_RenderPresent(game_renderer);
    SDL_PollEvent(&sdl_event);
    if (sdl_event.type == SDL_KEYDOWN)
    {
        rect.x++;
    }
    if (sdl_event.type == SDL_KEYUP)
    {
        game_status = 0;
    }
    
    // SDL_Surface *su1 = load_imgage1("assets\\test1.png");
    // SDL_RenderClear(game_renderer);
    // SDL_UpdateTexture(game_texture, NULL, su1->pixels, su1->pitch);
    // SDL_RenderCopy(game_renderer, game_texture, NULL, NULL);
    // SDL_RenderPresent(game_renderer);
    // SDL_Delay(5000);
}

static void quit()
{

    SDL_DestroyTexture(game_texture);
    SDL_DestroyRenderer(game_renderer);
    SDL_DestroyWindow(game_window);
    //退出SDL
    SDL_Quit();
}
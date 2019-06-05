#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "config.h"

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
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, text);
    if (!texture)
    {
        SDL_Log("image load fait");
        return NULL;
    }
    return texture;
}

/**
 * 加载图片 
 **/
SDL_Surface *load_image1(const char *text)
{
    SDL_Surface *surface = NULL;
    surface = IMG_Load(text);
    if (!surface)
    {
        SDL_Log("image load fait");
        return NULL;
    }
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
    start_game();
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
    SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255);
    SDL_RenderClear(game_renderer);
    static SDL_Rect rect = {200, 300, 100, 100};
    SDL_PollEvent(&sdl_event);
    switch (sdl_event.type)
    {
    case SDL_QUIT:
        SDL_Log("game squit");
        game_status = 0;
        break;
    case SDL_KEYDOWN:
        switch (sdl_event.key.keysym.sym)
        {
        case SDLK_w:
            SDL_Log("rect.y:%d",rect.y);
            rect.y = rect.y - 10;
            break;
        case SDLK_s:
            rect.y = rect.y + 10;
            break;
        case SDLK_a:
            rect.x = rect.x - 10;
            break;
        case SDLK_d:
            rect.x = rect.x + 10;
            break;
        }
        break;
    }
    SDL_SetRenderDrawColor(game_renderer, 0, 0, 255, 255);
    SDL_RenderDrawRect(game_renderer, &rect);
    SDL_RenderPresent(game_renderer);
}

static void quit()
{
    SDL_DestroyTexture(game_texture);
    SDL_DestroyRenderer(game_renderer);
    SDL_DestroyWindow(game_window);
    //退出SDL
    SDL_Quit();
}
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

/**
 * 加载图片
 **/
SDL_Texture *load_imgage(SDL_Renderer *renderer, const char *text)
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

SDL_Surface *load_imgage1(const char *text)
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
    SDL_Surface *su = load_imgage1("assets\\test.bmp");
    SDL_RenderClear(game_renderer);
    SDL_UpdateTexture(game_texture, NULL, su->pixels, su->pitch);
    SDL_RenderCopy(game_renderer, game_texture, NULL, NULL);
    SDL_RenderPresent(game_renderer);
    SDL_Delay(5000);

    SDL_Surface *su1 = load_imgage1("assets\\test1.bmp");
    SDL_RenderClear(game_renderer);
    SDL_UpdateTexture(game_texture, NULL, su1->pixels, su1->pitch);
    SDL_RenderCopy(game_renderer, game_texture, NULL, NULL);
    SDL_RenderPresent(game_renderer);
    SDL_Delay(5000);
}

static void quit()
{

    SDL_DestroyTexture(game_texture);
    SDL_DestroyRenderer(game_renderer);
    SDL_DestroyWindow(game_window);
    //退出SDL
    SDL_Quit();
}
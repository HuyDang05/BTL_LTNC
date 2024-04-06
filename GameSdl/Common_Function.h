
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

const int WIDTH_BACKGROUND = 4800;
const int HEIGHT_BACKGROUND = 600;
const int SCREEN_WIDTH = 1360;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;



static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;


namespace SDLCommonFunc{
    SDL_Surface* LoadImage(std:: string file_path);
    void ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y);
    void ApplySurfaceVid(SDL_Surface* scr, SDL_Surface* des, SDL_Rect* clip_, int x, int y);
    void Cleanup();
    bool IsCollision(const SDL_Rect& object_a, const SDL_Rect& object_b);
}


#endif
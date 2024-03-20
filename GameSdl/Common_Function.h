
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 1360;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;


namespace SDLCommonFunc{
    SDL_Surface* LoadImage(std:: string file_path);
    void ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y);
    void Cleanup();
}


#endif
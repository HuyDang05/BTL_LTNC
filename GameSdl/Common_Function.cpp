#include "Common_Function.h"
#include "stdafx.h"


SDL_Surface* SDLCommonFunc::LoadImage(std:: string file_path){
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;
    load_image = IMG_Load(file_path.c_str());
    if(load_image != NULL){
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);

        if(optimize_image != NULL){
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);
            SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
        }
    }
    return optimize_image;
}

void SDLCommonFunc::ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(scr, NULL, des, &offset);
}

void SDLCommonFunc::Cleanup(){
    SDL_FreeSurface(g_screen);
    SDL_FreeSurface(g_bkground);
}
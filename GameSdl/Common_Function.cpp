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

void SDLCommonFunc::ApplySurfaceVid(SDL_Surface* scr, SDL_Surface* des, SDL_Rect* clip, int x, int y){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(scr, clip, des, &offset);


}


void SDLCommonFunc::Cleanup(){
    SDL_FreeSurface(g_screen);
    SDL_FreeSurface(g_bkground);
}

bool SDLCommonFunc::IsCollision(const SDL_Rect& object_a, const SDL_Rect& object_b){
    int left_a = object_a.x;
  int right_a = object_a.x + object_a.w;
  int top_a = object_a.y;
  int bottom_a = object_a.y + object_a.h;
 
  int left_b = object_b.x;
  int right_b = object_b.x + object_b.w;
  int top_b = object_b.y;
  int bottom_b = object_b.y + object_b.h;
 
  // Case 1: size object 1 < size object 2
  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }
 
  if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }
 
  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }
 
  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }
  
  // Case 2: size object 1 < size object 2
  if (left_b > left_a && left_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }
 
  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
 
  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }
 
  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
 
   // Case 3: size object 1 = size object 2
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }
 
  return false;
}
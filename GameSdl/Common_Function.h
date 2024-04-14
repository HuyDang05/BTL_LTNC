
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


//SCREEN
const int WIDTH_BACKGROUND = 4800;
const int HEIGHT_BACKGROUND = 600;
const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int SPEED_SCREEN = 1;

//Main
const int POS_X_START_MAIN_OBJ  = 100;
const int POS_Y_START_MAIN_OBJ  = 200;
const int SPEED_MAIN_OBJECT     = 10;
const int SPEED_BULLET_MAIN     = 20;

//Threat
const int THREAT = 1;
const int SPEED_THREAT = 3;
const int SPEED_BULLET_THREAT = 10;
const int UNDER_BOUND = 200;
const int VAL_OFFSET_START_POST_THREATS = 800;

const int BOSS = 3;

const int SPEED_BULLET_BOSS = 15;



static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_img_menu = NULL;
static SDL_Surface* g_img_instruct = NULL;
static SDL_Event g_even;


static Mix_Chunk* g_sound_bullet[2];
static Mix_Chunk* g_sound_exp[2];
static Mix_Chunk* g_sound_bgr[1];
static Mix_Chunk* g_sound_gold[1];
static Mix_Chunk* g_sound_choose[1];



namespace SDLCommonFunc{
    SDL_Surface* LoadImage(std:: string file_path);
    SDL_Rect ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y);
    void ApplySurfaceVid(SDL_Surface* scr, SDL_Surface* des, SDL_Rect* clip_, int x, int y);
    void Cleanup();
    bool IsCollision(const SDL_Rect& object_a, const SDL_Rect& object_b);
    int  MakeMenu(SDL_Surface* des, TTF_Font* font);
    int  MakeMenu2(SDL_Surface* des, TTF_Font* font);
    int  MakeMenu3(SDL_Surface* des, TTF_Font* font, int score_val, int gold_num);
    bool IsEnter(const int& x, const int& y, const SDL_Rect& rect);
}


#endif
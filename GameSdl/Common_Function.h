
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
const int SPEED_SCREEN = 3;

//Main
const int POS_X_START_MAIN_OBJ  = 100;
const int POS_Y_START_MAIN_OBJ  = 200;
const int SPEED_MAIN_OBJECT     = 10;
const int SPEED_BULLET_MAIN     = 20;

//Threat
const int THREAT = 4;
const int SPEED_THREAT = 6;
const int SPEED_BULLET_THREAT = 15;
const int UNDER_BOUND = 200;
const int VAL_OFFSET_START_POST_THREATS = 800;

//BOSS
const int HEALTH_BOSS = 25;
const int BOSS = 3;
const int SPEED_BULLET_BOSS = 18;
const int SPEED_BOSS = 8;
const int NUM_BOSS_TO_WIN = 5;

//EXTRA CONDITION
const int TIME_TO_WIN = 100;
const int SCORE_TO_WIN = 10;
const int EX_NUM_BOSS = 3;


//GLOBAL VARIABLE
static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Surface* g_img_menu = NULL;
static SDL_Surface* g_img_instruct = NULL;
static SDL_Event g_even;

//SOUND
static Mix_Chunk* g_sound_bullet[2];
static Mix_Chunk* g_sound_exp[2];
static Mix_Chunk* g_sound_bgr[1];
static Mix_Chunk* g_sound_gold[1];
static Mix_Chunk* g_sound_choose[1];



namespace SDLCommonFunc{
    SDL_Surface* LoadImg(std:: string file_path);
    SDL_Rect ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y);
    void ApplySurfaceVid(SDL_Surface* scr, SDL_Surface* des, SDL_Rect* clip_, int x, int y);
    void Cleanup();
    bool IsCollision(const SDL_Rect& object_a, const SDL_Rect& object_b);
    int  MakeMenu(SDL_Surface* des, TTF_Font* font);
    int  MakeMenu2(SDL_Surface* des, TTF_Font* font);
    int  MakeMenu3(SDL_Surface* des, TTF_Font* font, int score_val, int gold_num);
    int  MakeMenu4(SDL_Surface* des, TTF_Font* font, int score_val, int gold_num);
    bool IsEnter(const int& x, const int& y, const SDL_Rect& rect);

    int GetRandInSpace(int s1, int s2);
}


#endif
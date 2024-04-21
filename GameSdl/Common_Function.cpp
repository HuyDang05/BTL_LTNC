#include "Common_Function.h"
#include "stdafx.h"
#include "TextObject.h"
#include <string>

 bool SDLCommonFunc::IsEnter(const int& x, const int& y, const SDL_Rect& rect){
      if(x >= rect.x && x < rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) return true;
      return false;
  }

int SDLCommonFunc::MakeMenu(SDL_Surface* des, TTF_Font* font){
    g_sound_choose[0] = Mix_LoadWAV("choose.wav");
    g_img_menu = LoadImg("kgime.png");
    if(g_img_menu == NULL){
        return 0;
    }

    const int item_num = 3;
    SDL_Rect pos_arr[item_num];

    pos_arr[0].x = 200;
    pos_arr[0].y = 400;

    pos_arr[1].x = 200;
    pos_arr[1].y = 450;
  
    pos_arr[2].x = 200;
    pos_arr[2].y = 500;

    
    TextObject text_menu[item_num];

    text_menu[0].SetText("Play Game");
    text_menu[0].SetColor(TextObject::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("Exit Game");
    text_menu[1].SetColor(TextObject::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    text_menu[2].SetText("Guide");
    text_menu[2].SetColor(TextObject::BLACK_TEXT);
    text_menu[2].SetRect(pos_arr[2].x, pos_arr[2].y);

    bool choose[item_num] = {0, 0, 0};
    int x_mouse = 0;
    int y_mouse  = 0;

    SDL_Event m_event;
    while (true)
    {
        SDLCommonFunc::ApplySurface(g_img_menu, des, 0, 0);
        for(int i = 0; i < item_num; i++){
            text_menu[i].MakeText(font, des);
    }
        while (SDL_PollEvent(&m_event))
        {
            switch(m_event.type){
            case SDL_QUIT:
                {
                    Mix_PlayChannel(-1, g_sound_choose[0], 0);
                    return 1;}
            case SDL_MOUSEMOTION:
                {
                    x_mouse = m_event.motion.x;
                    y_mouse = m_event.motion.y;

                    for(int i = 0; i < item_num; i++){
                        if(IsEnter(x_mouse, y_mouse, text_menu[i].GetRect())){
                            if(choose[i] == false){
                                choose[i] = 1;
                                text_menu[i].SetColor(TextObject::RED_TEXT);
                            }


                        }
                        else{
                            if(choose[i] == true){
                                choose[i] = 0;
                                text_menu[i].SetColor(TextObject::BLACK_TEXT);
                            }



                        }


                    }

                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                {   Mix_PlayChannel(-1, g_sound_choose[0], 0);
                    x_mouse = m_event.button.x;
                    y_mouse = m_event.button.y;
                     for(int i = 0; i < item_num; i++){
                    if(IsEnter(x_mouse, y_mouse, text_menu[i].GetRect())){
                            return i;


                        }
                }
                }
                break;
            case SDL_KEYDOWN:
                if(m_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 1;}

            default:
                break;



            }
        }

         SDL_Flip(des);
    }


   
    return 1;
}


SDL_Surface* SDLCommonFunc::LoadImg(std:: string file_path){
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

SDL_Rect SDLCommonFunc::ApplySurface(SDL_Surface* scr, SDL_Surface* des, int x, int y){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(scr, NULL, des, &offset);

    return offset;
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


int SDLCommonFunc::MakeMenu2(SDL_Surface* des, TTF_Font* font){
    g_img_menu = LoadImg("instr.png");
    if(g_img_menu == NULL){
        return 0;
    }
     TTF_Font* font_ins =  TTF_OpenFont("game.ttf", 40);
     

    TextObject instruction;
    instruction.SetColor(TextObject::BLACK_TEXT);
    std::string str_val("INSTRUCTION");
    instruction.SetText(str_val);
    instruction.SetRect(500, 50);


    const int item_num = 2;
    SDL_Rect pos_arr[item_num];

    pos_arr[0].x = 100;
    pos_arr[0].y = 500;

    pos_arr[1].x = 1000;
    pos_arr[1].y = 500;
    
    TextObject text_menu[item_num];

    text_menu[0].SetText("Back");
    text_menu[0].SetColor(TextObject::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("Continue");
    text_menu[1].SetColor(TextObject::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool choose[item_num] = {0,0};
    int x_mouse = 0;
    int y_mouse  = 0;

    SDL_Event m_event;
    while (true)
    {
        SDLCommonFunc::ApplySurface(g_img_menu, des, 0, 0);
        instruction.MakeText(font_ins, des);
        

        for(int i = 0; i < item_num; i++){
            text_menu[i].MakeText(font, des);
    }
        while (SDL_PollEvent(&m_event))
        {
            switch(m_event.type){
            case SDL_QUIT:{
                Mix_PlayChannel(-1, g_sound_choose[0], 0);
                return 1;}
            case SDL_MOUSEMOTION:
                {
                    x_mouse = m_event.motion.x;
                    y_mouse = m_event.motion.y;

                    for(int i = 0; i < item_num; i++){
                        if(IsEnter(x_mouse, y_mouse, text_menu[i].GetRect())){
                            if(choose[i] == false){
                                choose[i] = 1;
                                text_menu[i].SetColor(TextObject::RED_TEXT);
                            }


                        }
                        else{
                            if(choose[i] == true){
                                choose[i] = 0;
                                text_menu[i].SetColor(TextObject::BLACK_TEXT);
                            }



                        }


                    }

                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                {    Mix_PlayChannel(-1, g_sound_choose[0], 0);
                    x_mouse = m_event.button.x;
                    y_mouse = m_event.button.y;
                     for(int i = 0; i < item_num; i++){
                    if(IsEnter(x_mouse, y_mouse, text_menu[i].GetRect())){
                            return i;


                        }
                }
                }
                break;
            case SDL_KEYDOWN:
                if(m_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 1;}

            default:
                break;



            }
        }

         SDL_Flip(des);
    }


   
    return 1;
}


int SDLCommonFunc::MakeMenu3(SDL_Surface* des, TTF_Font* font, int score_val, int gold_num){
    g_img_menu = LoadImg("demo.png");
    if(g_img_menu == NULL){
        return 0;
    }
     TTF_Font* font_ins =  TTF_OpenFont("game.ttf", 40);
     

    TextObject result;
    result.SetColor(TextObject::BLACK_TEXT);
    std::string str_val("YOU LOSE !");
    result.SetText(str_val);
    result.SetRect(500, 50);

      //Show score 
        TextObject mark;
        std::string val_str_mark = std::to_string(score_val);
        std::string strMark("SCORE : ");
        strMark += val_str_mark;
        mark.SetText(strMark);
        mark.SetRect(500, 200);
     
     //Show gold
        TextObject gold;
        std::string val_str_gold = std::to_string(gold_num);
        std::string strGold("GOLD : ");
        strGold += val_str_gold;

        gold.SetText(strGold);
        
        gold.SetRect(500, 300);

        

    const int item_num = 2;
    SDL_Rect pos_arr[item_num];

    pos_arr[0].x = 100;
    pos_arr[0].y = 500;

    pos_arr[1].x = 850;
    pos_arr[1].y = 500;
    
    TextObject text_menu[item_num];

    text_menu[0].SetText("QUIT");
    text_menu[0].SetColor(TextObject::BLACK_TEXT);
    text_menu[0].SetRect(pos_arr[0].x, pos_arr[0].y);

    text_menu[1].SetText("PLAY AGAIN");
    text_menu[1].SetColor(TextObject::BLACK_TEXT);
    text_menu[1].SetRect(pos_arr[1].x, pos_arr[1].y);

    bool choose[item_num] = {0,0};
    int x_mouse = 0;
    int y_mouse  = 0;

    SDL_Event m_event;
    while (true)
    {
        SDLCommonFunc::ApplySurface(g_img_menu, des, 0, 0);
        result.MakeText(font_ins, des);
        mark.MakeText(font_ins, des);
        gold.MakeText(font_ins, des);

        for(int i = 0; i < item_num; i++){
            text_menu[i].MakeText(font, des);
    }
        while (SDL_PollEvent(&m_event))
        {
            switch(m_event.type){
            case SDL_QUIT:{
                Mix_PlayChannel(-1, g_sound_choose[0], 0);
                return 1;}
            case SDL_MOUSEMOTION:
                {
                    x_mouse = m_event.motion.x;
                    y_mouse = m_event.motion.y;

                    for(int i = 0; i < item_num; i++){
                        if(IsEnter(x_mouse, y_mouse, text_menu[i].GetRect())){
                            if(choose[i] == false){
                                choose[i] = 1;
                                text_menu[i].SetColor(TextObject::RED_TEXT);
                            }


                        }
                        else{
                            if(choose[i] == true){
                                choose[i] = 0;
                                text_menu[i].SetColor(TextObject::BLACK_TEXT);
                            }



                        }


                    }

                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                {    Mix_PlayChannel(-1, g_sound_choose[0], 0);
                    x_mouse = m_event.button.x;
                    y_mouse = m_event.button.y;
                     for(int i = 0; i < item_num; i++){
                    if(IsEnter(x_mouse, y_mouse, text_menu[i].GetRect())){
                            return i;


                        }
                }
                }
                break;
            case SDL_KEYDOWN:
                if(m_event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 1;}

            default:
                break;



            }
        }

         SDL_Flip(des);
    }


   
    return 1;
}

int SDLCommonFunc::GetRandInSpace(int s1, int s2)
{
    int ret = s1 + ( std::rand() % ( s2 - s1 + 1 ) );
    return ret;
}
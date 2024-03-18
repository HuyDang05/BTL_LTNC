// GameSdl.cpp : Defines the entry point for the console application.
//
#include "Common_Function.h"
#include "stdafx.h"
#include "MainObject.h"



bool Init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        return false;
    }

    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(g_screen == NULL) return false;
    return true;
}



int main(int arc, char* argv[]){
    bool is_quit = false;
    
    if(Init() == false){
        return 0;
    }


    g_bkground = SDLCommonFunc::LoadImage("bkgn.png");
    if(g_bkground == NULL){
        return 0;
    }

    

    MainObject human_object;
    human_object.SetRect(100,200);
    bool ret = human_object.LoadImg("plane.png");
    if(!ret){
        return 0;
    }

    

    while(!is_quit){
        while(SDL_PollEvent(&g_even)){
            if(g_even.type == SDL_QUIT){
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_even);
        }
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
        human_object.Show(g_screen);
        human_object.HandleMove();

        for(int i = 0; i < human_object.GetBulletList().size(); i++){
            std::vector<BulletObject*> bullet_list  = human_object.GetBulletList();
            BulletObject* p_bullet = bullet_list.at(i);
            if(p_bullet != NULL){
                if(p_bullet->get_is_move()){
                    p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                    p_bullet->Show(g_screen);
                    
                }
                else{
                    if(p_bullet != NULL){
                        bullet_list.erase(bullet_list.begin()+i);
                        human_object.SetBulletList(bullet_list);
                        
                        delete p_bullet;
                        p_bullet = NULL;
                    }
                }
            }
          }
        if(SDL_Flip(g_screen) == -1) return 0;
    }
    SDLCommonFunc::Cleanup();
    SDL_Quit();

    return 0;

}
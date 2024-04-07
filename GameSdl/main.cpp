// GameSdl.cpp : Defines the entry point for the console application.
//
#include "Common_Function.h"
#include "stdafx.h"
#include "MainObject.h"
#include "ThreatObject.h"
#include "ExplosionObject.h"



bool Init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        return false;
    }

    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if(g_screen == NULL) return false;

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) return false;

    //Load file wav audio
    g_sound_bullet[0] = Mix_LoadWAV("laser.wav");
    g_sound_bullet[1] = Mix_LoadWAV("gun.wav");
    g_sound_exp[0] = Mix_LoadWAV("explosion.wav");
    g_sound_exp[1] = Mix_LoadWAV("main_explosion.wav");
    
    if(g_sound_bullet[0] == NULL || g_sound_bullet[1] == NULL || g_sound_exp[0] == NULL ||  g_sound_exp[1] == NULL ) return false;
    return true;
}



int main(int arc, char* argv[]){
    bool is_move_screen = true;
    double bkgn_x = 0;
    bool is_quit = false;
    
    if(Init() == false){
        return 0;
    }


    g_bkground = SDLCommonFunc::LoadImage("bk.png");
    if(g_bkground == NULL){
        return 0;
    }

    
    //make Mainobject
    MainObject human_object;
    human_object.SetRect(100,200);
    bool ret = human_object.LoadImg("ob6.png");
    if(!ret){
        return 0;
    }

    //make explosion mainobject
    ExplosionObject exp_main;
    ret = exp_main.LoadImg("expmain.png");
    exp_main.set_clip();
    if(ret == false) return 0;

    //make explosion threatobject
    ExplosionObject exp_threats;
    ret = exp_threats.LoadImg("expmain.png");
    exp_threats.set_clip();
    if(ret == false) return 0;


    //make Threatobject
    ThreatObject* p_threats = new ThreatObject[THREAT];
    for(int i = 0; i < THREAT; i++){
        ThreatObject* p_threat = (p_threats + i);
        if(p_threat){
    bool res = p_threat->LoadImg("ob3.png");
    if(res == false) return 0;

    

    int rand_y = rand()%500;
    if(rand_y > SCREEN_HEIGHT){
         rand_y = SCREEN_HEIGHT*0.25;
    }
    
    p_threat->SetRect(SCREEN_WIDTH + i*800, rand_y-125);
 
    p_threat->set_x_val(5);

    BulletObject * p_bullet = new BulletObject();

       p_threat->InitBullet(p_bullet);

       


        }}



    

    while(!is_quit){
        while(SDL_PollEvent(&g_even)){
            if(g_even.type == SDL_QUIT){
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_even, g_sound_bullet);
        } 
        //Apply background
        //SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
        
        if(is_move_screen == true){
        bkgn_x -= 0.75;
        if(bkgn_x <= -(WIDTH_BACKGROUND - SCREEN_WIDTH)){
            is_move_screen = false;
        }
        else{
        SDLCommonFunc::ApplySurface(g_bkground,g_screen,bkgn_x, 0);
        }
        }
        else{
            SDLCommonFunc::ApplySurface(g_bkground,g_screen,bkgn_x, 0);
        }




        //Implement main
        human_object.HandleMove();
        human_object.Show(g_screen);
        human_object.MakeBullet(g_screen);


        

        // Implement threat object
        for(int i = 0; i < THREAT; i++){
            ThreatObject* p_threat = (p_threats + i);
            if(p_threat){
            p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
            p_threat->Show(g_screen);
            p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);

            //Check collision threats bullet with main object
            bool is_col1 = false;
            std::vector<BulletObject*> bullet_arr = p_threat->GetBulletList();
            for(int b = 0; b < bullet_arr.size(); b++){
                BulletObject* p_bullet = bullet_arr.at(b);
                if(p_bullet){
                    is_col1 = SDLCommonFunc::IsCollision(p_bullet->GetRect(),human_object.GetRect());
                    if(is_col1 == true){
                        p_threat->ResetBullet(p_bullet);
                        break;
                    }
                }
            }
             


           

            //Check collision thr and main
            bool is_col = SDLCommonFunc::IsCollision(human_object.GetRect(), p_threat->GetRect());
            if(is_col || is_col1){
                for(int ex = 0; ex < 4; ex++){
                    int x_pos = (human_object.GetRect().x + human_object.GetRect().w*0.5)- EX_WIDTH*0.5;
                    int y_pos = (human_object.GetRect().y + human_object.GetRect().h*0.5)- EX_HEIGHT*0.5;

                    exp_main.set_frame(ex);
                    exp_main.SetRect(x_pos, y_pos);
                    exp_main.ShowEx(g_screen);

                    SDL_Delay(100);
                    //Update screen
                   if(SDL_Flip(g_screen) == -1) return 0;
                }
                Mix_PlayChannel(-1, g_sound_exp[1], 0);
               if( MessageBox(NULL, L"YOU LOSE !", L"Notification", MB_OK) == IDOK){
                   delete [] p_threats;
                    SDLCommonFunc::Cleanup();
                    SDL_Quit();
                    return 0;
               }
            }

            std::vector<BulletObject*> bullet_list = human_object.GetBulletList();
            for(int j = 0; j < bullet_list.size(); j++){
                BulletObject* p_bullet = bullet_list.at(j);
                if(p_bullet != NULL){
                    bool res_col = SDLCommonFunc::IsCollision(p_bullet->GetRect(), p_threat->GetRect());
                    if(res_col){
                        for(int t = 0; t < 4; t++){
                            int x_pos = p_bullet->GetRect().x - EX_WIDTH*0.5;
                            int y_pos = p_bullet->GetRect().y - EX_HEIGHT*0.5;

                            exp_threats.set_frame(t);
                            exp_threats.SetRect(x_pos, y_pos);
                            exp_threats.ShowEx(g_screen);

                            //Update screen
                            if(SDL_Flip(g_screen) == -1) return 0;

                        }

                        p_threat->Renew(SCREEN_WIDTH + i*800);
                        human_object.DestroyBullet(j);
                        Mix_PlayChannel(-1, g_sound_exp[0], 0);
                    }
                }
            }
          }
        }
        
          
       



        //Update screen
        if(SDL_Flip(g_screen) == -1) return 0;
    }

    delete [] p_threats;

    SDLCommonFunc::Cleanup();
    SDL_Quit();

    return 0;

}
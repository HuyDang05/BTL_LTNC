// GameSdl.cpp : Defines the entry point for the console application.
//
#include "Common_Function.h"
#include "stdafx.h"
#include "MainObject.h"
#include "ThreatObject.h"



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


    g_bkground = SDLCommonFunc::LoadImage("bk34.png");
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
            human_object.HandleInputAction(g_even);
        }
        //Apply background
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

        //Implement main
        human_object.Show(g_screen);
        human_object.HandleMove();
        human_object.MakeBullet(g_screen);

        

        // Implement threat object
        for(int i = 0; i < THREAT; i++){
            ThreatObject* p_threat = (p_threats + i);
            if(p_threat){
            p_threat->Show(g_screen);
        p_threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
     
        p_threat->MakeBullet(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
            }}



        //Update screen
        if(SDL_Flip(g_screen) == -1) return 0;
    }

    delete [] p_threats;

    SDLCommonFunc::Cleanup();
    SDL_Quit();

    return 0;

}
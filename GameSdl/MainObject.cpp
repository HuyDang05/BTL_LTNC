#include "MainObject.h"
#include "stdafx.h"

MainObject::MainObject(){
    rect_.x = 0; rect_.y = 0;
    rect_.w = WIDTH_MAIN_OBJECT;
    rect_.h = HEIGHT_MAIN_OBJECT;
    x_val_ = 0;
    y_val_ = 0;
}

MainObject::~MainObject()
{
    ;
}

void MainObject:: HandleInputAction(SDL_Event events){
    if(events.type == SDL_KEYDOWN){
        switch(events.key.keysym.sym){
        case SDLK_w:
            y_val_ -= HEIGHT_MAIN_OBJECT/5;
            break;
        case SDLK_s:
            y_val_ += HEIGHT_MAIN_OBJECT/5;
            break;
        case SDLK_a:
            x_val_ -= WIDTH_MAIN_OBJECT/5;
             break;
        case SDLK_d:
            x_val_ += WIDTH_MAIN_OBJECT/5;
            break;
            default:
                break;
        }
    }
    else if(events.type = SDL_KEYUP){
        switch (events.key.keysym.sym)
        {
        case SDLK_w: y_val_ += HEIGHT_MAIN_OBJECT/5;
            break;
        case SDLK_s:  y_val_ -= HEIGHT_MAIN_OBJECT/5;
            break;
        case SDLK_a: x_val_ += WIDTH_MAIN_OBJECT/5;
            break;
        case SDLK_d: x_val_ -= WIDTH_MAIN_OBJECT/5;
            break;

        }

    }
    else if(events.type == SDL_MOUSEBUTTONDOWN){

    }
    else if(events.type == SDL_MOUSEBUTTONUP){

    }


    
}

void MainObject:: HandleMove(){
    rect_.x += x_val_;
    if(rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH){
        rect_.x -= x_val_;
    }
    rect_.y += y_val_;
    if(rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT -200){
        rect_.y -= y_val_;
    }
}
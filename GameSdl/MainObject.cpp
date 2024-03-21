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
    BulletObject* p_bullet = new BulletObject();
    if(events.type == SDL_KEYDOWN){
      
        switch(events.key.keysym.sym){
        case SDLK_w:
            y_val_ -= HEIGHT_MAIN_OBJECT/10;
            break;
        case SDLK_s:
            y_val_ += HEIGHT_MAIN_OBJECT/10;
            break;
        case SDLK_a:
            x_val_ -= WIDTH_MAIN_OBJECT/10;
             break;
        case SDLK_d:
            x_val_ += WIDTH_MAIN_OBJECT/10;
            break;
        

        case SDLK_k:

            p_bullet->SetWidthHeight(WIDTH_LASER, HEIGHT_LASER);
            p_bullet->LoadImg("laserbl.png");
            p_bullet->set_type(BulletObject::LASER);
            p_bullet->SetRect(this->rect_.x + this-> rect_.w - 20, this->rect_.y + this->rect_.h*0.5);
            p_bullet->set_is_move(true);
            p_bullet_list_.push_back(p_bullet);
            break;
            
        case SDLK_l: 
            p_bullet->SetWidthHeight(WIDTH_DART, HEIGHT_DART);
            p_bullet->LoadImg("dartbl.png");
            p_bullet->set_type(BulletObject::DART);
            p_bullet->SetRect(this->rect_.x + this-> rect_.w - 20, this->rect_.y + this->rect_.h*0.5);
            p_bullet->set_is_move(true);
            p_bullet_list_.push_back(p_bullet);
            break;
            
            default:
                break;
        }
    }
    else if(events.type == SDL_KEYUP){
        switch (events.key.keysym.sym)
        {
        case SDLK_w: y_val_ += HEIGHT_MAIN_OBJECT/10;
            break;
        case SDLK_s:  y_val_ -= HEIGHT_MAIN_OBJECT/10;
            break;
        case SDLK_a: x_val_ += WIDTH_MAIN_OBJECT/10;
            break;
        case SDLK_d: x_val_ -= WIDTH_MAIN_OBJECT/10;
            break;

        }

    }
    else if(events.type == SDL_MOUSEBUTTONDOWN){
        
        if(events.button.button == SDL_BUTTON_LEFT){
            
        }
        else if(events.button.button == SDL_BUTTON_RIGHT){
            
        }

        

    }
    else if(events.type == SDL_MOUSEBUTTONUP){

    }
    else{
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
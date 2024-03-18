#include "BulletObject.h"
#include "stdafx.h"

BulletObject:: BulletObject(){
    rect_.x = 0;
    rect_.y = 0;
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
    bullet_type_ = NONE;
}


BulletObject::~BulletObject(){

    ;
}

void BulletObject::HandleMove(const int& x_border, const int& y_border){
    if(is_move_ == true){
    rect_.x += 20;
    if(rect_.x > x_border){
        is_move_ = false;
    }
    }
}

void BulletObject::HandleInputAction(SDL_Event events){

}
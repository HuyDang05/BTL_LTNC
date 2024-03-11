#include "BaseObject.h"
#include "stdafx.h"



BaseObject::BaseObject(){

    rect_.x = 0;
    rect_.y = 0;
    p_object_ = NULL;
}

BaseObject::~BaseObject(){
    
}


bool BaseObject::LoadImg(const char* file_name){
    p_object_ = SDLCommonFunc::LoadImage(file_name);
    if(p_object_ == NULL) return false;
    return true;
}

void BaseObject::Show(SDL_Surface* des){
    if (p_object_ != NULL){
        SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
    }
}


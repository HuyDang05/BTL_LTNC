#include "BaseObject.h"
#include "stdafx.h"



BaseObject::BaseObject(){

    rect_.x = 0;
    rect_.y = 0;
    p_object_ = NULL;
}

BaseObject::~BaseObject(){
    Free();
}


bool BaseObject::LoadImg(const char* file_name){

    Free();
    p_object_ = SDLCommonFunc::LoadImage(file_name);
    if(p_object_ == NULL) return false;
    return true;
}

void BaseObject::Show(SDL_Surface* des){
    if (p_object_ != NULL){
        rect_ = SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
    }
}

void BaseObject::Free()
{
    if(p_object_ != NULL)
    {
        SDL_FreeSurface(p_object_);
        p_object_ = NULL;
    }
}
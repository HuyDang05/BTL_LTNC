
#include "ExplosionObject.h"
#include "stdafx.h"

ExplosionObject::ExplosionObject(){

}

ExplosionObject::~ExplosionObject(){

}

void ExplosionObject::set_clip(){

    clip_[0].x = 0;
    clip_[0].y = 0;
    clip_[0].w = EX_WIDTH;
    clip_[0].h = EX_HEIGHT;

    clip_[1].x = EX_WIDTH;
    clip_[1].y = 0;
    clip_[1].w = EX_WIDTH;
    clip_[1].h = EX_HEIGHT;

    clip_[2].x = 2*EX_WIDTH;
    clip_[2].y = 0;
    clip_[2].w = EX_WIDTH;
    clip_[2].h = EX_HEIGHT;

    clip_[3].x = 3*EX_WIDTH;
    clip_[3].y = 0;
    clip_[3].w = EX_WIDTH;
    clip_[3].h = EX_HEIGHT;
}

void ExplosionObject::ShowEx(SDL_Surface* des){
    if(frame >= 4){
        frame = 0;
    }

    SDLCommonFunc::ApplySurfaceVid(this->p_object_,des, &clip_[frame], rect_.x, rect_.y);
}

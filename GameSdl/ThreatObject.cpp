#include "ThreatObject.h"
#include "stdafx.h"

ThreatObject::ThreatObject(){

    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT*0.5;
    rect_.w = WIDTH_THREAT;
    rect_.h = HEIGHT_THREAT;

    x_val_ = 0;
    y_val_ = 0;

}


ThreatObject::~ThreatObject(){


};

//void ThreatObject::InitBullet(BulletObject* p_bullet){
//    if(p_bullet){
//        bool res = p_bullet->LoadImg("");
//        if(res){
//            p_bullet->set_is_move(true);
//            p_bullet->SetWidthHeight(WIDTH_LASER, HEIGHT_LASER);
//            p_bullet->set_type(BulletObject::LASER);
//            p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.3);
//            p_bullet_list.push_back(p_bullet);
//        }
//    }
//}

   void ThreatObject::MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit){


void ThreatObject::HandleMove(const int& x_border, const int& y_border){
    rect_.x -= x_val_;
    if(rect_.x < 0){
        rect_.x = SCREEN_WIDTH;
        int rand_y = rand()%500;
        if(rand_y > SCREEN_HEIGHT-200){
            rand_y = SCREEN_HEIGHT*0.25;
        }
        rect_.y = rand_y;
    }


}

void ThreatObject::HandleInputAction(SDL_Event events){


}
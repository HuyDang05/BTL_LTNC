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
    if(p_bullet_list_.size() > 0){
        for(int i = 0; i < p_bullet_list_.size(); i++){
            BulletObject* p_bullet = p_bullet_list_.at(i);
            if(p_bullet != NULL){
                delete p_bullet;
                p_bullet = NULL;
            }
        }
        p_bullet_list_.clear();
    }


};

void ThreatObject::InitBullet(BulletObject* p_bullet){
    if(p_bullet){
        bool res = p_bullet->LoadImg("bl8.png");
        if(res){
            p_bullet->set_is_move(true);
            p_bullet->SetWidthHeight(WIDTH_LASER, HEIGHT_LASER);
            p_bullet->set_type(BulletObject::LASER);
            p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.3);
            p_bullet->set_x_val(SPEED_BULLET_THREAT);
            p_bullet_list_.push_back(p_bullet);
        }
    }
}

void ThreatObject::MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit){
       for(int i = 0; i < p_bullet_list_.size(); i++){

           BulletObject* p_bullet = p_bullet_list_.at(i);
           if(p_bullet){
               if(p_bullet->get_is_move()){
                   p_bullet->Show(des);
                   p_bullet->HandleThreatMove();
               }
               else{
                   p_bullet->set_is_move(true);
                   p_bullet->SetRect(rect_.x, rect_.y + rect_.h * 0.5);
               }
           }
       }




   }

 

void ThreatObject::HandleMove(const int& x_border, const int& y_border){
    rect_.x -= x_val_;
    if(rect_.x < 0){
        rect_.x = SCREEN_WIDTH;
        int rand_y = rand()%500;
        if(rand_y > SCREEN_HEIGHT-UNDER_BOUND){
            rand_y = SCREEN_HEIGHT*0.25;
        }
        rect_.y = rand_y;
    }


}

void ThreatObject::HandleInputAction(SDL_Event events){


}

void ThreatObject::Renew(const int& x_border){
    rect_.x = x_border;
        int rand_y = rand()%500;
        if(rand_y > SCREEN_HEIGHT-UNDER_BOUND){
            rand_y = SCREEN_HEIGHT*0.25;
        }
        rect_.y = rand_y;
        for(int i = 0; i < p_bullet_list_.size(); i++){
            BulletObject* p_bullet = p_bullet_list_.at(i);
            if(p_bullet){
                ResetBullet(p_bullet);
            }
        }
}

void ThreatObject::ResetBullet(BulletObject* p_bullet){
    p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.3);
}

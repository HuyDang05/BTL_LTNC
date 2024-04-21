#include "Boss.h"
#include "stdafx.h"
#include "Common_Function.h"

BossObject::BossObject(){

    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT*0.5;
    rect_.w = WIDTH_THREAT;
    rect_.h = HEIGHT_THREAT;

    x_val_ = 0;
    y_val_ = 0;
    flag_moving = 0;
    val_moving = 0;

}


BossObject::~BossObject(){
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

void BossObject::InitBullet(BulletObject* p_bullet){
    if(p_bullet){
        bool res = p_bullet->LoadImg("bl4.png");
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

void BossObject::MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit){
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

 
  
void BossObject::HandleMove(const int& x_border, const int& y_border){
    if(rect_.x > 900) // boss se lui dan tu vi tri ban dau ve 1200
    {
        // bat dau -x_value khi boss o vi tri > 1200
        rect_.x -= x_val_;
    }
    else
    {
        // khi boss bat dau ve den vi tri 1200
        // kiem tra co di chuyen
        if (flag_moving == 0) // neu co bang 0, thi di chuyen xuong duoi
        {
            // moi lan di chuyen thi + gia tri di chuyen vao bien val_moving
            val_moving += y_val_;
            if (val_moving > 400) // khi tong gia tri di chuyen > 300
            {
                val_moving = 0;  // dua gia tri = 0
                flag_moving = 1; // dao co di chuyen
            }
            else
            {
                // neu tong gia tri chua vuot 300, thi cho phep di chuyen 
                 rect_.y += y_val_;
                 if (rect_.y > SCREEN_HEIGHT - UNDER_BOUND)
                 {
                        val_moving = 0;
                        flag_moving = 1;
                 }
            }
        }
        else
        {
            // khi co flag == 1, thi cung tuong tu tinh tong luong di chuyen nguoc lai
             val_moving += y_val_;
             if (val_moving > 400)
             {
                val_moving = 0;
                flag_moving = 0;
              }
              else
              {
                   rect_.y -= y_val_;
                   if (rect_.y < 0)
                   {
                        val_moving = 0;
                        flag_moving = 0;
                   }
              }
        }
    }
}

void BossObject::HandleInputAction(SDL_Event events){


}

void BossObject::Renew(const int& x_border){
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

void BossObject::ResetBullet(BulletObject* p_bullet){
    p_bullet->SetRect(rect_.x, rect_.y + rect_.h*0.3);
}


#include "stdafx.h"
#include "SupportItem.h"
#include <time.h>

SupportItem::SupportItem()
{
    /*rect_.x = 0;
    rect_.y = 0;
    rect_.w = GOLD_WIDTH; 
    rect_.h = GOLD_HEIGHT;
    x_val_ = 0;
    y_val_ = 0;*/
}

SupportItem::~SupportItem()
{

}

void SupportItem::AddPos(const int& xpos, const int& ypos){
    pos_list_.push_back(std::make_pair(xpos, ypos));
}


void SupportItem::Render(SDL_Surface* des){
    if(number_ == pos_list_.size()){
        for(int i = 0; i < pos_list_.size(); i++){
            rect_.x = pos_list_.at(i).first;
            rect_.y = pos_list_.at(i).second;
            Show(des);
        }
    }
}

void SupportItem::Init(){
    LoadImg("gold.png");
    number_ = 4;
    if(pos_list_.size() > 0){
        pos_list_.clear();
    }


    AddPos(40,80);
    AddPos(80,80);
    AddPos(120,80);
    AddPos(150,80);
}




//void SupportItem::Show(SDL_Surface* des)
//{
//    
//    SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
//}




//void SupportItem::SetRandomPos()
//{
//    srand(time(0));
//    rect_.x = rand() % (SCREEN_WIDTH - GOLD_WIDTH); 
//    rect_.y = rand() % (SCREEN_HEIGHT - GOLD_HEIGHT); 
//    
//}


void SupportItem::Decrease(){
    number_--;
    pos_list_.pop_back();
}

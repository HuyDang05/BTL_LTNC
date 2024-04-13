#include "HP.h"
#include "stdafx.h"
Health::Health(){

}
Health::~Health(){

}


void Health::AddPos(const int& xpos){
    pos_list_.push_back(xpos);
}

void Health::Render(SDL_Surface* des){
    if(number_ == pos_list_.size()){
        for(int i = 0; i < pos_list_.size(); i++){
            rect_.x = pos_list_.at(i);
            Show(des);
        }
    }
}

void Health::Init(){

    LoadImg("health.png");
    number_ = 3;
    if(pos_list_.size() > 0){
        pos_list_.clear();
    }
    AddPos(20);
    AddPos(60);
    AddPos(100);

}
void Health::Decrease(){
    number_ --;
    pos_list_.pop_back();
}

void Health::Increase(){
    if(number_ <= 7){
    number_ ++;

    pos_list_.push_back(number_ * 20);}
}


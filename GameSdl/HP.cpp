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
    
}
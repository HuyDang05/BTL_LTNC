
#include "stdafx.h"
#include "SupportItem.h"
#include <time.h>

SupportItem::SupportItem()
{
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = GOLD_WIDTH; 
    rect_.h = GOLD_HEIGHT;
    x_val_ = 0;
    y_val_ = 0;
}

SupportItem::~SupportItem()
{

}


void SupportItem::Init(){
    LoadImg("gold.png");
    number_ = 4;
}




void SupportItem::Show(SDL_Surface* des)
{
    
    SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
}




void SupportItem::SetRandomPos()
{
    srand(time(0));
    rect_.x = rand() % (SCREEN_WIDTH - GOLD_WIDTH); 
    rect_.y = rand() % (SCREEN_HEIGHT - GOLD_HEIGHT); 
    
}

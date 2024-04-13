
#include "stdafx.h"
#include "SupportItem.h"
#include <time.h>
#include "SDL.h"
#include "Common_Function.h"


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
    number_ = ITEM_NUM;
    if(pos_list_.size() > 0){
        pos_list_.clear();
    }
       srand(time(0));
   int ran =  rand() % (RIGHT_BOUND - LEFT_BOUND + 1) + LEFT_BOUND;
   int y = rand()%( SCREEN_HEIGHT - LOWER_BOUND);
 
   for (int i = 1; i <= number_; ++i) {
      
        int x = ran + 35*i;
       
        AddPos(x, y);
    }
}







void SupportItem::Decrease(){
    number_--;
    pos_list_.pop_back();

}
//bool SupportItem::CheckCollisionWithGold(MainObject& human_object) {
//   SDL_Rect main_rect = human_object.GetRect();
//    SDL_Rect gold_rect = this->GetRect();
//    // Kiểm tra va chạm giữa hai hình chữ nhật
//    if(SDLCommonFunc::IsCollision(main_rect, gold_rect)){
//       // Khởi tạo lại vị trí mới cho cục vàng
//        return true; // Trả về true để cho biết đã xử lý va chạm thành công
//    }
//    return false; // Trả về false nếu không có va chạm
//}

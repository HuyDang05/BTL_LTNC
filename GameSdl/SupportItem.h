
#ifndef SUPPORT_ITEM_H_
#define SUPPORT_ITEM_H_

#include "Common_Function.h"
#include "BaseObject.h"
#include "stdafx.h"
#include <vector>
#include <utility>


const int GOLD_WIDTH = 30;
const int GOLD_HEIGHT = 30;
const int ITEM_NUM = 4;
const int LEFT_BOUND = 100;
const int RIGHT_BOUND = SCREEN_WIDTH - 35 * ITEM_NUM;
const int LOWER_BOUND = 200;


class SupportItem : public BaseObject
{
public:
    SupportItem(){ number_ = ITEM_NUM;}
    ~SupportItem();

    
    void Init();
    void AddPos(const int& xpos, const int& ypos);
    void Render(SDL_Surface* des);
    int GetNumber() { return number_;}
  
    void Decrease();
    void Increase();
 
private:
    int x_val_;
    int y_val_;
    int number_;
    std::vector<std::pair <int, int>> pos_list_;
};

#endif

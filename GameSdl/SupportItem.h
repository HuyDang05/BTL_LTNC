
#ifndef SUPPORT_ITEM_H_
#define SUPPORT_ITEM_H_

#include "Common_Function.h"
#include "BaseObject.h"
#include "stdafx.h"
#include <vector>
#include <utility>


const int GOLD_WIDTH = 30;
const int GOLD_HEIGHT = 30;

class SupportItem : public BaseObject
{
public:
    SupportItem();
    ~SupportItem();

    void SetNumber(const int& num){ number_ = num;}
    void Init();
    void AddPos(const int& xpos, const int& ypos);
    void Render(SDL_Surface* des);
  //  void Show(SDL_Surface* des);
    void SetRandomPos(); // Ð?t t?a d? ng?u nhiên cho d?i tu?ng gold
    void Decrease();
    void Increase();

private:
    int x_val_;
    int y_val_;
    int number_;
    std::vector<std::pair <int, int>> pos_list_;
};

#endif

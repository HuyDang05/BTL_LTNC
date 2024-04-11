
#ifndef SUPPORT_ITEM_H_
#define SUPPORT_ITEM_H_

#include "Common_Function.h"
#include "BaseObject.h"
#include "stdafx.h"

const int GOLD_WIDTH = 30;
const int GOLD_HEIGHT = 30;

class SupportItem : public BaseObject
{
public:
    SupportItem();
    ~SupportItem();

    void Init();
    void Show(SDL_Surface* des);
    void SetRandomPos(); // Ð?t t?a d? ng?u nhiên cho d?i tu?ng gold
    void Increase();

private:
    int x_val_;
    int y_val_;
    int number_;
    std::vector<int> pos_list_;
};

#endif

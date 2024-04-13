#ifndef HP_H
#define HP_H
#include "BaseObject.h"
#include <vector>


class Health : public BaseObject{
public:
    Health();
    ~Health();
    void SetNumber(const int& num){ number_ = num;}
    void AddPos(const int& xpos);
    void Render(SDL_Surface* des);
    void Init();
    void Decrease();
    void Increase();
private:
    int number_;
    std::vector<int> pos_list_;
};

#endif

#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "BaseObject.h"
#include "Common_Function.h"

const int EX_WIDTH = 165;
const int EX_HEIGHT = 165;

class ExplosionObject : public BaseObject{
public:
    ExplosionObject();
    ~ExplosionObject();
    void set_clip;
    void set_frame(const int & fr) {frame = fr;}
    void ShowEx(SDL_Surface* des);

private:
    int frame;
    SDL_Rect clip_[4];
};


#endif
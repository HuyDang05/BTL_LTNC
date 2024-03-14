
#ifndef BULLET_OBJECT_H_
#define BULLET_OBJECT_H_
#include "BaseObject.h"
#include "stdafx.h"

#define WIDTH_LASER 35
#define HEIGHT_LASER 5

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10

class BulletObject : public BaseObject{
public:
    enum Bullettype
    {
        NONE = 0,
        LASER = 1,
        SPHERE = 2

    };
    BulletObject();
    ~BulletObject();
    void HandleInputAction(SDL_Event events);
    void HandleMove();

    int get_type() const {return bullet_type_;}
    void set_type(const int& type){ bullet_type_ = type;}

    bool get_is_move() const {return is_move_;}
    void set_is_move(bool is_move) {is_move_ = is_move;}
    void SetWidthHeight(const int& width, const int &height) {rect_.w = width; rect_.h = height;}


private:
    int x_val_;
    int y_val_;
    bool is_move_;
    int bullet_type_;
};
#endif
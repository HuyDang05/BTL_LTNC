
#ifndef BOSS_OBJECT_H_
#define BOSS_OBJECT_H_

#include "BaseObject.h"
#include "Common_Function.h"
#include "BulletObject.h"
#include <vector>
#include "stdafx.h"


class BossObject : public BaseObject{

    public:
    BossObject();
    ~BossObject();

    void HandleMove(const int& x_border, const int & y_border);
    void HandleInputAction(SDL_Event events);

    void set_x_val(const int& val){ x_val_ = val;}
    void set_y_val(const int& val){ y_val_ = val;}
    int get_x_val() const {return x_val_;}
    int get_y_val() const {return y_val_;}

    void SetBulletList(std:: vector<BulletObject*> bullet_list) {p_bullet_list_ = bullet_list;}
    std::vector<BulletObject*> GetBulletList() const {return p_bullet_list_;}

    void InitBullet(BulletObject* p_bullet);
    void MakeBullet(SDL_Surface* des, const int& x_limit, const int& y_limit);
    void Renew(const int& x_border);
    void ResetBullet(BulletObject* p_bullet);
private:
    int x_val_;
    int y_val_;
    int flag_moving;
    int val_moving;
     std::vector<BulletObject*> p_bullet_list_;
};






#endif
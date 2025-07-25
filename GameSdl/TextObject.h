
#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include "BaseObject.h"
#include <string>
#include <SDL_ttf.h>
#include "stdafx.h"
#include "Common_Function.h"

class TextObject : public BaseObject
{
public:
    enum TextColor{
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };
    
    TextObject();
    ~TextObject();

    void SetText(const std::string& text){ str_ = text;}
    void SetColor(const int& type);
    void MakeText(TTF_Font* font, SDL_Surface* des);

private:
    std::string str_ ;
    SDL_Color text_color;


};


#endif
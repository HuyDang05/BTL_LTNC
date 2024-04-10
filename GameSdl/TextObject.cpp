
#include "TextObject.h"
#include "stdafx.h"

TextObject::TextObject(){
    rect_.x = 30;
    rect_.y = 40;
    text_color.r = 0;
    text_color.r = 0;
    text_color.r = 0;
}

TextObject::~TextObject(){

}

void TextObject::SetColor(const int& type){
    if(type == RED_TEXT){
        SDL_Color color = {255,0,0};
        text_color = color;
    }

    else if(type == WHITE_TEXT){
        SDL_Color color = {255, 255, 255};
        text_color = color;
    }

    else {
        SDL_Color color = {0, 0, 0};
        text_color = color;
    }

}

void TextObject::MakeText(TTF_Font* font, SDL_Surface* des){
    p_object_ = TTF_RenderText_Solid(font, str_.c_str(), text_color);
    Show(des);
}
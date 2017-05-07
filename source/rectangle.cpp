#include <iostream>
#include "rectangle.hpp"
    Rectangle::Rectangle():
        min_{{0.0f},{0.0f}},
        max_{{0.0f},{0.0f}},
        bottomright_{{0.0f},{0.0f}},
        topleft_{{0.0f},{0.0f}}
    {}
    Rectangle::Rectangle(Vec2 const& vctr1, Vec2 const& vctr2):
        min_{vctr1},
        max_{vctr2},
        bottomright_{{vctr2.x_},{vctr1.y_}},
        topleft_{{vctr1.x_},{vctr2.y_}}
    {}
    Vec2 Rectangle:: getMin_() const{return min_;}
    Vec2 Rectangle:: getMax_() const{return max_;}
    Vec2 Rectangle:: getBottomright_() const{return bottomright_;}
    Vec2 Rectangle:: getTopleft_() const{return topleft_;}
    float Rectangle:: circumfrenceR()const{
        float result=(((bottomright_.x_-min_.x_)+(max_.y_-bottomright_.y_))*2);
        return result;
    }
#include <iostream>
#include "vec2.hpp"
Vec2::Vec2():
    x_{0.0},
    y_{0.0}
{}
Vec2::Vec2(float a, float b):
    x_{a},
    y_{b}
{}
Vec2& Vec2::operator+=(Vec2 const& v){
    x_+=v.x_;
    y_+=v.y_;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v){
    x_-=v.x_;
    y_-=v.y_;
    return *this;
}

Vec2& Vec2::operator*=(float s){
    x_*=s;
    y_*=s;
    return *this;
}
Vec2& Vec2::operator/=(float s){
    if(s==0.0f){
        std::cerr<<"Diese Operation ist nicht mit 0 moeglich!"<<std::endl;
        return *this;
    }
   else{ 
    x_/=s;
    y_/=s;
    return *this;
   }
}
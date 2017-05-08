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
Vec2::Vec2(Vec2 const& v):
    x_{v.x_},
    y_{v.y_}
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
Vec2 operator+( Vec2 const & u , Vec2 const & v ){
    Vec2 tmp{u};
    tmp += v;
    return tmp;
}
Vec2 operator-( Vec2 const & u , Vec2 const & v ){
    float x=u.x_-v.x_;
    float y=u.y_-v.y_;
    Vec2 temp{x,y};
    return temp;
}
Vec2 operator*( Vec2 const & v , float s ){
    float x=v.x_*s;
    float y=v.y_*s;
    Vec2 temp{x,y};
    return temp;
}
Vec2 operator/( Vec2 const & v , float s ){
     if(s==0.0f){
        std::cerr<<"Diese Operation ist nicht mit 0 moeglich!"<<std::endl;
        return v;
    }
    else{
    Vec2 temp{{v.x_/s},{v.y_/s}};
    return temp;
   }
}
Vec2 operator*( float s , Vec2 const & v ){
    float x=v.x_*s;
    float y=v.y_*s;
    Vec2 temp{x,y};
    return temp;
}
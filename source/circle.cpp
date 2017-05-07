#include <iostream>
#include <math.h>
#include "circle.hpp"
    Circle::Circle():
        radius_{0.0f},
        center_{{0.0f},{0.0f}}
    {}
    Circle::Circle(Vec2 const& ctr, float r){
        if(r<0.0f){
        std::cerr<<"Der Kreis muss einen Radius über 0 haben!"<<std::endl;
        radius_=0.0f;
        center_={{0.0f},{0.0f}};
    }
    else{
        radius_=r;
        center_=ctr;
    }
    }
    float Circle:: getRadius() const{return radius_;}
    Vec2 Circle:: getCenter() const{return center_;}
    float Circle:: circumfrenceC()const{
        float result=2*M_PI*radius_;
        return result;
    }
#include <iostream>
#include <math.h>
#include "circle.hpp"
    Circle::Circle():
        radius_{0.0f},
        center_{{0.0f},{0.0f}},
        kreisfarbe_{{0.0f},{0.0f},{0.0f}}
    {}
    Circle::Circle(Vec2 const& ctr, float r, Color const& clr){
        if(r<0.0f){
        std::cerr<<"Der Kreis muss einen Radius über 0 haben!"<<std::endl;
        radius_=0.0f;
        center_={{0.0f},{0.0f}};
        kreisfarbe_={{0.0f},{0.0f},{0.0f}};
    }
    else{
        radius_=r;
        center_=ctr;
        kreisfarbe_=clr;
    }
    }
    float Circle:: getRadius() const{return radius_;}
    Vec2 Circle:: getCenter() const{return center_;}
    float Circle:: circumfrenceC()const{
        float result=2*M_PI*radius_;
        return result;
    }
    Color Circle:: getColorC() const{return kreisfarbe_;}
    void Circle:: draw(Window const& canvas) const{
        canvas.draw_point(getCenter().x_,getCenter().y_,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_-radius_ /2,center_.y_-radius_,center_.x_+radius_ /2,center_.y_-radius_,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_+radius_ /2,center_.y_-radius_,center_.x_+radius_,center_.y_-radius_ /2,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_+radius_,center_.y_-radius_ /2,center_.x_+radius_,center_.y_+radius_ /2,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_+radius_,center_.y_+radius_ /2,center_.x_+radius_ /2,center_.y_+radius_,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_+radius_ /2,center_.y_+radius_,center_.x_-radius_ /2,center_.y_+radius_,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_-radius_ /2,center_.y_+radius_,center_.x_-radius_,center_.y_+radius_ /2,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_-radius_,center_.y_+radius_ /2,center_.x_-radius_,center_.y_-radius_ /2,0.0f,0.0f,0.0f);
        canvas.draw_line(center_.x_-radius_,center_.y_-radius_ /2,center_.x_-radius_ /2,center_.y_-radius_,0.0f,0.0f,0.0f);
    }
    void Circle:: draw(Window const& canvas, Color const& clr) const{
        canvas.draw_point(getCenter().x_,getCenter().y_,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_-radius_ /2,center_.y_-radius_,center_.x_+radius_ /2,center_.y_-radius_,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_+radius_ /2,center_.y_-radius_,center_.x_+radius_,center_.y_-radius_ /2,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_+radius_,center_.y_-radius_ /2,center_.x_+radius_,center_.y_+radius_ /2,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_+radius_,center_.y_+radius_ /2,center_.x_+radius_ /2,center_.y_+radius_,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_+radius_ /2,center_.y_+radius_,center_.x_-radius_ /2,center_.y_+radius_,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_-radius_ /2,center_.y_+radius_,center_.x_-radius_,center_.y_+radius_ /2,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_-radius_,center_.y_+radius_ /2,center_.x_-radius_,center_.y_-radius_ /2,clr.r,clr.g,clr.b);
        canvas.draw_line(center_.x_-radius_,center_.y_-radius_ /2,center_.x_-radius_ /2,center_.y_-radius_,clr.r,clr.g,clr.b);
    }
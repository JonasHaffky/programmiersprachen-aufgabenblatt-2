#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
class Rectangle{
    public:
        Rectangle();
        Rectangle(Vec2 const& vctr1, Vec2 const& vctr2,Color const& clr);
        Vec2 getMin_() const;
        Vec2 getMax_() const;
        Vec2 getBottomright_() const;
        Vec2 getTopleft_() const;
        float circumfrenceR()const;
        Color getColorR() const;
        void draw(Window const& canvas) const;
        void draw(Window const& canvas, Color const& clr) const;
    private:
        Vec2 min_;
        Vec2 max_;
        Vec2 bottomright_;
        Vec2 topleft_;
        Color rechteckfarbe_;
};
#endif //Rectangle_HPP
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
class Circle{
    public:
        Circle();
        Circle(Vec2 const& ctr, float r,Color const& clr);
        float getRadius() const;
        Vec2 getCenter() const;
        float circumfrenceC()const;
        Color getColorC() const;
        void draw(Window const& canvas) const;
        void draw(Window const& canvas, Color const& clr) const;
    private:
        float radius_;
        Vec2 center_;
        Color kreisfarbe_;
};
#endif //CIRCLE_HPP
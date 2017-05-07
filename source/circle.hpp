#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
class Circle{
    public:
        Circle();
        Circle(Vec2 const& ctr, float r);
        float getRadius() const;
        Vec2 getCenter() const;
    private:
        float radius_;
        Vec2 center_;
};
#endif //CIRCLE_HPP
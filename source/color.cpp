#include <iostream>
#include "color.hpp"
Color::Color():
    r{0.0f},
    g{0.0f},
    b{0.0f}
{}
Color::Color(float a):
    r{a},
    g{a},
    b{a}
{}

Color::Color(float red, float green, float blue){
    if(red<0||red>1||green<0||green>1||blue<0||blue>1){
        std::cerr<<"Die Farbintensitaet muss zwischen 0 und 1 liegen!"<<std::endl;
        r=0.0f;
        g=0.0f;
        b=0.0f;
    }
    else{
        r=red;
        g=green;
        b=blue;
    }
}
#include <iostream>
#include "mat2.hpp"
Mat2::Mat2():
    x1{1.0f},
    x2{0.0f},
    y1{0.0f},
    y2{1.0f}
{}
Mat2::Mat2(float a, float b, float c, float d):
    x1{a},
    x2{b},
    y1{c},
    y2{d}
{}
Mat2& Mat2::operator*=( Mat2 const & m ){
    float x1temp=x1;
    float y1temp=y1;
    x1*= m.x1;
    x1+= x2*m.y1;
    x2*= m.y2;
    x2+= x1temp*m.x2;
    y1*= m.x1;
    y1+= y2*m.y1;
    y2*= m.y2;
    y2+= y1temp*m.x2; 
    return *this;
}
Mat2 operator*( Mat2 const & m1 , Mat2 const & m2 ){
    float atemp, btemp, ctemp, dtemp;
    atemp = m1.x1*m2.x1+m1.x2*m2.y1;
    btemp = m1.x1*m2.x2+m1.x2*m2.y2;
    ctemp = m1.y1*m2.x1+m1.y2*m2.y1;
    dtemp = m1.y1*m2.x2+m1.y2*m2.y2;
    Mat2 mattemp{atemp, btemp, ctemp, dtemp};
    return mattemp;
}
float Mat2::det() const{
    float result=x1*y2-y1*x2;
    return result;
}
Vec2 operator*( Mat2 const& m , Vec2 const & v ){
    float xtemp=m.x1*v.x_+m.x2*v.y_;
    float ytemp=m.y1*v.x_+m.y2*v.y_;
    Vec2 tempvec{xtemp,ytemp};
    return tempvec;
}
Vec2 operator*( Vec2 const& v , Mat2 const& m ){
    std::cerr<<"Da die Spaltenzahl des Vektors und die Zeilenzahl der Matrix nicht gleich sind, kann diese Operation nicht ausgeführt werden."<<std::endl;
    return v;
}
Mat2 inverse ( Mat2 const& m ){
    float dettemp=m.det();
    float x1temp=m.y2/dettemp;
    float y2temp=m.x1/dettemp;
    float x2temp=-m.y1/dettemp;
    float y1temp=-m.x2/dettemp;
    Mat2 inverseMatrix{x1temp,x2temp,y1temp,y2temp};
    return inverseMatrix;
}
Mat2 transpose ( Mat2 const& m ){
    float x2temp = m.y1;
    float y1temp = m.x2;
    Mat2 transponierteMatrix{m.x1,x2temp,y1temp,m.y2};
    return transponierteMatrix;
}
//Mat2 make_rotation_mat2 ( float phi ){

//}
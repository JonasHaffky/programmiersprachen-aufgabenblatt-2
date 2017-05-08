#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE("describe_vec2","[vec2]")
{ Vec2 a{};
  Vec2 b{{4.2f},{2.1f}};
  REQUIRE(a.x_==0.0f);
  REQUIRE(a.y_==0.0f);
  REQUIRE(b.x_==4.2f);
  REQUIRE(b.y_==2.1f);
}
TEST_CASE("describe_operator+=","[operator+=]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{4.0f},{0.0f}};
  Vec2 c{{6.8f},{0.5f}};
  Vec2 d{{0.7f},{4.8f}};
  a.operator+=(b);
  b.operator+=(c);
  c.operator+=(d);
  REQUIRE(a.x_==9.0f);
  REQUIRE(a.y_==2.0f);
  REQUIRE(b.x_==10.8f);
  REQUIRE(b.y_==0.5f);
  REQUIRE(c.x_==7.5f);
  REQUIRE(c.y_==5.3f);
}

TEST_CASE("describe_operator-=","[operator-=]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{3.0f},{0.0f}};
  Vec2 c{{6.8f},{0.5f}};
  Vec2 d{{0.7f},{4.8f}};
  a.operator-=(b);
  b.operator-=(d);
  c.operator-=(c);
  REQUIRE(a.x_==2.0f);
  REQUIRE(a.y_==2.0f);
  REQUIRE(b.x_==2.3f);
  REQUIRE(b.y_==-4.8f);
  REQUIRE(c.x_==0.0f);
  REQUIRE(c.y_==0.0f);
}
TEST_CASE("describe_operator*=","[operator*=]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{3.0f},{0.0f}};
  Vec2 c{{6.8f},{0.5f}};
  float x=2.5f;
  float y=0.7f;
  a.operator*=(x);
  b.operator*=(x);
  c.operator*=(y);
  REQUIRE(a.x_==12.5f);
  REQUIRE(a.y_==5.0f);
  REQUIRE(b.x_==7.5f);
  REQUIRE(b.y_==0.0f);
  REQUIRE(c.x_==4.76f);
  REQUIRE(c.y_==0.35f);
}
TEST_CASE("describe_operator/=","[operator/=]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{3.0f},{0.0f}};
  Vec2 c{{6.8f},{0.5f}};
  float x=2.5f;
  float y=0.0f;
  a.operator/=(y);
  b.operator/=(x);
  c.operator/=(x);
  REQUIRE(a.x_==5.0f);
  REQUIRE(a.y_==2.0f);
  REQUIRE(b.x_==1.2f);
  REQUIRE(b.y_==0.0f);
  REQUIRE(c.x_==2.72f);
  REQUIRE(c.y_==0.2f);
}
TEST_CASE("describe_operator+","[operator+]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{4.0f},{0.0f}};
  Vec2 c{{6.8f},{0.5f}};
  Vec2 d{{0.7f},{4.8f}};
  Vec2 temp_1 = a + b;
  Vec2 temp_2{operator+(b,c)};
  Vec2 temp_3{operator+(d,a)};
  REQUIRE(temp_1.x_==9.0f);
  REQUIRE(temp_1.y_==2.0f);
  REQUIRE(temp_2.x_==10.8f);
  REQUIRE(temp_2.y_==0.5f);
  REQUIRE(temp_3.x_==5.7f);
  REQUIRE(temp_3.y_==6.8f);
}
TEST_CASE("describe_operator-","[operator-]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{4.0f},{0.0f}};
  Vec2 c{{0.2f},{0.5f}};
  Vec2 d{{0.7f},{4.8f}};
  Vec2 temp_1{operator-(a,b)};
  Vec2 temp_2{operator-(b,a)};
  Vec2 temp_3{operator-(d,c)};
  REQUIRE(temp_1.x_==1.0f);
  REQUIRE(temp_1.y_==2.0f);
  REQUIRE(temp_2.x_==-1.0f);
  REQUIRE(temp_2.y_==-2.0f);
  REQUIRE(temp_3.x_==0.5f);
  REQUIRE(temp_3.y_==4.3f);
}
TEST_CASE("describe_operator*","[operator*]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{4.0f},{0.0f}};
  Vec2 c{{-3.0f},{1.0f}};
  float x=1.3;
  float y=0.4;
  Vec2 temp_1{operator*(a,x)};
  Vec2 temp_2{operator*(b,x)};
  Vec2 temp_3{operator*(c,y)};
  REQUIRE(temp_1.x_==6.5f);
  REQUIRE(temp_1.y_==2.6f);
  REQUIRE(temp_2.x_==5.2f);
  REQUIRE(temp_2.y_==0.0f);
  REQUIRE(temp_3.x_==-1.2f);
  REQUIRE(temp_3.y_==0.4f);
}
TEST_CASE("describe_operator/","[operator/]")
{ Vec2 a{{5.2f},{2.0f}};
  Vec2 b{{4.0f},{0.0f}};
  Vec2 c{{-3.0f},{1.0f}};
  float x=4.0;
  float y=0.4;
  float z=0.0;
  Vec2 temp_1{operator/(a,x)};
  Vec2 temp_2{operator/(b,x)};
  Vec2 temp_3{operator/(c,y)};
  Vec2 temp_4{operator/(c,z)};
  REQUIRE(temp_1.x_==1.3f);
  REQUIRE(temp_1.y_==0.5f);
  REQUIRE(temp_2.x_==1.0f);
  REQUIRE(temp_2.y_==0.0f);
  REQUIRE(temp_3.x_==-7.5f);
  REQUIRE(temp_3.y_==2.5f);
  REQUIRE(temp_4.x_==-3.0f);
  REQUIRE(temp_4.y_==1.0f);
}
TEST_CASE("describe_operator*2","[operator*2]")
{ Vec2 a{{5.0f},{2.0f}};
  Vec2 b{{4.0f},{0.0f}};
  Vec2 c{{-3.0f},{1.0f}};
  float x=1.3;
  float y=0.4;
  Vec2 temp_1{operator*(x,a)};
  Vec2 temp_2{operator*(x,b)};
  Vec2 temp_3{operator*(y,c)};
  REQUIRE(temp_1.x_==6.5f);
  REQUIRE(temp_1.y_==2.6f);
  REQUIRE(temp_2.x_==5.2f);
  REQUIRE(temp_2.y_==0.0f);
  REQUIRE(temp_3.x_==-1.2f);
  REQUIRE(temp_3.y_==0.4f);
}
TEST_CASE("describe_mat2","[mat2]")
{ Mat2 a{};
  Mat2 b{{4.2f},{2.1f},{3.2f},{5.5f}};
  REQUIRE(a.x1==1.0f);
  REQUIRE(a.x2==0.0f);
  REQUIRE(a.y1==0.0f);
  REQUIRE(a.y2==1.0f);
  REQUIRE(b.x1==4.2f);
  REQUIRE(b.x2==2.1f);
  REQUIRE(b.y1==3.2f);
  REQUIRE(b.y2==5.5f);
}
TEST_CASE("describe_operator*=mat2","[operator*=mat2]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Mat2 b{{4.0f},{2.0f},{3.0f},{5.0f}};
  a.operator*=(b);
  REQUIRE(a.x1==18.0f);
  REQUIRE(a.x2==16.0f);
  REQUIRE(a.y1==19.0f);
  REQUIRE(a.y2==27.0f);
}
TEST_CASE("describe_operator*mat2","[operator*mat2]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Mat2 b{{4.0f},{2.0f},{3.0f},{5.0f}};
  Mat2 temp{operator*(a,b)};
  REQUIRE(temp.x1==18.0f);
  REQUIRE(temp.x2==16.0f);
  REQUIRE(temp.y1==19.0f);
  REQUIRE(temp.y2==27.0f);
}
TEST_CASE("describe_det","[det]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Mat2 b{{4.0f},{2.0f},{3.0f},{5.0f}};
  float result1=a.det();
  float result2=b.det();
  REQUIRE(result1==13.0f);
  REQUIRE(result2==14.0f);
 }
 TEST_CASE("describe_operatorM*V","[operatorM*V]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Vec2 b{{3.0f},{2.0f}};
  Vec2 result{operator*(a,b)};
  REQUIRE(result.x_==13.0f);
  REQUIRE(result.y_==13.0f);
}
 TEST_CASE("describe_operatorV*M","[operatorV*M]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Vec2 b{{3.0f},{2.0f}};
  Vec2 result{operator*(b,a)};
  REQUIRE(result.x_==3.0f);
  REQUIRE(result.y_==2.0f);
}
 TEST_CASE("describe_inverse","[inverse]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Mat2 b{{4.0f},{2.0f},{3.0f},{5.0f}};
  Mat2 result1{inverse(a)};
  Mat2 result2{inverse(b)};
  REQUIRE(result1.x1==Approx(0.3846f).epsilon(0.01));
  REQUIRE(result1.x2==Approx(-0.07692f).epsilon(0.01));
  REQUIRE(result1.y1==Approx(-0.1538f).epsilon(0.01));
  REQUIRE(result1.y2==Approx(0.23016f).epsilon(0.01));
  REQUIRE(result2.x1==Approx(0.357f).epsilon(0.01));
  REQUIRE(result2.x2==Approx(-0.2142f).epsilon(0.01));
  REQUIRE(result2.y1==Approx(-0.1428f).epsilon(0.01));
  REQUIRE(result2.y2==Approx(0.2857f).epsilon(0.01));
}
 TEST_CASE("describe_transponse","[transponse]")
{ Mat2 a{{3.0f},{2.0f},{1.0f},{5.0f}};
  Mat2 b{{4.0f},{2.0f},{3.0f},{5.0f}};
  Mat2 result1{transpose(a)};
  Mat2 result2{transpose(b)};
  REQUIRE(result1.x1==3.0f);
  REQUIRE(result1.x2==1.0f);
  REQUIRE(result1.y1==2.0f);
  REQUIRE(result1.y2==5.0f);
  REQUIRE(result2.x1==4.0f);
  REQUIRE(result2.x2==3.0f);
  REQUIRE(result2.y1==2.0f);
  REQUIRE(result2.y2==5.0f);
}
TEST_CASE("describe_color","[color]"){ 
  Color a{1.0f};
  Color b{{0.2f},{0.1f},{0.8f}};
  Color c{};
  REQUIRE(a.r==1.0f);
  REQUIRE(a.g==1.0f);
  REQUIRE(a.b==1.0f);
  REQUIRE(b.r==0.2f);
  REQUIRE(b.g==0.1f);
  REQUIRE(b.b==0.8f);
  REQUIRE(c.r==0.0f);
  REQUIRE(c.g==0.0f);
  REQUIRE(c.b==0.0f);
}
TEST_CASE("describe_circle","[circle]")
{ Circle a{};
  Vec2 b{{4.0f},{2.0f}};
  float r=2.0f;
  Color x{{0.1f},{0.2f},{0.3f}};
  Circle c{b,r,x};
  REQUIRE(a.getCenter().x_==0.0f);
  REQUIRE(a.getCenter().y_==0.0f);
  REQUIRE(a.getRadius()==0.0f);
  REQUIRE(a.getColorC().r==0.0f);
  REQUIRE(a.getColorC().g==0.0f);
  REQUIRE(a.getColorC().b==0.0f);
  REQUIRE(c.getCenter().x_==4.0f);
  REQUIRE(c.getCenter().y_==2.0f);
  REQUIRE(c.getRadius()==2.0f);
  REQUIRE(c.circumfrenceC()==Approx(12.566f).epsilon(0.01));
  REQUIRE(c.getColorC().r==0.1f);
  REQUIRE(c.getColorC().g==0.2f);
  REQUIRE(c.getColorC().b==0.3f);
}
TEST_CASE("describe_rectangle","[rectangle]")
{ Rectangle a{};
  Vec2 b{{4.0f},{2.0f}};
  Vec2 c{{6.0f},{8.0f}};
  Color x{{0.1f},{0.2f},{0.3f}};
  Rectangle d{b,c,x};
  REQUIRE(a.getMin_().x_==0.0f);
  REQUIRE(a.getMin_().y_==0.0f);
  REQUIRE(a.getMax_().x_==0.0f);
  REQUIRE(a.getMax_().y_==0.0f);
  REQUIRE(a.getBottomright_().x_==0.0f);
  REQUIRE(a.getBottomright_().y_==0.0f);
  REQUIRE(a.getTopleft_().x_==0.0f);
  REQUIRE(a.getTopleft_().y_==0.0f);
  REQUIRE(a.getColorR().r==0.0f);
  REQUIRE(a.getColorR().g==0.0f);
  REQUIRE(a.getColorR().b==0.0f);
  REQUIRE(d.getMin_().x_==4.0f);
  REQUIRE(d.getMin_().y_==2.0f);
  REQUIRE(d.getMax_().x_==6.0f);
  REQUIRE(d.getMax_().y_==8.0f);
  REQUIRE(d.getBottomright_().x_==6.0f);
  REQUIRE(d.getBottomright_().y_==2.0f);
  REQUIRE(d.getTopleft_().x_==4.0f);
  REQUIRE(d.getTopleft_().y_==8.0f);
  REQUIRE(d.circumfrenceR()==16.0f);
  REQUIRE(d.getColorR().r==0.1f);
  REQUIRE(d.getColorR().g==0.2f);
  REQUIRE(d.getColorR().b==0.3f);
}
 
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

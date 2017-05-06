#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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
  Vec2 temp_1{operator+(a,b)};
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



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

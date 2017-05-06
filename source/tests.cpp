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


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

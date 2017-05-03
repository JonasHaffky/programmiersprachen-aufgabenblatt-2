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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

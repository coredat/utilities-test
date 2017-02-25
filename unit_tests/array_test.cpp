#include <catch/catch.hpp>
#include <utilities/array.hpp>


TEST_CASE("Array Test")
{
  SECTION("Initalize")
  {
    lib::array<int, 3> int_array;

    REQUIRE(int_array.size() == 0);
    REQUIRE(int_array.capacity() == 3);
    REQUIRE(int_array.empty() == true);
  }

  SECTION("List Ctor")
  {
    lib::array<int, 3> int_array({1,2,3});

    REQUIRE(int_array.size() == 3);
    REQUIRE(int_array.empty() == false);
    REQUIRE(int_array.capacity() == 3);

    REQUIRE(int_array[0] == 1);
    REQUIRE(int_array[1] == 2);
    REQUIRE(int_array[2] == 3);
  }

  SECTION("Push back")
  {
    lib::array<int, 3> int_array;
    REQUIRE(int_array.size() == 0);

    int_array.push_back(1);
    REQUIRE(int_array[0] == 1);
    REQUIRE(int_array.size() == 1);
    ;
    int_array.push_back(2);
    REQUIRE(int_array[0] == 1);
    REQUIRE(int_array[1] == 2);
    REQUIRE(int_array.size() == 2);

    int_array.push_back(3);
    REQUIRE(int_array[0] == 1);
    REQUIRE(int_array[1] == 2);
    REQUIRE(int_array[2] == 3);
    REQUIRE(int_array.size() == 3);

    REQUIRE(int_array.empty() == false);
    REQUIRE(int_array.capacity() == 3);
  }

  SECTION("Resize")
  {
    lib::array<int, 3> int_array({1,2,3});

    int_array.resize(6);

    REQUIRE(int_array.capacity() == 6);
    REQUIRE(int_array.size() == 6);
    REQUIRE(int_array.empty() == false);

    REQUIRE(int_array[0] == 1);
    REQUIRE(int_array[1] == 2);
    REQUIRE(int_array[2] == 3);
  }

  SECTION("Reserve")
  {
    lib::array<int, 3> int_array;

    int_array.push_back(1);
    int_array.push_back(2);
    int_array.push_back(3);

    int_array.reserve(6);

    REQUIRE(int_array.capacity() == 6);
    REQUIRE(int_array.size() == 3);

    REQUIRE(int_array[0] == 1);
    REQUIRE(int_array[1] == 2);
    REQUIRE(int_array[2] == 3);
  }

  SECTION("Emplace back")
  {
    struct Foo
    {
      size_t _foo;
    };

    lib::array<Foo, 3> foo_array;

    foo_array.emplace_back(size_t{1});
    REQUIRE(foo_array.size() == 1);
    REQUIRE(foo_array.capacity() == 3);

    foo_array.emplace_back(Foo{2});
    REQUIRE(foo_array.size() == 2);
    REQUIRE(foo_array.capacity() == 3);

    Foo bar;
    foo_array.emplace_back(bar);
    REQUIRE(foo_array.size() == 3);
    REQUIRE(foo_array.capacity() == 3);
  }

  SECTION("For loops")
  {
    const lib::array<int, 3> int_array({1,2,3});

    int counter = 0;

    // range for

    for(const auto &i : int_array)
    {
      ++counter;

      REQUIRE(i == counter);
    }

    REQUIRE(counter == int_array.size());

    // -- for

    counter = 0;

    for(int i = 0; i < int_array.size(); ++i)
    {
      ++counter;

      REQUIRE(int_array[i] == counter);
    }

    REQUIRE(counter == 3);
  }
}

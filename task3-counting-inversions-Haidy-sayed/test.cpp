// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "naive_inversion.hpp"
#include "dandq_inversion.hpp"

TEST_CASE("Example 1", "[multi-file:2]"){
  vector<int> a = {8, 4, 2, 1};
  int naive_result = naive_counting_inversions(a);
  int dandq_result = naive_counting_inversions(a);
  REQUIRE( naive_result == dandq_result);
  REQUIRE( dandq_result == 6);
}

TEST_CASE("Example 2", "[multi-file:2]"){
  vector<int> a = {3, 1, 2};
  int naive_result = naive_counting_inversions(a);
  int dandq_result = naive_counting_inversions(a);
  REQUIRE( naive_result == dandq_result);
  REQUIRE( dandq_result == 2);
}
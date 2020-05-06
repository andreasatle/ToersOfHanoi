/// @brief Test suite for the game Towers of Hanoi.

#include "../src/tower.h"
#include "../catch/catch.hpp"

/// Test 1 - Game of size 3
TEST_CASE("Game of size 3.") {

  TowerOfHanoi tower(3);

  SECTION("Source stack should contain 3 elements 1,2,3 after constructor") {
    TowerOfHanoi::Tower stack = tower.get_source_stack();

    REQUIRE(stack.size() == 3);

    int e1 = stack.top(); stack.pop();
    int e2 = stack.top(); stack.pop();
    int e3 = stack.top(); stack.pop();

    REQUIRE(e1 == 1);
    REQUIRE(e2 == 2);
    REQUIRE(e3 == 3);
  }

  SECTION("Work stack should be empty after constructor") {
    TowerOfHanoi::Tower stack = tower.get_work_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Target stack should be empty after constructor") {
    TowerOfHanoi::Tower stack = tower.get_target_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("No moves are taken") {
    REQUIRE(tower.get_num_moves() == 0);
  }

  tower.mute();
  tower.play();
  tower.unmute();

  SECTION("Source stack should be empty after game") {
    TowerOfHanoi::Tower stack = tower.get_source_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Work stack should be empty after game") {
    TowerOfHanoi::Tower stack = tower.get_work_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Target stack should contain 3 elements 1,2,3 after game") {
    TowerOfHanoi::Tower stack = tower.get_target_stack();
    REQUIRE(stack.size() == 3);

    int e1 = stack.top(); stack.pop();
    int e2 = stack.top(); stack.pop();
    int e3 = stack.top(); stack.pop();

    REQUIRE(e1 == 1);
    REQUIRE(e2 == 2);
    REQUIRE(e3 == 3);
  }

  SECTION("7 moves are taken") {
    REQUIRE(tower.get_num_moves() == 7);
  }
}

/// Test 2 - Game of size 4
TEST_CASE("Game of size 4.") {

  TowerOfHanoi tower(4);

  SECTION("Source stack should contain 4 elements 1,2,3,4 after constructor") {
    TowerOfHanoi::Tower stack = tower.get_source_stack();

    REQUIRE(stack.size() == 4);

    int e1 = stack.top(); stack.pop();
    int e2 = stack.top(); stack.pop();
    int e3 = stack.top(); stack.pop();
    int e4 = stack.top(); stack.pop();

    REQUIRE(e1 == 1);
    REQUIRE(e2 == 2);
    REQUIRE(e3 == 3);
    REQUIRE(e4 == 4);
  }

  SECTION("Work stack should be empty after constructor") {
    TowerOfHanoi::Tower stack = tower.get_work_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Target stack should be empty after constructor") {
    TowerOfHanoi::Tower stack = tower.get_target_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("No moves are taken") {
    REQUIRE(tower.get_num_moves() == 0);
  }

  tower.mute();
  tower.play();
  tower.unmute();

  SECTION("Source stack should be empty after game") {
    TowerOfHanoi::Tower stack = tower.get_source_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Work stack should be empty after game") {
    TowerOfHanoi::Tower stack = tower.get_work_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Target stack should contain 4 elements 1,2,3,4 after game") {
    TowerOfHanoi::Tower stack = tower.get_target_stack();
    REQUIRE(stack.size() == 4);

    int e1 = stack.top(); stack.pop();
    int e2 = stack.top(); stack.pop();
    int e3 = stack.top(); stack.pop();
    int e4 = stack.top(); stack.pop();

    REQUIRE(e1 == 1);
    REQUIRE(e2 == 2);
    REQUIRE(e3 == 3);
    REQUIRE(e4 == 4);
  }

  SECTION("15 moves are taken") {
    REQUIRE(tower.get_num_moves() == 15);
  }
}

/// Test 3 - Game of size 5
TEST_CASE("Game of size 5.") {

  TowerOfHanoi tower(5);

  SECTION("Source stack should contain 5 elements 1,2,3,4,5 after constructor") {
    TowerOfHanoi::Tower stack = tower.get_source_stack();

    REQUIRE(stack.size() == 5);

    int e1 = stack.top(); stack.pop();
    int e2 = stack.top(); stack.pop();
    int e3 = stack.top(); stack.pop();
    int e4 = stack.top(); stack.pop();
    int e5 = stack.top(); stack.pop();

    REQUIRE(e1 == 1);
    REQUIRE(e2 == 2);
    REQUIRE(e3 == 3);
    REQUIRE(e4 == 4);
    REQUIRE(e5 == 5);
  }

  SECTION("Work stack should be empty after constructor") {
    TowerOfHanoi::Tower stack = tower.get_work_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Target stack should be empty after constructor") {
    TowerOfHanoi::Tower stack = tower.get_target_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("No moves are taken") {
    REQUIRE(tower.get_num_moves() == 0);
  }

  tower.mute();
  tower.play();
  tower.unmute();

  SECTION("Source stack should be empty after game") {
    TowerOfHanoi::Tower stack = tower.get_source_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Work stack should be empty after game") {
    TowerOfHanoi::Tower stack = tower.get_work_stack();

    REQUIRE(stack.size() == 0);
  }

  SECTION("Target stack should contain 5 elements 1,2,3,4,5 after game") {
    TowerOfHanoi::Tower stack = tower.get_target_stack();
    REQUIRE(stack.size() == 5);

    int e1 = stack.top(); stack.pop();
    int e2 = stack.top(); stack.pop();
    int e3 = stack.top(); stack.pop();
    int e4 = stack.top(); stack.pop();
    int e5 = stack.top(); stack.pop();

    REQUIRE(e1 == 1);
    REQUIRE(e2 == 2);
    REQUIRE(e3 == 3);
    REQUIRE(e4 == 4);
    REQUIRE(e5 == 5);
  }

  SECTION("31 moves are taken") {
    REQUIRE(tower.get_num_moves() == 31);
  }
}


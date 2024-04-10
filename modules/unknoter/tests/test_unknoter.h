#pragma once

#include "tests/test_macros.h"

#include "modules/unknoter/unknoterImpl.h"

namespace TestUnknoter {

TEST_CASE("[Modules][Unknoter] Test UnknoterImpl behavior") {
    UnknoterImpl unknoter;

    unknoter.set_param("players", 3);
    unknoter.set_param("width", 6);
    unknoter.set_param("height", 6);
    unknoter.reset();

    std::vector<std::vector<int>> field = {
        {-1,  0, -1,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1},
        { 0, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1},
        {-1, -1, -1,  1, -1,  1, -1,  1,  1,  1, -1, -1, -1},
        { 0, -1,  1, -1, -1, -1, -1, -1,  0, -1,  1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1,  1,  1,  1, -1, -1, -1},
        { 0, -1,  1, -1, -1, -1,  1, -1,  0, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1,  2,  2,  2,  2,  2, -1, -1, -1},
        { 0, -1,  1, -1,  2, -1,  1, -1,  0, -1,  2, -1, -1},
        {-1,  0,  1,  0,  2,  0,  1,  0, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1,  2, -1,  1, -1, -1, -1,  2, -1, -1},
        {-1, -1, -1, -1, -1,  2,  2,  2, -1,  2, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1,  1, -1,  1, -1, -1, -1, -1, -1, -1, -1}
    };

    unknoter._set_field({field});

    CHECK(unknoter.get_param("players") == 3);
    CHECK(unknoter.get_param("width") == 6);
    CHECK(unknoter.get_param("height") == 6);

    // Correct moves
    CHECK(unknoter.can_player_shift_edges(1, 3, 10, 0, -2));
    CHECK(unknoter.can_player_shift_edges(0, 0, 3, -1, 2));
    CHECK(unknoter.can_player_shift_edges(1, 3, 2, 0, 1));
    CHECK(unknoter.can_player_shift_edges(2, 9, 10, -1, 1));
    CHECK(unknoter.can_player_shift_edges(0, 0, 1, 1, 2));
    CHECK(unknoter.can_player_shift_edges(1, 3, 10, 0, -3));
    CHECK(unknoter.can_player_shift_edges(2, 9, 10, 0, 1));
    CHECK(unknoter.can_player_shift_edges(2, 7, 10, 0, 1));
    CHECK(unknoter.can_player_shift_edges(0, 1, 8, 3, 2));
    CHECK(unknoter.can_player_shift_edges(1, 11, 2, -4, 5));

    // Offset out of bounds
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 10, 9, 6, 5));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 7, 0, -5, 1));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 12, 3, -5, 3));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 1, 10, -2, -1));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 0, 5, 5, 3));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 3, 0, 5, -2));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 7, 0, 4, -5));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 12, 1, -6, 6));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 8, 1, 6, -1));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 4, 5, -6, -1));

    // Offset does not belong to our component
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 0, 11, -2, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 12, 3, 0, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 0, 7, 0, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 11, 4, 0, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 5, 0, 1, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 7, 2, -3, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 4, 4, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 4, 1, 4, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 12, 9, -2, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 12, 5, -1, -6));

    // Perpendicular offset out of bounds
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 9, 10, 0, 4));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 12, 5, -1, 2));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 9, 4, -1, 6));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 4, 7, 1, -6));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 0, 5, 0, -3));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 0, 3, 2, -5));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 0, 7, -2, -1));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 10, 5, 0, 4));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 0, 1, -6));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 7, 2, 1, -4));

    // Perpendicular offset destination is occupied
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 5, -1, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 11, 2, -4, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 5, 1, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 5, 6, 2, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 8, 3, 1, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 5, 0, 1, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 8, 5, 1, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 9, 10, -1, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 9, 6, -1, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 7, 0, -3, 3));

    // Side edges belong to a different component
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 8, 1, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 5, 8, -1, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 7, 2, -2, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 6, 5, 0, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 7, 2, -1, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 8, 0, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 5, 0, 1, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 11, 2, 0, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 5, 8, 0, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 5, 0, -2, 6));

    // Deleting edges of our component for the second time
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 11, 2, -3, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 9, -1, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 7, 1, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 5, 2, 3, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 3, 2, 0, 5));

    // Touching a different component
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 5, -1, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 3, 2, 0, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 5, 0, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 2, 3, 1, 1));

    // Touching ourselves
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 0, 3, -1, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 0, 1, 2, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, 2, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 0, 1, 0, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 5, 2, 0, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 12, 3, 0, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 0, -1, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 5, 2, -1, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, 1, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 5, 0, 0, 2));

    unknoter.shift_edges(0, 1, 1, 2);
    unknoter.shift_edges(4, 1, 1, -2);
    CHECK_EQ(field, unknoter._get_field());
}

TEST_CASE("[Modules][Unknoter] Test UnknoterImpl behavior big") {
    UnknoterImpl unknoter;

    unknoter.set_param("players", 4);
    unknoter.set_param("width", 20);
    unknoter.set_param("height", 20);
    unknoter.reset();

    std::vector<std::vector<int>> field = {
        {-1, -1, -1,  1, -1,  1, -1,  1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1,  2, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1,  2, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 2, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 2, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1,  2, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  2, -1,  2, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 2, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1,  2, -1,  2, -1,  2, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1,  2, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1,  1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 1, -1, -1, -1,  3, -1, -1, -1,  2, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  0, -1, -1, -1,  3, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 1, -1, -1, -1,  3, -1, -1, -1,  2, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  0, -1, -1, -1,  3, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1},
        { 1, -1, -1, -1,  3, -1, -1, -1,  2, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1, -1},
        {-1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1},
        { 1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1,  1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1,  1},
        {-1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1,  2, -1,  1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1, -1},
        {-1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 0, -1,  1, -1, -1, -1, -1, -1,  2, -1,  1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 0, -1,  1, -1, -1, -1, -1, -1,  2, -1,  1, -1,  3, -1, -1, -1,  3, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1,  3, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1},
        { 0, -1,  1, -1, -1, -1, -1, -1,  2, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1,  2, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  3, -1, -1},
        {-1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1,  2, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1,  2, -1,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  3, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1, -1, -1,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1,  1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1, -1},
        {-1, -1, -1,  1, -1,  1, -1,  1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1,  3, -1, -1, -1}
    };

    unknoter._set_field({field});

    // Correct moves
    CHECK(unknoter.can_player_shift_edges(2, 23, 24, 5, 1));
    CHECK(unknoter.can_player_shift_edges(3, 14, 19, 1, -2));
    CHECK(unknoter.can_player_shift_edges(2, 38, 17, -1, 1));
    CHECK(unknoter.can_player_shift_edges(1, 25, 0, 0, 3));
    CHECK(unknoter.can_player_shift_edges(3, 18, 7, 2, -1));
    CHECK(unknoter.can_player_shift_edges(2, 8, 25, 0, -4));
    CHECK(unknoter.can_player_shift_edges(2, 10, 29, -1, 1));
    CHECK(unknoter.can_player_shift_edges(0, 30, 17, -1, 1));
    CHECK(unknoter.can_player_shift_edges(2, 38, 9, 5, -3));
    CHECK(unknoter.can_player_shift_edges(2, 38, 17, -4, -14));
    CHECK(unknoter.can_player_shift_edges(3, 14, 21, -1, -2));
    CHECK(unknoter.can_player_shift_edges(1, 21, 0, 1, 1));
    CHECK(unknoter.can_player_shift_edges(0, 21, 34, -5, 3));
    CHECK(unknoter.can_player_shift_edges(2, 6, 7, -3, -2));
    CHECK(unknoter.can_player_shift_edges(3, 40, 23, 3, -7));
    CHECK(unknoter.can_player_shift_edges(1, 35, 2, 1, 1));
    CHECK(unknoter.can_player_shift_edges(1, 24, 27, 6, -9));
    CHECK(unknoter.can_player_shift_edges(3, 31, 38, -4, -4));
    CHECK(unknoter.can_player_shift_edges(3, 34, 15, 0, -6));
    CHECK(unknoter.can_player_shift_edges(0, 2, 29, 2, 5));

    // Offset out of bounds
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 21, 26, 13, 9));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 26, 39, 19, -20));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 26, 21, -19, -19));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 37, 38, 19, -1));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 34, 27, -15, -19));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 0, 1, -8, -19));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 20, 13, -12, -6));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 0, 11, -9, 19));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 26, -8, -8));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 17, 36, -20, 20));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 7, 2, -11, 7));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 14, 7, -12, 20));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 16, 5, -10, -18));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 10, 7, 17, -9));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 15, 38, -16, -7));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 31, 8, -10));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 29, 34, 8, 4));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 12, 33, 11, -3));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 39, 4, 12, -7));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 17, 30, -19, 7));

    // Offset does not belong to our component
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 7, 32, 1, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 7, 28, 6, -12));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 33, 32, -16, 12));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 36, 7, 6, -19));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 21, 20, 1, 7));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 15, 0, 0, 16));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 39, 6, -18, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 4, 33, -12, 12));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 17, 2, -6, -14));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 2, 31, -2, -19));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 1, 11, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 35, 0, -2, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 25, 28, 5, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 29, 38, 4, -11));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 5, 38, 13, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 21, 16, 4, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 24, 11, -1, 13));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 18, 3, 8, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 38, 25, -12, 17));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 15, 36, 11, -9));

    // Perpendicular offset out of bounds
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 7, 28, 9, -16));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 3, 2, 9));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 21, 8, 0, -17));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 11, 28, 7, -15));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 13, 10, 7));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 37, -7, -17));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 13, 8, 10, 18));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 5, 0, -13));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 3, 2, 0, -6));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 33, 2, -16));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 7, 12, -16));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 27, -8, 16));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 1, 8, 18));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 9, 28, 7, 9));
    // CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 17, -6, -10));
    // CHECK_FALSE(unknoter.can_player_shift_edges(2, 17, 8, 10, -9));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 19, 5, 19));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 7, 7, 8));
    // CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 21, -9, 16));
    // CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 23, 5, 10));

    // Perpendicular offset destination is occupied
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 13, 28, 4, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 13, 28, -5, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 25, 24, -3, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 21, 3, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 36, 1, 9, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 21, -2, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 25, -3, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 29, 28, -6, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 27, -3, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 23, -9, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 13, 24, 7, -8));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 5, 11, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 31, -11, 12));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 23, 28, -2, -9));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 12, 5, -2, 14));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 27, 0, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 19, 8, 5, 16));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 15, 12, 8));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 19, -7, 13));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 9, -1, 6));

    // Side edges belong to a different component
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 23, -2, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 34, 8, -14));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 35, 8, 0, 9));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 38, 11, 2, -14));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 9, 2, -1, 12));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 21, -2, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 33, 34, -4, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 13, 7, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 35, 8, -9, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 33, 24, -9, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 25, 34, 2, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 33, 16, -4, 7));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 19, 28, -2, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 29, 38, 0, -12));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 27, 22, 4, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 30, 23, -1, -14));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 35, 0, -8));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 23, 4, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 29, 10, 3, 10));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 29, 38, 0, -9));

    // Deleting edges of our component for the second time
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 17, 9, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 35, 32, 0, -8));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 17, 4, -1, 16));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 9, 0, 0, 15));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 35, -12, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 40, 7, 1, -18));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 38, 29, 0, -11));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 19, -1, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 17, 32, 0, -13));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 13, 6, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 19, 6, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 31, 2, -1, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 9, 0, 1, 11));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 8, 23, 0, 7));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 35, -1, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 11, 9, -14));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 0, 3, 3, 17));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 8, 31, -3, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 17, 0, 3, 10));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 22, 17, 0, -3));

    // Touch yourself 1
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 11, 34, -4, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 19, 8, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 10, 29, -2, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 6, 7, 3, 10));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 19, 0, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 11, 0, -2, 11));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 8, 29, -1, 14));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 19, 0, 7));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 31, 12, -2, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 21, 34, -8, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 19, 0, 8));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 7, 28, 11, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 31, 0, 6));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 17, 2, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 39, -4, -14));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 33, 34, -14, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 29, -4, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 3, 14, 1, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 19, 0, 11));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 40, 35, -2, -14));

    // Touch yourself 2
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 31, 34, -14, -8));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 23, 22, 8, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 34, 14, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 7, 16, -2, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 8, 23, 4, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 21, 38, 9, -10));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 31, 34, -14, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 11, 24, 13, -9));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 8, 21, 5, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 31, 34, -14, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 34, 15, -8));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 7, 16, -2, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 8, 19, 6, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 3, 16, 2, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 2, 33, -2, 17));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 2, 33, -1, 17));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 35, -9, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 2, 31, 1, 17));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 7, 16, -2, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 34, 14, -4));

    // Touch yourself 3
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 7, 16, 0, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 37, -3, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 25, -1, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 25, 34, -9, -8));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 5, 16, 1, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 18, 25, -1, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 35, -8, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 21, -2, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 25, -2, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 36, 13, -3, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 33, 3, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 19, 0, 7));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 7, 34, 12, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 35, -1, 4));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 25, -5, 9));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 3, 34, 9, -4));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 12, 1, 1, -5));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 31, 4, 3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 38, 27, 2, -6));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 36, 5, 0, -5));

    // Touching a different component
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 1, 10, 4, 7));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 36, 25, -4, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 24, 15, 5, -9));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 40, 35, 1, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 38, 19, -1, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 21, 28, -9, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 33, 22, -3, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 14, 7, 4, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 38, 11, -1, -2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 36, 15, 2, -15));
    CHECK_FALSE(unknoter.can_player_shift_edges(2, 11, 24, 5, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 33, 22, 0, 5));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 19, 34, 1, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 1, 10, 0, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 20, 35, -4, 8));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 7, 28, 2, -7));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 29, 34, -5, -1));
    CHECK_FALSE(unknoter.can_player_shift_edges(1, 28, 25, -5, -11));
    CHECK_FALSE(unknoter.can_player_shift_edges(3, 39, 38, 0, -3));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 36, 17, 0, -1));
}

} // namespace TestUnknoter

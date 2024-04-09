#pragma once

#include "tests/test_macros.h"

#include "modules/unknoter/unknoterImpl.h"

namespace TestUnknoter {

TEST_CASE("[Modules][Unknoter] Test UnknoterImpl behavior") {
    UnknoterImpl unknoter;

    unknoter.reset(3, 6, 6);

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

    CHECK(unknoter.get_players() == 3);
    CHECK(unknoter.get_width() == 6);
    CHECK(unknoter.get_height() == 6);

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

    unknoter.shift_edges(1, 0, 1, 2);
    unknoter.shift_edges(1, 4, 1, -2);
    CHECK_EQ(field, unknoter._get_field());
}

} // namespace TestUnknoter

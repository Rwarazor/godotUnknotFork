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

    for (int i = 0; i < 6; ++i) {
        if (i <= 3) {
            CHECK(unknoter.can_player_shift_edges(0, 1, 0, i, 0));
        }
        else {
            CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, i, 0));
        }
    }
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, 0, 1));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, 0, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, 1, 1));
    CHECK(unknoter.can_player_shift_edges(0, 1, 0, 1, 2));
    CHECK_FALSE(unknoter.can_player_shift_edges(0, 1, 0, 1, 3));

    unknoter.shift_edges(1, 0, 1, 2);
    unknoter.shift_edges(1, 4, 1, -2);
    CHECK_EQ(field, unknoter._get_field());
}

} // namespace TestUnknoter


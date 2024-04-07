#include "unknoterImpl.h"

#include <iostream>

std::vector<std::vector<std::pair<int, int>>> get_field() {
  return {
    {{0, 35}, {1, 34}, {0, 37}, {1, 38}, {3, 34}, {3, 38}, {5, 34}, {5, 38}, {7, 34}, {7, 38}, {9, 34}, {9, 38}, {11, 34}, {11, 38}, {13, 34}, {13, 38}, {15, 34}, {15, 38}, {31, 34}, {31, 38}, {33, 34}, {33, 38}, {35, 34}, {35, 38}, {37, 34}, {37, 38}, {39, 34}, {39, 38}, {41, 34}, {41, 38}, {43, 34}, {43, 38}, {45, 34}, {45, 38}, {47, 34}, {47, 38}, {49, 34}, {49, 38}, {51, 34}, {51, 38}, {53, 38}, {55, 38}, {57, 38}, {60, 35}, {59, 34}, {60, 37}, {59, 38}, {17, 28}, {16, 33}, {19, 28}, {21, 28}, {23, 28}, {25, 28}, {27, 28}, {29, 28}, {30, 33}, {16, 39}, {16, 41}, {17, 42}, {19, 42}, {21, 42}, {23, 42}, {25, 42}, {27, 42}, {30, 39}, {30, 41}, {29, 42}, {0, 29}, {1, 28}, {0, 31}, {1, 32}, {3, 28}, {3, 32}, {5, 28}, {5, 32}, {7, 28}, {7, 32}, {9, 28}, {9, 32}, {11, 28}, {11, 32}, {13, 28}, {13, 32}, {15, 28}, {15, 32}, {31, 28}, {31, 32}, {33, 28}, {33, 32}, {35, 28}, {35, 32}, {37, 28}, {37, 32}, {39, 28}, {39, 32}, {41, 28}, {41, 32}, {43, 28}, {43, 32}, {45, 28}, {45, 32}, {48, 29}, {47, 28}, {48, 31}, {47, 32}, {52, 3}, {53, 2}, {52, 5}, {52, 7}, {52, 9}, {52, 11}, {52, 13}, {52, 15}, {52, 17}, {52, 19}, {52, 21}, {52, 23}, {52, 25}, {52, 27}, {52, 29}, {52, 31}, {52, 33}, {55, 2}, {58, 3}, {57, 2}, {58, 5}, {58, 7}, {58, 9}, {58, 11}, {58, 13}, {58, 15}, {58, 17}, {58, 19}, {58, 21}, {58, 23}, {58, 25}, {58, 27}, {58, 29}, {58, 31}, {58, 33}},
    {{2, 1}, {3, 0}, {2, 3}, {2, 5}, {2, 7}, {2, 9}, {2, 11}, {2, 13}, {2, 15}, {2, 17}, {2, 19}, {2, 21}, {2, 23}, {2, 25}, {2, 27}, {2, 29}, {2, 31}, {2, 33}, {2, 35}, {2, 37}, {2, 39}, {2, 41}, {2, 43}, {2, 45}, {2, 47}, {2, 49}, {2, 51}, {2, 53}, {2, 55}, {2, 57}, {2, 59}, {3, 60}, {5, 0}, {5, 60}, {8, 1}, {7, 0}, {8, 5}, {8, 7}, {8, 9}, {8, 11}, {8, 13}, {8, 15}, {8, 17}, {8, 19}, {8, 21}, {8, 23}, {8, 25}, {8, 27}, {8, 29}, {8, 31}, {8, 33}, {8, 35}, {8, 37}, {8, 39}, {8, 41}, {8, 43}, {8, 45}, {8, 47}, {8, 49}, {8, 51}, {8, 53}, {8, 55}, {8, 57}, {8, 59}, {7, 60}, {9, 2}, {9, 4}, {11, 2}, {11, 4}, {13, 2}, {13, 4}, {15, 2}, {17, 2}, {19, 2}, {21, 2}, {23, 2}, {23, 4}, {25, 2}, {27, 2}, {29, 2}, {31, 2}, {33, 2}, {35, 2}, {38, 3}, {37, 2}, {38, 5}, {38, 7}, {38, 9}, {38, 11}, {38, 13}, {38, 15}, {38, 17}, {38, 19}, {38, 21}, {38, 23}, {38, 25}, {38, 27}, {38, 29}, {38, 31}, {38, 33}, {38, 35}, {38, 37}, {38, 39}, {38, 41}, {38, 43}, {38, 45}, {38, 47}, {38, 49}, {38, 51}, {38, 53}, {38, 55}, {24, 5}, {24, 7}, {24, 9}, {24, 11}, {24, 13}, {24, 15}, {24, 17}, {24, 19}, {24, 21}, {24, 23}, {24, 25}, {24, 27}, {24, 29}, {24, 31}, {24, 33}, {24, 35}, {24, 37}, {24, 39}, {24, 41}, {24, 43}, {24, 45}, {24, 47}, {24, 49}, {24, 51}, {24, 53}, {24, 55}, {24, 57}, {25, 58}, {27, 58}, {29, 58}, {31, 58}, {33, 58}, {35, 58}, {38, 57}, {37, 58}, {14, 5}, {14, 7}, {14, 9}, {14, 11}, {14, 13}, {14, 15}, {14, 17}, {14, 19}, {14, 21}, {14, 23}, {14, 25}, {14, 27}, {14, 29}, {14, 31}, {14, 33}, {14, 35}, {14, 37}, {14, 39}, {14, 41}, {14, 43}, {14, 45}, {15, 46}, {17, 46}, {19, 46}, {22, 5}, {22, 7}, {22, 9}, {22, 11}, {22, 13}, {22, 15}, {22, 17}, {22, 19}, {22, 21}, {22, 23}, {22, 25}, {22, 27}, {22, 29}, {22, 31}, {22, 33}, {22, 35}, {22, 37}, {22, 39}, {22, 41}, {22, 43}, {22, 45}, {21, 46}},
    {{28, 1}, {29, 0}, {28, 3}, {28, 5}, {28, 7}, {28, 9}, {28, 11}, {28, 13}, {28, 15}, {28, 17}, {28, 19}, {28, 21}, {28, 23}, {28, 53}, {28, 55}, {28, 57}, {28, 59}, {29, 60}, {31, 0}, {31, 60}, {33, 0}, {33, 60}, {35, 0}, {35, 60}, {37, 0}, {37, 60}, {39, 0}, {40, 53}, {40, 55}, {40, 57}, {40, 59}, {39, 60}, {26, 45}, {26, 47}, {26, 49}, {26, 51}, {27, 52}, {42, 29}, {42, 31}, {42, 33}, {42, 35}, {42, 37}, {42, 39}, {42, 41}, {42, 43}, {42, 45}, {42, 47}, {42, 49}, {42, 51}, {41, 52}, {42, 1}, {41, 0}, {42, 3}, {42, 5}, {42, 7}, {42, 9}, {42, 11}, {42, 13}, {42, 15}, {42, 17}, {42, 19}, {42, 21}, {42, 23}, {42, 25}, {42, 27}, {10, 25}, {11, 24}, {10, 27}, {10, 29}, {10, 31}, {10, 33}, {10, 35}, {10, 37}, {10, 39}, {10, 41}, {10, 43}, {11, 44}, {13, 24}, {13, 44}, {15, 24}, {15, 44}, {17, 24}, {17, 44}, {19, 24}, {19, 44}, {21, 24}, {21, 44}, {23, 24}, {23, 44}, {25, 24}, {25, 44}, {27, 24}},
    {{0, 9}, {1, 8}, {0, 11}, {0, 13}, {0, 15}, {0, 17}, {0, 19}, {0, 21}, {1, 22}, {3, 8}, {3, 22}, {5, 8}, {5, 22}, {7, 8}, {7, 22}, {9, 8}, {9, 22}, {11, 8}, {11, 22}, {13, 8}, {13, 22}, {15, 8}, {15, 22}, {17, 22}, {19, 22}, {21, 22}, {23, 22}, {25, 22}, {27, 22}, {29, 22}, {31, 22}, {33, 22}, {35, 22}, {37, 22}, {39, 22}, {41, 22}, {43, 22}, {45, 22}, {51, 8}, {53, 8}, {55, 8}, {57, 8}, {57, 22}, {60, 9}, {59, 8}, {60, 11}, {60, 13}, {60, 15}, {60, 17}, {60, 19}, {60, 21}, {59, 22}, {46, 23}, {46, 25}, {46, 27}, {46, 29}, {46, 31}, {46, 33}, {46, 35}, {46, 37}, {46, 39}, {46, 49}, {46, 51}, {46, 53}, {46, 55}, {46, 57}, {46, 59}, {47, 60}, {49, 60}, {51, 60}, {53, 60}, {56, 23}, {56, 25}, {56, 27}, {56, 29}, {56, 31}, {56, 33}, {56, 35}, {56, 37}, {56, 39}, {56, 59}, {55, 60}, {16, 7}, {17, 6}, {19, 6}, {21, 6}, {23, 6}, {25, 6}, {27, 6}, {29, 6}, {31, 6}, {33, 6}, {35, 6}, {37, 6}, {39, 6}, {41, 6}, {43, 6}, {45, 6}, {47, 6}, {50, 7}, {49, 6}, {20, 41}, {21, 40}, {20, 43}, {20, 45}, {20, 47}, {21, 48}, {23, 40}, {23, 48}, {25, 40}, {25, 48}, {27, 40}, {27, 48}, {29, 40}, {29, 48}, {31, 40}, {31, 48}, {33, 40}, {33, 48}, {35, 40}, {35, 48}, {37, 40}, {37, 48}, {39, 40}, {39, 48}, {41, 40}, {41, 48}, {43, 40}, {43, 48}, {45, 40}, {45, 48}, {57, 40}, {57, 58}, {60, 41}, {59, 40}, {60, 43}, {60, 45}, {60, 47}, {60, 49}, {60, 51}, {60, 53}, {60, 55}, {60, 57}, {59, 58}}
  };
}

void UnknoterImpl::_set_field(const std::vector<std::vector<int>>& field) {
    coords_to_player = field;
}

int UnknoterImpl::get_width() {
  return width;
}

int UnknoterImpl::get_height() {
  return height;
}

void UnknoterImpl::reset(int players, int width_, int height_) {
  width = width_;
  height = height_;
  coords_to_player.assign(2 * width + 1, std::vector<int>(2 * height + 1, -1));

  auto field = get_field();
  int i = 0;
  for (const auto& player_edges: field) {
    for (const auto& edge: player_edges) {
      if (i < players) {
        coords_to_player[edge.first][edge.second] = i;
      }
    }
    ++i;
  }
  for (int x = 0; x <= 2 * width; x += 2) {
    for (int y = 0; y <= 2 * height; y += 2) {
      std::vector<int> players;
      auto check_edge = [&](int x, int y) {
        if (x < 0 || x > 2 * width || y < 0 || y > 2 * height) {
          return;
        }
        if (coords_to_player[x][y] != -1) {
          players.push_back(coords_to_player[x][y]);
        }
      };
      check_edge(x - 1, y);
      check_edge(x + 1, y);
      check_edge(x, y - 1);
      check_edge(x, y + 1);
      if (players.size() == 4) {
        coords_to_player[x][y] = players[rand() % players.size()];
      }
    }
  }
}

int UnknoterImpl::get_edge_player(int x, int y) {
  return coords_to_player[x][y];
}

int UnknoterImpl::get_upper_vertex_player(int x, int y) {
  return coords_to_player[x][y];
}

int UnknoterImpl::get_lower_vertex_player(int x, int y) {
  auto upper = get_upper_vertex_player(x, y);
  if (upper == -1) {
    return -1;
  }
  std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (auto [dx, dy]: dirs) {
    auto x1 = x + dx;
    auto y1 = y + dy;
    if (x1 < 0 || x1 > 2 * width || y1 < 0 || y1 > 2 * height) {
      continue;
    }
    int maybe_lower = coords_to_player[x1][y1];
    if (maybe_lower != -1 && maybe_lower != upper) {
      return maybe_lower;
    }
  }
  return -1;
}

bool UnknoterImpl::can_player_flip_vertex(int player, int x, int y) {
  return get_upper_vertex_player(x, y) == player || get_lower_vertex_player(x, y) == player;
}

bool is_edge_alt(int x, int y) {
  return x & 1;
}

bool UnknoterImpl::can_player_shift_edges(int player, int x, int y, int select_offset, int perpendicular_offset) {
  // TODO: implement perpendicular_offset != 0 case
  if (get_edge_player(x, y) != player) {
    return false;
  }
  int sign = (select_offset > 0) - (select_offset < 0);
  int sign_perpendicular = (perpendicular_offset > 0) - (perpendicular_offset < 0);
  if (select_offset != 0) {
    for (int i = sign; i != select_offset + sign; i += sign) {
      int x1 = x;
      int y1 = y;
      if (is_edge_alt(x, y)) {
        x1 += 2 * i;
      } else {
        y1 += 2 * i;
      }
      if (get_edge_player(x1, y1) != player) {
        return false;
      }
    }
  }
  if (perpendicular_offset != 0) {
    int i = 0;
    do {
      int x1 = x;
      int y1 = y;
      if (is_edge_alt(x, y)) {
        x1 += 2 * i;
        y1 += 2 * perpendicular_offset;
      } else {
        x1 += 2 * perpendicular_offset;
        y1 += 2 * i;
      }
      if (get_edge_player(x1, y1) != -1) {
        return false;
      }
      i += sign;
    }
    while (i != select_offset + sign);
    for (int j = sign_perpendicular; j != perpendicular_offset + sign_perpendicular; j += sign_perpendicular) {
      int x1 = x;
      int y1 = y;
      int x2, y2;
      if (is_edge_alt(x, y)) {
        if (sign > 0) {
          x1 -= 1;
          y1 += j;
          x2 = x1 + 2 * (select_offset + 1);
        } else {
          x2 = x + 1;
          x1 = x2 + 2 * (select_offset + 1);
        }
        y1 += j;
        y2 = y1;
      } else {
        if (sign > 0) {
          y1 -= 1;
          y2 = y1 + 2 * (select_offset + 1);
        } else {
          y2 = y + 1;
          y1 = y2 + 2 * (select_offset + 1);
        }
        x1 += j;
        x2 = x1;
      }
      if ((get_edge_player(x1, y1) != -1 && get_edge_player(x1, y1) != player) || (get_edge_player(x2, y2) != -1 && get_edge_player(x2, y2) != player)) {
        return false;
      }
    }
  }
  return true;
}

void UnknoterImpl::flip_vertex(int x, int y) {
  coords_to_player[x][y] = get_lower_vertex_player(x, y);
}

void UnknoterImpl::shift_edges(int x, int y, int select_offset, int perpendicular_offset) {
  int sign_select = (select_offset > 0) - (select_offset < 0);
  int sign_perpendicular = (perpendicular_offset > 0) - (perpendicular_offset < 0);

  if (sign_select != 0) {
    for (int i = sign_select; i != select_offset + sign_select; i += sign_select) {
      int x1 = x + i * !is_edge_alt(x, y);
      int y1 = y + i * is_edge_alt(x, y);
      coords_to_player[x1][y1] = get_edge_player(x, y);
      if (i != select_offset) {
        coords_to_player[x - (i - sign_select) * !is_edge_alt(x, y)][y - (i - sign_select) * is_edge_alt(x, y)] = -1; 
      }
    }
  }
  if (sign_perpendicular != 0) {
    for (int i = sign_perpendicular; i != perpendicular_offset + sign_perpendicular; i += sign_perpendicular) {
      int x1 = x;
      int y1 = y;
      if (is_edge_alt(x, y)) {
        y1 += 2 * i;
      } else {
        x1 += 2 * i;
      }
      coords_to_player[x1][y1] = get_edge_player(x, y);
      if (i != select_offset) {
        coords_to_player[x - (i - sign_select) * !is_edge_alt(x, y)][y - (i - sign_select) * is_edge_alt(x, y)] = -1; 
      }
      if (i != perpendicular_offset) {
        coords_to_player[x][y - (i - sign_perpendicular)] = -1; 
      }
    }
  }
}
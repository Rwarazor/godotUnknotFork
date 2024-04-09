#include "unknoterImpl.h"
#include "core/io/file_access.h"

#include <iostream>

std::vector<std::vector<std::pair<int, int>>> get_field() {
  return {
    {{38, 27}, {37, 26}, {38, 29}, {11, 28}, {13, 28}, {15, 28}, {17, 28}, {19, 28}, {21, 28}, {23, 28}, {25, 28}, {27, 28}, {29, 28}, {35, 32}, {38, 31}, {37, 32}, {7, 28}, {7, 34}, {9, 28}, {9, 34}, {11, 34}, {13, 34}, {15, 34}, {17, 34}, {19, 34}, {21, 34}, {23, 34}, {25, 34}, {27, 34}, {29, 34}, {31, 34}, {34, 33}, {33, 34}, {2, 29}, {3, 28}, {2, 31}, {2, 33}, {3, 34}, {5, 28}, {5, 34}, {30, 1}, {31, 0}, {30, 3}, {30, 5}, {30, 7}, {30, 9}, {30, 11}, {30, 13}, {30, 15}, {30, 17}, {30, 19}, {30, 21}, {30, 23}, {30, 25}, {30, 27}, {33, 0}, {36, 1}, {35, 0}, {36, 3}, {36, 5}, {36, 7}, {36, 9}, {36, 11}, {36, 13}, {36, 15}, {36, 17}, {36, 19}, {36, 21}, {36, 23}, {36, 25}},
    {{14, 1}, {15, 0}, {15, 10}, {17, 0}, {17, 10}, {19, 0}, {19, 10}, {21, 0}, {23, 0}, {25, 0}, {28, 1}, {27, 0}, {0, 3}, {1, 2}, {0, 5}, {0, 7}, {0, 9}, {1, 10}, {3, 2}, {3, 10}, {5, 2}, {5, 10}, {7, 2}, {7, 10}, {9, 2}, {9, 10}, {11, 2}, {11, 10}, {13, 2}, {13, 10}, {21, 10}, {23, 10}, {29, 2}, {29, 10}, {31, 2}, {31, 10}, {33, 2}, {33, 10}, {35, 2}, {35, 10}, {37, 2}, {37, 10}, {40, 3}, {39, 2}, {40, 5}, {40, 7}, {40, 9}, {39, 10}, {24, 11}, {24, 13}, {24, 15}, {24, 17}, {24, 19}, {24, 21}, {24, 23}, {24, 25}, {24, 27}, {24, 29}, {24, 31}, {24, 33}, {24, 35}, {24, 37}, {24, 39}, {25, 40}, {28, 11}, {28, 13}, {28, 15}, {28, 17}, {28, 19}, {28, 21}, {28, 23}, {28, 25}, {28, 27}, {28, 29}, {28, 31}, {28, 33}, {28, 35}, {28, 37}, {28, 39}, {27, 40}},
    {{9, 0}, {8, 17}, {8, 19}, {8, 21}, {8, 23}, {8, 25}, {10, 25}, {8, 27}, {10, 27}, {8, 29}, {10, 29}, {8, 31}, {10, 31}, {9, 32}, {2, 15}, {3, 14}, {3, 16}, {5, 14}, {5, 16}, {7, 16}, {11, 24}, {13, 8}, {13, 24}, {15, 8}, {15, 24}, {17, 8}, {17, 24}, {19, 8}, {19, 24}, {21, 8}, {21, 24}, {23, 8}, {23, 24}, {25, 8}, {25, 24}, {27, 8}, {27, 24}, {29, 8}, {29, 24}, {31, 8}, {31, 24}, {33, 8}, {33, 24}, {35, 8}, {35, 24}, {38, 9}, {37, 8}, {38, 11}, {38, 13}, {38, 15}, {38, 17}, {38, 19}, {38, 21}, {38, 23}, {37, 24}, {6, 1}, {7, 0}, {6, 3}, {6, 5}, {6, 7}, {6, 9}, {6, 11}, {6, 13}, {12, 1}, {11, 0}, {12, 3}, {12, 5}, {12, 7}},
    {{14, 5}, {15, 4}, {14, 7}, {14, 9}, {14, 11}, {14, 13}, {14, 15}, {14, 17}, {14, 19}, {14, 21}, {14, 23}, {14, 25}, {14, 27}, {14, 29}, {14, 31}, {15, 32}, {18, 5}, {17, 4}, {18, 7}, {18, 9}, {18, 11}, {18, 17}, {18, 19}, {18, 21}, {18, 23}, {18, 25}, {18, 27}, {18, 29}, {18, 31}, {17, 32}, {19, 16}, {23, 16}, {20, 5}, {22, 5}, {21, 4}, {20, 7}, {22, 7}, {20, 9}, {22, 9}, {20, 11}, {22, 11}, {20, 17}, {22, 17}, {20, 19}, {22, 19}, {20, 21}, {22, 21}, {20, 23}, {20, 25}, {20, 27}, {20, 29}, {20, 31}, {20, 33}, {20, 35}, {20, 37}, {21, 38}, {23, 22}, {23, 38}, {25, 22}, {25, 38}, {27, 22}, {27, 38}, {29, 22}, {29, 38}, {31, 22}, {31, 38}, {33, 22}, {33, 38}, {35, 22}, {35, 38}, {37, 22}, {37, 38}, {40, 23}, {39, 22}, {40, 25}, {40, 27}, {40, 29}, {40, 31}, {40, 33}, {40, 35}, {40, 37}, {39, 38}, {19, 12}, {23, 12}, {25, 12}, {25, 16}, {27, 12}, {27, 16}, {29, 12}, {29, 16}, {31, 12}, {31, 16}, {34, 13}, {33, 12}, {34, 15}, {33, 16}}
  };
}

void set_preset_field(int players, int width, int height, std::vector<std::vector<int>>& field) {
  if (width != 20 || height != 20) {
    return;
  }
  auto preset = get_field();
  int i = 0;
  for (const auto& player_edges: preset) {
    for (const auto& edge: player_edges) {
      if (i < players) {
        field[edge.first][edge.second] = i;
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
        if (field[x][y] != -1) {
          players.push_back(field[x][y]);
        }
      };
      check_edge(x - 1, y);
      check_edge(x + 1, y);
      check_edge(x, y - 1);
      check_edge(x, y + 1);
      if (players.size() == 4) {
        field[x][y] = players[rand() % players.size()];
      }
    }
  }
}

void UnknoterImpl::_set_field(const std::vector<std::vector<int>>& field) {
  coords_to_player = field;
}


int UnknoterImpl::get_players() {
  return players;
}

void UnknoterImpl::set_current_player(int player) {
  current_player = player;
}

int UnknoterImpl::get_current_player() {
  return current_player;
}

int UnknoterImpl::get_width() {
  return width;
}

int UnknoterImpl::get_height() {
  return height;
}

void UnknoterImpl::reset(int players_, int width_, int height_) {
  players = players_;
  current_player = 0;
  width = width_;
  height = height_;
  coords_to_player.assign(2 * width + 1, std::vector<int>(2 * height + 1, -1));
  set_preset_field(players, width, height, coords_to_player);
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
      int x1, y1, x2, y2;
      if (is_edge_alt(x, y)) {
        x1 = x;
        x2 = x1;
        y1 = y - sign_perpendicular + 2 * j;
        y2 = y1;
        if (sign > 0) {
          x1 -= 1;
          x2 = x1 + 2 * (select_offset + 1);
        } else if (sign < 0) {
          x2 = x + 1;
          x1 = x2 + 2 * (select_offset + 1);
        }
      } else {
        x1 = x - sign_perpendicular + 2 * j;
        y1 = y;
        y2 = y1;
        x2 = x1;
        if (sign > 0) {
          y1 -= 1;
          y2 = y1 + 2 * (select_offset + 1);
        } else if (sign < 0) {
          y2 = y + 1;
          y1 = y2 + 2 * (select_offset + 1);
        } else {
          y1 -= 1;
          y2 += 1;
        }
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

const int SCHEMA = 1;
Error UnknoterImpl::save(const String &p_path) {
  Error err;
  Ref<FileAccess> file = FileAccess::open(p_path, FileAccess::WRITE, &err);

  if (err) {
    return err;
  }

  file->store_32(SCHEMA);

  file->store_8(players);
  file->store_8(current_player);
  file->store_8(width);
  file->store_8(height);
  for (int x = 0; x <= 2 * width; ++x) {
    for (int y = 0; y <= 2 * height; ++y) {
      file->store_8(coords_to_player[x][y]);
    }
  }

  return OK;
}

Error UnknoterImpl::load(const String &p_path) {
  Error err;
  Ref<FileAccess> file = FileAccess::open(p_path, FileAccess::READ, &err);

  if (err) {
    return err;
  }
  int schema = file->get_32();
  if (schema == 1) {
    players = file->get_8();
    current_player = file->get_8();
    width = file->get_8();
    height = file->get_8();
    coords_to_player.assign(2 * width + 1, std::vector<int>(2 * height + 1, -1));
    for (int x = 0; x <= 2 * width; ++x) {
      for (int y = 0; y <= 2 * height; ++y) {
        coords_to_player[x][y] = file->get_8();
        if (coords_to_player[x][y] == 255)
          coords_to_player[x][y] = -1;
      }
    }
  } else {
    return Error::ERR_CANT_RESOLVE;
  }
  return Error::OK;
}

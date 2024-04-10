#include "unknoterNode.h"

#include <map>
#include <vector>

class UnknoterImpl {
  std::vector<std::vector<int>> coords_to_player;
  std::map<String, int> params_ = {
    {"players", 0},
    {"virtual_players", 0},
    {"current_player", 0},
    {"width", 0},
    {"height", 0},
  };

public:
  void reset();

  int get_edge_player(int x, int y);
  int get_upper_vertex_player(int x, int y);
  int get_lower_vertex_player(int x, int y);

  int get_param(String key);
  void set_param(String key, int val);

  bool can_player_flip_vertex(int player, int x, int y);
  bool can_player_shift_edges(int player, int x, int y, int select_offset, int perpendicular_offset);

  void flip_vertex(int x, int y);
  void shift_edges(int x, int y, int select_offset, int perpendicular_offset);

  bool has_player_won(int player);

  void _set_field(const std::vector<std::vector<int>>& field);
  std::vector<std::vector<int>> _get_field();

  Error save(const String &p_path);
  Error load(const String &p_path);
};

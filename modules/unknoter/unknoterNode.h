#pragma once

#include "scene/main/node.h"

#include <memory>

class UnknoterImpl;

class UnknoterNode : public Node {
	GDCLASS(UnknoterNode, Node);

  std::unique_ptr<UnknoterImpl> impl_;
protected:
  static void _bind_methods();

public:
  UnknoterNode();
  ~UnknoterNode();

  void reset();

  int get_param(String key);
  void set_param(String key, int val);

  int get_edge_player(int x, int y);
  int get_upper_vertex_player(int x, int y);
  int get_lower_vertex_player(int x, int y);

  bool can_player_flip_vertex(int player, int x, int y);
  bool can_player_shift_edges(int player, int x, int y, int select_offset, int perpendicular_offset);

  void flip_vertex(int x, int y);
  void shift_edges(int x, int y, int select_offset, int perpendicular_offset);

  bool has_player_won(int player);

  Error save(const String &path);
  Error load(const String &path);
};

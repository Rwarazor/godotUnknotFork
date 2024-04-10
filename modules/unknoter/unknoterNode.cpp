#include "unknoterImpl.h"

void UnknoterNode::_bind_methods(){
  ClassDB::bind_method(D_METHOD("reset"), &UnknoterNode::reset);
  ClassDB::bind_method(D_METHOD("get_param", "key"), &UnknoterNode::get_param);
  ClassDB::bind_method(D_METHOD("set_param", "key", "val"), &UnknoterNode::set_param);
  ClassDB::bind_method(D_METHOD("get_edge_player", "x", "y"), &UnknoterNode::get_edge_player);
  ClassDB::bind_method(D_METHOD("get_upper_vertex_player", "x", "y"), &UnknoterNode::get_upper_vertex_player);
  ClassDB::bind_method(D_METHOD("get_lower_vertex_player", "x", "y"), &UnknoterNode::get_lower_vertex_player);
  ClassDB::bind_method(D_METHOD("can_player_flip_vertex", "player", "x", "y"), &UnknoterNode::can_player_flip_vertex);
  ClassDB::bind_method(D_METHOD("can_player_shift_edges", "player", "x", "y", "select_offset", "perpendicular_offset"), &UnknoterNode::can_player_shift_edges);
  ClassDB::bind_method(D_METHOD("flip_vertex", "x", "y"), &UnknoterNode::flip_vertex);
  ClassDB::bind_method(D_METHOD("shift_edges", "x", "y", "select_offset", "perpendicular_offset"), &UnknoterNode::shift_edges);
  ClassDB::bind_method(D_METHOD("save", "path"), &UnknoterNode::save);
  ClassDB::bind_method(D_METHOD("load", "path"), &UnknoterNode::load);
}

UnknoterNode::UnknoterNode()
  : impl_(new UnknoterImpl())
{}

UnknoterNode::~UnknoterNode() = default;

void UnknoterNode::reset() {
  impl_->reset();
}

int UnknoterNode::get_param(String key) {
  return impl_->get_param(key);
}

void UnknoterNode::set_param(String key, int val) {
  return impl_->set_param(key, val);
}

int UnknoterNode::get_edge_player(int x, int y) {
  return impl_->get_edge_player(x, y);
}

int UnknoterNode::get_upper_vertex_player(int x, int y) {
  return impl_->get_upper_vertex_player(x, y);
}

int UnknoterNode::get_lower_vertex_player(int x, int y) {
  return impl_->get_lower_vertex_player(x, y);
}

bool UnknoterNode::can_player_flip_vertex(int player, int x, int y) {
  return impl_->can_player_flip_vertex(player, x, y);
}

bool UnknoterNode::can_player_shift_edges(int player, int x, int y, int select_offset, int perpendicular_offset) {
  return impl_->can_player_shift_edges(player, x, y, select_offset, perpendicular_offset);
}

void UnknoterNode::flip_vertex(int x, int y) {
  impl_->flip_vertex(x, y);
}

void UnknoterNode::shift_edges(int x, int y, int select_offset, int perpendicular_offset) {
  impl_->shift_edges(x, y, select_offset, perpendicular_offset);
}

Error UnknoterNode::save(const String &path) {
  return impl_->save(path);
}

Error UnknoterNode::load(const String &path) {
  return impl_->load(path);
}

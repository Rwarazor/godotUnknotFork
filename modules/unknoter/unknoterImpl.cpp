#include "unknoterImpl.h"
#include "core/io/file_access.h"

#include <iostream>

void UnknoterImpl::_set_field(const std::vector<std::vector<int>>& field) {
  coords_to_player = field;
}

std::vector<std::vector<int>> UnknoterImpl::_get_field() {
  return coords_to_player;
}

int UnknoterImpl::get_param(String key) {
  if (params_.count(key) == 0) {
    return -1;
  }
  return params_[key];
}

void UnknoterImpl::set_param(String key, int val) {
  if (params_.count(key) == 0) {
    return;
  }
  params_[key] = val;
}

void UnknoterImpl::reset() {
  int virtual_players = params_["virtual_players"];
  int players = params_["players"];
  int width = params_["width"];
  int height = params_["height"];
  coords_to_player.assign(2 * width + 1, std::vector<int>(2 * height + 1, -1));
  if (width != 20 || height != 20) {
    return;
  }
  if (players == 3) {
    _set_field({
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  2, -1,  2,  0,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1,  1, -1,  1,  2,  1, -1,  1, -1,  1,  1,  1, -1,  1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1,  0, -1,  0, -1,  0,  1,  0, -1,  0, -1,  0,  0,  0, -1,  0, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1,  2, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2, -1,  2,  2,  2, -1,  2, -1,  2, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    });
    return;
  }
  _set_field({
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
  });
  for (int x = 0; x <= 2 * width; x += 1) {
    for (int y = 0; y <= 2 * height; y += 1) {
      if (coords_to_player[x][y] >= players + virtual_players) {
        coords_to_player[x][y] = -1;
      }
    }
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
  int width = params_["width"];
  int height = params_["height"];
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
  int width = params_["width"];
  int height = params_["height"];
  auto out_of_bounds = [&](int x1, int y1) {
    return x1 < 0 || x1 > 2 * width || y1 < 0 || y1 > 2 * height;
  };
  if (get_edge_player(x, y) != player) {
    return false;
  }
  int sign_select = (select_offset > 0) - (select_offset < 0);
  int sign_perpendicular = (perpendicular_offset > 0) - (perpendicular_offset < 0);
  int i = 0;
  do  {
    int x1 = x + 2 * i * is_edge_alt(x, y);
    int y1 = y + 2 * i * !is_edge_alt(x, y);
    if (get_edge_player(x1, y1) != player) {
      return false;
    }
    if (perpendicular_offset != 0) {
      int x2 = x1 + 2 * perpendicular_offset * !is_edge_alt(x, y);
      int y2 = y1 + 2 * perpendicular_offset * is_edge_alt(x, y);
      if (get_edge_player(x2, y2) != -1) {
        return false;
      }
      if (i != 0) {
        if (is_edge_alt(x, y)) {
          if (get_edge_player(x2 - sign_select, y2 - sign_perpendicular) == player) {
            return false;
          }
        } else {
          if (get_edge_player(x2 - sign_perpendicular, y2 - sign_select) == player) {
            return false;
          }
        }
      }
    }
    i += sign_select;
  } while (i != select_offset + sign_select);

  bool deleting1 = true, deleting2 = true;
  for (int j = sign_perpendicular; j != perpendicular_offset + 2 * sign_perpendicular; j += sign_perpendicular) {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    if (is_edge_alt(x, y)) {
      x1 = std::min(x, x + 2 * select_offset) - 1;
      x2 = std::max(x, x + 2 * select_offset) + 1;
      y1 = y - sign_perpendicular + 2 * j;
      y2 = y1;

      x3 = x1 + 1;
      y3 = y + 2 * j;
      x4 = x2 - 1;
      y4 = y + 2 * j;
    } else {
      x1 = x - sign_perpendicular + 2 * j;
      x2 = x1;
      y1 = std::min(y, y + 2 * select_offset) - 1;
      y2 = std::max(y, y + 2 * select_offset) + 1;

      x3 = x + 2 * j;
      y3 = y1 + 1;
      x4 = x + 2 * j;
      y4 = y2 - 1;
    }
    if (out_of_bounds(x1, y1) || out_of_bounds(x2, y2)) {
      break;
    }
    if (deleting1) {
      if (get_edge_player(x1, y1) == -1) {
        deleting1 = false;
      } else if (get_edge_player(x1, y1) != player) {
        return false;
      }
    } else if (get_edge_player(x1, y1) != -1) {
        return false;
    }
    if (j != perpendicular_offset + sign_perpendicular &&
      !deleting1 &&
      get_edge_player(x3, y3) == player)
    {
      return false;
    }
    if (deleting2) {
      if (get_edge_player(x2, y2) == -1) {
        deleting2 = false;
      } else if (get_edge_player(x2, y2) != player) {
        return false;
      }
    } else if (get_edge_player(x2, y2) != -1) {
        return false;
    }
    if (j != perpendicular_offset + sign_perpendicular &&
      !deleting2 &&
      get_edge_player(x4, y4) == player)
    {
      return false;
    }
  }
  return true;
}

void UnknoterImpl::flip_vertex(int x, int y) {
  coords_to_player[x][y] = get_lower_vertex_player(x, y);
}

void UnknoterImpl::shift_edges(int x, int y, int select_offset, int perpendicular_offset) {
  if (perpendicular_offset == 0) {
    return;
  }
  int sign_select = (select_offset > 0) - (select_offset < 0);
  int sign_perpendicular = (perpendicular_offset > 0) - (perpendicular_offset < 0);
  auto player = get_edge_player(x, y);
  int i = 0;
  do  {
    int x1 = x + 2 * i * is_edge_alt(x, y);
    int y1 = y + 2 * i * !is_edge_alt(x, y);
    // clear intersection when removing edge
    coords_to_player[x1 / 2 * 2][y1 / 2 * 2] = -1;
    coords_to_player[x1][y1] = -1;
    int x2 = x1 + 2 * perpendicular_offset * !is_edge_alt(x, y);
    int y2 = y1 + 2 * perpendicular_offset * is_edge_alt(x, y);
    coords_to_player[x2][y2] = player;
    if (i != 0) {
      if (is_edge_alt(x, y)) {
        int other_player = get_edge_player(x2 - sign_select, y2 - sign_perpendicular);
        if (other_player != -1) {
          coords_to_player[x2 - sign_select][y2] = player;
        }
      } else {
        if (get_edge_player(x2 - sign_perpendicular, y2 - sign_select) != -1) {
          coords_to_player[x2][y2 - sign_select] = player;
        }
      }
    }
    i += sign_select;
  } while (i != select_offset + sign_select);

  bool deleting1 = true, deleting2 = true;
  for (int j = sign_perpendicular; j != perpendicular_offset + sign_perpendicular; j += sign_perpendicular) {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    if (is_edge_alt(x, y)) {
      x1 = std::min(x, x + 2 * select_offset) - 1;
      x2 = std::max(x, x + 2 * select_offset) + 1;
      y1 = y - sign_perpendicular + 2 * j;
      y2 = y1;

      x3 = x1 + 1;
      y3 = y + 2 * j;
      x4 = x2 - 1;
      y4 = y + 2 * j;
    } else {
      x1 = x - sign_perpendicular + 2 * j;
      x2 = x1;
      y1 = std::min(y, y + 2 * select_offset) - 1;
      y2 = std::max(y, y + 2 * select_offset) + 1;

      x3 = x + 2 * j;
      y3 = y1 + 1;
      x4 = x + 2 * j;
      y4 = y2 - 1;
    }
    if (get_edge_player(x1, y1) == -1) {
      deleting1 = false;
    }
    if (coords_to_player[x1][y1] == -1) {
      coords_to_player[x1][y1] = player;
    } else{
      coords_to_player[x1][y1] = -1;
      // clear intersection when removing edge
      coords_to_player[x1 / 2 * 2][y1 / 2 * 2] = -1;
    }
    if (j != perpendicular_offset &&
      !deleting1 &&
      get_edge_player(x3, y3) != -1)
    {
      coords_to_player[x3 - is_edge_alt(x, y)][y3 - !is_edge_alt(x, y)] = player;
    }
    if (get_edge_player(x2, y2) == -1) {
      deleting2 = false;
    }
    if (coords_to_player[x2][y2] == -1) {
      coords_to_player[x2][y2] = player;
    } else{
      coords_to_player[x2][y2] = -1;
      // clear intersection when removing edge
      coords_to_player[x2 / 2 * 2][y2 / 2 * 2] = -1;
    }
    if (j != perpendicular_offset &&
      !deleting2 &&
      get_edge_player(x4, y4) != -1)
    {
      coords_to_player[x4 + is_edge_alt(x, y)][y4 + !is_edge_alt(x, y)] = player;
    }
  }
}

bool UnknoterImpl::has_player_won(int player) {
  int width = params_["width"];
  int height = params_["height"];
  for (int x = 0; x <= 2 * width; x += 2) {
    for (int y = 0; y <= 2 * height; y += 2) {
      if (get_lower_vertex_player(x, y) == player || get_upper_vertex_player(x, y) == player) {
        return false;
      }
    }
  }
  return true;
}

const int SCHEMA = 1;
Error UnknoterImpl::save(const String &p_path) {
  int width = params_["width"];
  int height = params_["height"];
  Error err;
  Ref<FileAccess> file = FileAccess::open(p_path, FileAccess::WRITE, &err);

  if (err) {
    return err;
  }

  file->store_32(SCHEMA);

  file->store_8(params_["players"]);
  file->store_8(params_["virtual_players"]);
  file->store_8(params_["current_player"]);
  file->store_8(width);
  file->store_8(height);
  file->store_32(params_["energy1"]);
  file->store_32(params_["energy2"]);
  file->store_32(params_["energy3"]);
  file->store_32(params_["energy4"]);
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
    params_["players"] = file->get_8();
    params_["virtual_players"] = file->get_8();
    params_["current_player"] = file->get_8();
    int width = params_["width"] = file->get_8();
    int height = params_["height"] = file->get_8();
    params_["energy1"] = file->get_32();
    params_["energy2"] = file->get_32();
    params_["energy3"] = file->get_32();
    params_["energy4"] = file->get_32();
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

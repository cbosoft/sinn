#include "output_layer.hpp"

std::vector<double> OutputLayer::get_output()
{
  std::vector<double> rv;

  for (auto n : this->neurons)
    rv.push_back(n->get_value());

  return rv;
}

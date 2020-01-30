#include "output_layer.hpp"

namespace sinn {

  std::vector<double> OutputLayer::get_output()
  {
    std::vector<double> rv;
  
    for (auto n : this->neurons)
      rv.push_back(n->get_value());
  
    return rv;
  }

} //namespace sinn

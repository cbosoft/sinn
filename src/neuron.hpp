#pragma once

#include <vector>

namespace sinn {

  class Neuron {
  
    public:
  
      Neuron() =default;
      virtual ~Neuron() =default;
  
      virtual double get_value() =0;
  };

} // namespace sinn

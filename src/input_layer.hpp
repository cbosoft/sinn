#pragma once

#include "input_neuron.hpp"
#include "layer.hpp"

namespace sinn {

  class InputLayer : public virtual Layer {
  
    public:
  
      InputLayer(std::vector<double> input_values);
      InputLayer(int n);
      ~InputLayer() =default;
  
      void generate_neurons(std::vector<double> input_values);
      void generate_neurons(int n);
      void set_values(std::vector<double> input_values);
  };

} // namespace sinn

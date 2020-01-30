#pragma once

#include "hidden_neuron.hpp"
#include "layer.hpp"

namespace sinn {

  class HiddenLayer : public Layer {
  
    public:
  
      HiddenLayer(int n);
      ~HiddenLayer() =default;
  
  
      void generate_neurons(int n);
  
  };

} // namespace sinn

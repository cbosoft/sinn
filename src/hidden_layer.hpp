#pragma once

#include "hidden_neuron.hpp"
#include "layer.hpp"

class HiddenLayer : public virtual Layer {

  public:

    HiddenLayer(int n);
    ~HiddenLayer() =default;


    void generate_neurons(int n);

};

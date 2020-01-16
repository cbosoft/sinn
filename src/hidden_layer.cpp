#include "hidden_layer.hpp"

HiddenLayer::HiddenLayer(int n)
{
  this->generate_neurons(n);
}

void HiddenLayer::generate_neurons(int n)
{
  this->clear_neurons();
  for (int i = 0; i < n; i++) {
    this->neurons.push_back(new HiddenNeuron());
  }
}

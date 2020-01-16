#include "input_layer.hpp"


InputLayer::InputLayer(std::vector<double> input_values)
{
  this->generate_neurons(input_values);
}


void InputLayer::generate_neurons(std::vector<double> input_values)
{
  for (auto value : input_values)
  {
    InputNeuron *n = new InputNeuron(value);
    this->add_neuron(n);
  }
}

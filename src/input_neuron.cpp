#include "input_neuron.hpp"

InputNeuron::InputNeuron(double value)
{
  this->value = value;
}

double InputNeuron::get_value()
{
  return this->value;
}

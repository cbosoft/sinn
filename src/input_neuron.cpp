#include "input_neuron.hpp"

namespace sinn {

  InputNeuron::InputNeuron(double value)
  {
    this->value = value;
  }
  
  double InputNeuron::get_value()
  {
    return this->value;
  }
  
  void InputNeuron::set_value(double value)
  {
    this->value = value;
  }

} // namespace sinn

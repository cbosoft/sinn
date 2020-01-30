#include "input_layer.hpp"

namespace sinn {

  InputLayer::InputLayer(std::vector<double> input_values)
  {
    this->generate_neurons(input_values);
  }
  
  InputLayer::InputLayer(int n)
  {
    this->generate_neurons(n);
  }
  
  
  void InputLayer::generate_neurons(std::vector<double> input_values)
  {
    for (auto value : input_values) {
      InputNeuron *n = new InputNeuron(value);
      this->add_neuron(n);
    }
  }
  
  
  void InputLayer::generate_neurons(int n)
  {
    for (int i = 0; i < n; i++) {
      InputNeuron *n = new InputNeuron(0.0);
      this->add_neuron(n);
    }
  }

} // namespace sinn

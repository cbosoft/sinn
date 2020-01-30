#include "layer.hpp"

namespace sinn {

  Layer::~Layer()
  {
    this->clear_neurons();
  }
  
  
  void Layer::add_neuron(Neuron *neuron)
  {
    this->neurons.push_back(neuron);
  }
  
  
  void Layer::clear_neurons()
  {
    for (auto neuron: this->neurons) {
      delete neuron;
    }
  }

} // namespace sinn

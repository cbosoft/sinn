#include <iostream>
#include <iomanip>
#include <sstream>

#include "neural_network.hpp"


void NeuralNetwork::print()
{

  size_t neuron_index = 0;
  bool finished = false;
  const int col_width = 10;

  for (size_t layer_index = 0; layer_index < this->layers.size(); layer_index++) {
    std::stringstream ss;
    ss << "Layer " << layer_index;
    std::cout << std::setw(col_width) << ss.str() << "  ";
  }
  std::cout << std::endl;

  while (!finished) {

    finished = true;
    for (auto layer: this->layers)
      if (neuron_index < layer->neurons.size())
        finished = false;

    if (finished)
      break;

    for (auto layer : this->layers) {
      if (neuron_index < layer->neurons.size()) {
        std::cout << std::setw(col_width) << layer->neurons[neuron_index]->get_value() << "  ";
      }
      else {
        std::cout << std::setw(col_width) << "-" << "  ";
      }
    }
    neuron_index++;
    std::cout << std::endl << std::endl;
  }
}

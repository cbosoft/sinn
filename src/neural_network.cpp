#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "hidden_neuron.hpp"
#include "neural_network.hpp"
#include "input_neuron.hpp"


NeuralNetwork::NeuralNetwork()
{
  this->last_error = 100.0;
}


void NeuralNetwork::add_layer(Layer *layer)
{
  this->layers.push_back(layer);

  size_t nlayers = this->layers.size();
  if (nlayers > 1) {
    for (auto previous : this->layers[nlayers-2]->neurons) {
      for (auto latest : this->layers[nlayers-1]->neurons) {
        
        ((HiddenNeuron *)latest)->add_weighted_input(previous, 0.1);
      }
    }
  }
} 

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



double NeuralNetwork::get_last_error()
{
  return this->last_error;
}



void NeuralNetwork::set_input(std::vector<double> input)
{
  for (size_t i = 0; i < input.size(); i++) {
    ((InputNeuron *)this->layers[0]->neurons[i])->set_value(input[i]);
  }
}



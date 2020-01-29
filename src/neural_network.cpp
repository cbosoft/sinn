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



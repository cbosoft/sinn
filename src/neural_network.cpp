#include <iostream>
#include <sstream>
#include <fstream>

#include "util.hpp"
#include "exception.hpp"
#include "hidden_neuron.hpp"
#include "neural_network.hpp"
#include "input_neuron.hpp"
#include "output_layer.hpp"

namespace sinn {
  NeuralNetwork::NeuralNetwork()
  {
    this->last_error = 100.0;
  }

  void NeuralNetwork::add_layer_weighted(Layer *layer, double weight)
  {
    this->layers.push_back(layer);

    size_t nlayers = this->layers.size();
    if (nlayers > 1) {
      for (auto previous : this->layers[nlayers-2]->neurons) {
        for (auto latest : this->layers[nlayers-1]->neurons) {

          ((HiddenNeuron *)latest)->add_weighted_input(previous, weight);
        }
      }
    }
  } 

  void NeuralNetwork::add_layer_normal(Layer *layer, double mean, double stddev)
  {
    this->layers.push_back(layer);

    size_t nlayers = this->layers.size();
    if (nlayers > 1) {
      for (auto previous : this->layers[nlayers-2]->neurons) {
        for (auto latest : this->layers[nlayers-1]->neurons) {

          ((HiddenNeuron *)latest)->add_weighted_input(previous, util::get_normal_random(mean, stddev));
        }
      }
    }
  } 

  void NeuralNetwork::link_layers_weighted(int from, int to, double weight)
  {
    if (to > from) {
      throw Exception("LayerError", "Network layers can only be linked from ahead to behind ($to must be less than $from).");
    }

    int max_index = this->layers.size() - 1;
    if (from > max_index || to > max_index || from < 0 || to < 0) {
      throw Exception("LayerError", "Network layer indices given are not within acceptable range (0 - layer size).");
    }

    // Not sure if this is actually an error?
    // if (from == to) {
    //   throw Exception("LayerError", "Layer cannot be linked to itself.");
    // }

    for (auto neuron_from : this->layers[from]->neurons) {
      for (auto neuron_to : this->layers[to]->neurons) {
        ((HiddenNeuron *)neuron_to)->add_weighted_input(neuron_from, weight);
      }
    }

  }


  void NeuralNetwork::link_layers_normal(int from, int to, double mean, double stddev)
  {
    if (to > from) {
      throw Exception("LayerError", "Network layers can only be linked from ahead to behind ($to must be less than $from).");
    }

    int max_index = this->layers.size() - 1;
    if (from > max_index || to > max_index || from < 0 || to < 0) {
      throw Exception("LayerError", "Network layer indices given are not within acceptable range (0 - layer size).");
    }

    // Not sure if this is actually an error?
    // if (from == to) {
    //   throw Exception("LayerError", "Layer cannot be linked to itself.");
    // }

    for (auto neuron_from : this->layers[from]->neurons) {
      for (auto neuron_to : this->layers[to]->neurons) {
        ((HiddenNeuron *)neuron_to)->add_weighted_input(neuron_from, util::get_normal_random(mean, stddev));
      }
    }

  }


  void NeuralNetwork::link_layers_uniform(int from, int to, double min, double max)
  {
    if (to > from) {
      throw Exception("LayerError", "Network layers can only be linked from ahead to behind ($to must be less than $from).");
    }

    int max_index = this->layers.size() - 1;
    if (from > max_index || to > max_index || from < 0 || to < 0) {
      throw Exception("LayerError", "Network layer indices given are not within acceptable range (0 - layer size).");
    }

    // Not sure if this is actually an error?
    // if (from == to) {
    //   throw Exception("LayerError", "Layer cannot be linked to itself.");
    // }

    for (auto neuron_from : this->layers[from]->neurons) {
      for (auto neuron_to : this->layers[to]->neurons) {
        ((HiddenNeuron *)neuron_to)->add_weighted_input(neuron_from, util::get_uniform_random(min, max));
      }
    }

  }


  double NeuralNetwork::get_last_error() const
  {
    return this->last_error;
  }



  void NeuralNetwork::set_input(std::vector<double> input)
  {
    for (size_t i = 0; i < input.size(); i++) {
      ((InputNeuron *)this->layers[0]->neurons[i])->set_value(input[i]);
    }
  }


  std::vector<double> NeuralNetwork::get_output() const
  {
    std::vector<double> value = ((OutputLayer *)this->layers[this->layers.size()-1])->get_output();
    return value;
  }


  std::vector<double> NeuralNetwork::get_output(std::vector<double> input)
  {
     this->set_input(input);
     return this->get_output();
  }

} // namespace sinn

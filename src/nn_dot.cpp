#include <iostream>
#include <fstream>

#include "neural_network.hpp"


void NeuralNetwork::as_dot(std::string filename) const
{
  std::fstream of(filename, std::ios::trunc);
  of << "digraph G {" << std::endl
     << "  rankdir=LR;" << std::endl
     << "  ordering=out;" << std::endl
     << "  fontname=\"CMU Sans Serif\";" << std::endl
     << "  node [fontname=\"CMU Sans Serif\"];" << std::endl
     << "  edge [fontname=\"CMU Sans Serif\"];" << std::endl
     << "  ranksep=\"1.0 equally\";" << std::endl;
  
  for (size_t layer_index = 0; layer_index < this->layers.size(); layer_index++) {
    of << "  subgraph cluster_" << layer_index << "{" << std::endl;
    for (size_t neuron_index = 0; neuron_index < this->layers[layer_index]->neurons.size(); neuron_index++) {
      of << "    layer_" << layer_index << "_" << neuron_index << " [label=\"" << this->layers[layer_index]->neurons[neuron_index]->get_value() << "\"];" << std::endl;
    }

    of << "    label=\"";
    if (layer_index == 0) {
      of << "Input Layer";
    }
    else if (layer_index == (this->layers.size() - 1)) {
      of << "Output Layer";
    }
    else {
      of << "Hidden Layer " << layer_index;
    }
    of << "\";" << std::endl;
    of << "  }" << std::endl;
  }

  for (size_t layer_index = 1; layer_index < this->layers.size(); layer_index++) {
    for (size_t pn_index = 0; pn_index < this->layers[layer_index-1]->neurons.size(); pn_index++) {
      for (size_t n_index = 0; n_index < this->layers[layer_index]->neurons.size(); n_index++) {
        of << "  layer_" << layer_index-1 << "_" << pn_index << " -> layer_" << layer_index << "_" << n_index << ";" << std::endl;
      }
    }
  }

  of << "}" << std::endl;

}

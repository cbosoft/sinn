#pragma once

#include "neuron.hpp"
#include "activation_functions/activation_function.hpp"

namespace sinn {

  class NeuralNetwork;
  class HiddenNeuron : public Neuron {
  
    private:
  
      std::vector<Neuron *> in;
      std::vector<double> weights;
      std::vector<double> substitute_weights;
      double bias;
      double substitute_bias;
      ActivationFunction *activation_function;
  
    public:
      
      HiddenNeuron(ActivationFunction *actfunc);
      ~HiddenNeuron() =default;
  
      double get_value() override;
      void add_weighted_input(Neuron *neuron, double weight);
      void set_activation_function(ActivationFunction *activation_function);
  
      double get_bias();
      double get_substitute_bias();
      double get_weight(int);
      double get_substitute_weight(int);
      void set_bias(double);
      void set_substitute_bias(double);
      void set_weight(int, double);
      void set_substitute_weight(int, double);
      void swap_weights_and_bias();
  
      friend NeuralNetwork;
  
  };

} // namespace sinn

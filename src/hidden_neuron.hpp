#pragma once

#include "neuron.hpp"
#include "activation_function.hpp"

class HiddenNeuron : public Neuron {

  private:

    std::vector<Neuron *> in;
    std::vector<double> weights;
    ActivationFunction activation_function;
    std::vector<double> activation_func_args;

  public:
    
    HiddenNeuron();
    ~HiddenNeuron() =default;

    double get_value() override;
    void add_weighted_input(Neuron *neuron, double weight);
    void set_activation_function(ActivationFunction activation_function);

};

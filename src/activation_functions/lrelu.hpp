#pragma once

#include "activation_function.hpp"

class ActFunc_LeakyReLu : public ActivationFunction {

private:

  double lower_gradient;
  
public:

  ActFunc_LeakyReLu(double lower_gradient);
  ~ActFunc_LeakyReLu() =default;

  double calculate_value(double input);

};

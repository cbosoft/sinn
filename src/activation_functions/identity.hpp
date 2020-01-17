#pragma once

#include "activation_function.hpp"

class ActFunc_Identity : public ActivationFunction {

public:
  ~ActFunc_Identity() =default;

  double calculate_value(double input) override;
};

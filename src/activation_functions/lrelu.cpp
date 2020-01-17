#include "lrelu.hpp"

ActFunc_LeakyReLu::ActFunc_LeakyReLu(double lower_gradient)
{
  this->lower_gradient = lower_gradient;
}

double ActFunc_LeakyReLu::calculate_value(double input)
{
  if (input < 0.0)
    return this->lower_gradient*input;
  else
    return input;
}

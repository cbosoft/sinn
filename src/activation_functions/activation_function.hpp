#pragma once

#include <vector>

// double actfunc_identity(double, std::vector<double>);
// double actfunc_heaviside(double, std::vector<double>);
// double actfunc_sigmoid(double, std::vector<double>);
// double actfunc_tanh(double, std::vector<double>);
// double actfunc_relu(double, std::vector<double>);
// double actfunc_lrelu(double, std::vector<double>);
// double actfunc_prelu(double, std::vector<double>);
// double actfunc_rrelu(double, std::vector<double>);
// double actfunc_elu(double, std::vector<double>);
// double actfunc_selu(double, std::vector<double>);
// double actfunc_srelu(double, std::vector<double>);
// double actfunc_apl(double, std::vector<double>);
// double actfunc_softplus(double, std::vector<double>);
// double actfunc_bent(double, std::vector<double>);


class ActivationFunction {

public:

  virtual ~ActivationFunction() =default;

  virtual double calculate_value(double input) =0;

};

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "util.hpp"
#include "colour.hpp"

inline void test_header(std::string name)
{
  std::cerr << name << ":";
}

inline void pass_and_exit()
{
  std::cerr << " " << FG_GREEN << "PASSED" << RESET << std::endl;
  exit(0);
}

inline void fail_and_exit()
{
  std::cerr << " " << BG_RED << "FAILED" << RESET << std::endl;
  exit(1);
}

inline void test_check_and_exit(bool condition)
{
  if (condition)
    pass_and_exit();
  else
    fail_and_exit();
}

typedef double (* TrainingFunction)(int );

inline void get_training_set_from_function_uniform(TrainingFunction *f, int n, std::vector<double> &inputs, std::vector<double> &outputs, double min, double max)
{
  inputs.erase(inputs.begin(), inputs.end());
  outputs.erase(outputs.begin(), outputs.end());
  for (int i = 0; i < n; i++) {
    double v = sinn::util::get_uniform_random(min, max);
    inputs.push_back(v);
    outputs.push_back((*f)(v));
  }
}

inline void get_training_set_from_function_normal(TrainingFunction *f, int n, std::vector<double> &inputs, std::vector<double> &outputs, double mean, double stddev)
{
  inputs.erase(inputs.begin(), inputs.end());
  outputs.erase(outputs.begin(), outputs.end());
  for (int i = 0; i < n; i++) {
    double v = sinn::util::get_normal_random(mean, stddev);
    inputs.push_back(v);
    outputs.push_back((*f)(v));
  }
}

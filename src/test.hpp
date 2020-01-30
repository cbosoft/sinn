#pragma once
#include <iostream>
#include <string>
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

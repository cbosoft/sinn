#include <vector>
#include <string>

namespace sinn {

  namespace util {

    double sumsqdiff(std::vector<double> a, std::vector<double> b);
    std::string vec2string(std::vector<double> vec);
    double get_uniform_random(double, double);
    double get_normal_random(double, double);

  } // namespace util

} // namespace util

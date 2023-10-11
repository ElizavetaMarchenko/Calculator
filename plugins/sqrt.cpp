#include <cmath>

extern "C" __declspec(dllexport)
double universal_function(double x) {
    return sqrt(x);
}
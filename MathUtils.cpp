#include "MathUtils.h"
#include "pch.h"
#include <stdexcept>

namespace Utilities {

    int MathUtils::add(int a, int b) {
        return a + b;
    }

    int MathUtils::subtract(int a, int b) {
        return a - b;
    }

    int MathUtils::multiply(int a, int b) {
        return a * b;
    }

    double MathUtils::divide(int a, int b) {
        if (b == 0) throw std::invalid_argument("Division by zero");
        return static_cast<double>(a) / b;
    }

    double MathUtils::degreesToRadians(double degrees) {
        return degrees * (PI / 180.0);
    }

    double MathUtils::radiansToDegrees(double radians) {
        return radians * (180.0 / PI);
    }

    double MathUtils::clamp(double value, double min, double max) {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }

    double MathUtils::lerp(double a, double b, double t) {
        return a + t * (b - a);
    }

} // namespace SupportLib

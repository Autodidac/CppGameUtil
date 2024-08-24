#pragma once

namespace Utilities {

    class MathUtils {
    public:
        static constexpr double PI = 3.14159265358979323846;
        static constexpr double E = 2.71828182845904523536;

        static int add(int a, int b);
        static int subtract(int a, int b);
        static int multiply(int a, int b);
        static double divide(int a, int b);

        static double degreesToRadians(double degrees);
        static double radiansToDegrees(double radians);

        static double clamp(double value, double min, double max);
        static double lerp(double a, double b, double t);
    };

} // namespace Utilities

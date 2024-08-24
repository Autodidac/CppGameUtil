#pragma once

#include <random>

namespace Utilities {

    class IRandomNumberGenerator {
    public:
        virtual int getRandomInt(int min, int max) = 0;
        virtual double getRandomDouble(double min, double max) = 0;
    };

    class RandomUtils : public IRandomNumberGenerator {
    public:
        int getRandomInt(int min, int max) override;
        double getRandomDouble(double min, double max) override;
    };
} // namespace Utilities

#pragma once

#include <chrono>
#include <string>
#include <mutex>

namespace Utilities {

    class TimerBase {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void reset() = 0;
        virtual void reverse() = 0;
        virtual double elapsedMilliseconds() const = 0;
        virtual double elapsedSeconds() const = 0;
        virtual void update() = 0;  // Update the simulation time
    };

    class Timer : public TimerBase {
    public:
        Timer();
        ~Timer();
        void start() override;
        void stop() override;
        void reset() override;
        void reverse() override;
        double elapsedMilliseconds() const override;
        double elapsedSeconds() const override;
        void update() override;
        bool getIsReversed() const;

    private:
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::milliseconds accumulatedTime;
        bool isRunning;
        bool isReversed;
        mutable std::mutex timeMutex;
    };

    class DateTime {
    public:
        static std::string getCurrentTime();
        static std::string getCurrentDate();
        static std::string getCurrentDateTime();
        static std::string getCurrentDateUS();
        static std::string getCurrentDateTimeUS();
    };

} // namespace Utilities

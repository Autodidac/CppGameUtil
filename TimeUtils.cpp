#include "TimeUtils.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "pch.h"

namespace Utilities {

    // Timer implementation
    Timer::Timer()
        : isRunning(false), isReversed(false), accumulatedTime(std::chrono::milliseconds(0)) {}

    Timer::~Timer()
    {
    }

    void Timer::start() {
        std::lock_guard<std::mutex> lock(timeMutex);
        if (!isRunning) {
            isRunning = true;
            startTime = std::chrono::system_clock::now();
        }
    }

    void Timer::stop() {
        std::lock_guard<std::mutex> lock(timeMutex);
        if (isRunning) {
            isRunning = false;
            auto now = std::chrono::system_clock::now();
            accumulatedTime += std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
        }
    }

    void Timer::reset() {
        std::lock_guard<std::mutex> lock(timeMutex);
        isRunning = false;
        isReversed = false;
        accumulatedTime = std::chrono::milliseconds(0);
    }

    void Timer::reverse() {
        std::lock_guard<std::mutex> lock(timeMutex);
        isReversed = !isReversed;
    }

    bool Timer::getIsReversed() const {
        std::lock_guard<std::mutex> lock(timeMutex);
        return isReversed;
    }

    double Timer::elapsedMilliseconds() const {
        std::lock_guard<std::mutex> lock(timeMutex);
        auto elapsed_ms = accumulatedTime;
        if (isRunning) {
            auto now = std::chrono::system_clock::now();
            auto duration = (isReversed ? startTime - now : now - startTime);
            elapsed_ms += std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        }
        return std::chrono::duration<double>(elapsed_ms).count();
    }

    double Timer::elapsedSeconds() const {
        return elapsedMilliseconds() / 1000.0;
    }

    void Timer::update() {
        std::lock_guard<std::mutex> lock(timeMutex);
        if (isRunning) {
            auto now = std::chrono::system_clock::now();
            if (isReversed) {
                accumulatedTime -= std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
            }
            else {
                accumulatedTime += std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime);
            }
            startTime = now; // Update start time to current time
        }
    }

    // DateTime implementation
    std::string DateTime::getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm;
        localtime_s(&now_tm, &now_c);  // Thread-safe version
        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%H:%M:%S");
        return oss.str();
    }

    std::string DateTime::getCurrentDate() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm;
        localtime_s(&now_tm, &now_c);  // Thread-safe version
        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%d-%m-%Y");
        return oss.str();
    }

    std::string DateTime::getCurrentDateUS() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm;
        localtime_s(&now_tm, &now_c);  // Thread-safe version
        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%m-%d-%Y");
        return oss.str();
    }

    std::string DateTime::getCurrentDateTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm;
        localtime_s(&now_tm, &now_c);  // Thread-safe version
        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%d-%m-%Y %H:%M:%S");
        return oss.str();
    }

    std::string DateTime::getCurrentDateTimeUS() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm now_tm;
        localtime_s(&now_tm, &now_c);  // Thread-safe version
        std::ostringstream oss;
        oss << std::put_time(&now_tm, "%m-%d-%Y %H:%M:%S");
        return oss.str();
    }

} // namespace Utilities

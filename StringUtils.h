#pragma once

#include <string>
#include <vector>

namespace Utilities {

    class StringUtils {
    public:
        static bool startsWith(const std::string& str, const std::string& prefix);
        static bool endsWith(const std::string& str, const std::string& suffix);

        static std::string toUpperCase(const std::string& str);
        static std::string toLowerCase(const std::string& str);

        static std::vector<std::string> split(const std::string& str, char delimiter);
    };

} // namespace SupportLib

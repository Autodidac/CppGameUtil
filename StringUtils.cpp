#include "StringUtils.h"

#include <algorithm>
#include <sstream>  // Required for std::istringstream
#include "pch.h"

namespace Utilities {

    std::string StringUtils::toUpperCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }

    std::string StringUtils::toLowerCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    bool StringUtils::startsWith(const std::string& str, const std::string& prefix) {
        return str.compare(0, prefix.size(), prefix) == 0;
    }

    bool StringUtils::endsWith(const std::string& str, const std::string& suffix) {
        if (suffix.size() > str.size()) return false;
        return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    std::vector<std::string> StringUtils::split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

} // namespace Utilities

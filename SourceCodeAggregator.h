#pragma once

#include <string>
#include <vector>

namespace Utilities {

    class SourceCodeAggregator {
    public:
        static void aggregateFiles(const std::vector<std::wstring>& directories, const std::wstring& outputFilePath);
    };
}

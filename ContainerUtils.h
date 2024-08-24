#pragma once

#include <vector>

namespace Utilities {

    class ContainerUtils {
    public:
        template<typename T>
        static void removeElement(std::vector<T>& vec, const T& value);
    };

} // namespace Utilities

#include "ContainerUtils.inl"

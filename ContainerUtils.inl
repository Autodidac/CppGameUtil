
namespace Utilities {

    template<typename T>
    void ContainerUtils::removeElement(std::vector<T>& vec, const T& value) {
        vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
    }

} // namespace Utilities

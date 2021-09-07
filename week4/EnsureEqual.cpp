#include "string"

void EnsureEqual(const std::string& lhs, const std::string& rhs){
    if (lhs != rhs) {
        throw std::runtime_error(lhs + " != " + rhs);
    }
}
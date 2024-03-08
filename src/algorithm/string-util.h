#pragma once
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

namespace algorithm {

    inline std::string string_remove_spaces(const std::string& input) {
        if (input.empty()) {
            return {};
        }

        std::string output;
        std::remove_copy_if(input.cbegin(), input.cend(), std::back_inserter(output), isspace);
        return output;
    }

    inline std::string string_remove_pattern(const std::string& input, char pattern) {
        if (input.empty()) {
            return {};
        }

        std::string output;
        std::remove_copy(input.cbegin(), input.cend(), std::back_inserter(output), pattern);
        return output;
    }

    inline std::string string_join(const std::vector<std::string>& items, const std::string& separator) {
        if (items.empty()) {
            return {};
        }

        return std::accumulate(std::next(items.cbegin()), items.cend(), items[0], [&separator](auto a, auto b) { return  a + separator + b; });
    }
}
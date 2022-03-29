#pragma once

#include <cstddef>
namespace fth {

struct source_location {
    std::size_t line;
    std::size_t column;
    std::size_t offset;

    constexpr source_location(std::size_t line, std::size_t column, std::size_t offset)
        : line(line), column(column), offset(offset) {}
    constexpr bool operator==(const source_location& other) const {
        return line == other.line && column == other.column && offset == other.offset;
    }
};

} // namespace fth

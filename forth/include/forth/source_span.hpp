#pragma once

#include "forth/source_location.hpp"
namespace fth {

struct source_span {
    source_location begin;
    source_location end;

    constexpr source_span(source_location begin, source_location end) : begin(begin), end(end) {}
};

} // namespace fth

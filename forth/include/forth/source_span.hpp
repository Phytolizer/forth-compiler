#pragma once

#include "fmt/core.h"
#include "forth/source_location.hpp"

#include <ostream>
namespace fth {

struct source_span {
    source_location begin;
    source_location end;

    constexpr source_span(source_location begin, source_location end) : begin(begin), end(end) {}
};

std::ostream& operator<<(std::ostream& os, const source_span& span);

} // namespace fth

template <> struct fmt::formatter<fth::source_span> {
    constexpr auto parse(format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const fth::source_span& span, FormatContext& ctx) {
        return format_to(ctx.out(), "({}, {}) -> ({}, {})", span.begin.line + 1,
                span.begin.column + 1, span.end.line + 1, span.end.column + 1);
    }
};

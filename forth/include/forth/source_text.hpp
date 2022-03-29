#pragma once

#include "forth/source_location.hpp"
#include "forth/source_span.hpp"

#include <cstddef>
#include <string>
#include <string_view>

namespace fth {

class source_text {
    std::string m_text;

  public:
    explicit source_text(std::string&& text);

    std::string_view text() const;
    char operator[](std::size_t index) const;
    std::string_view operator[](source_span span) const;
};

} // namespace fth

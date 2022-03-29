#pragma once

#include "forth/source_span.hpp"
#include "forth/token_kind.hpp"

#include <string>
#include <string_view>

namespace fth {

class token {
    token_kind m_kind;
    source_span m_span;
    std::string m_text;

  public:
    token();
    token(token_kind kind, source_span span, std::string&& text);

    token_kind kind() const;
    source_span span() const;
    std::string_view text() const;
};

} // namespace fth

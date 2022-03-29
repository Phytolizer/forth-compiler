#pragma once

#include "fmt/core.h"
#include "fmt/format.h"
#include "forth/source_span.hpp"
#include "forth/token_kind.hpp"

#include <ostream>
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

std::ostream& operator<<(std::ostream& os, const token& token);

} // namespace fth

template <> struct fmt::formatter<fth::token> {
    constexpr auto parse(format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext> auto format(const fth::token& token, FormatContext& ctx) {
        return format_to(ctx.out(), "{{kind: {}, span: {}, text: '{}'}}",
                magic_enum::enum_name(token.kind()), token.span(), token.text());
    }
};

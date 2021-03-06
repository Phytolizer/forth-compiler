#include "forth/token.hpp"

#include "forth/token_kind.hpp"
#include "magic_enum.hpp"

fth::token::token() : m_kind(token_kind::eof), m_span({0, 0, 0}, {0, 0, 0}) {}

fth::token::token(token_kind kind, source_span span, std::string&& text)
    : m_kind(kind), m_span(span), m_text(std::move(text)) {}

fth::token_kind fth::token::kind() const {
    return m_kind;
}

fth::source_span fth::token::span() const {
    return m_span;
}

std::string_view fth::token::text() const {
    return m_text;
}

std::ostream& fth::operator<<(std::ostream& os, const token& token) {
    return os << "{kind: " << magic_enum::enum_name(token.kind()) << ", span: " << token.span()
              << ", text: '" << token.text() << "'}";
}

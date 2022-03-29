#include "forth/lexer.hpp"

#include "forth/source_location.hpp"
#include "forth/source_text.hpp"

#include <cctype>
#include <charconv>
#include <cstdint>

void fth::lexer::iterator::skip_whitespace() {
    while (std::isspace(current())) {
        advance();
    }
    if (current() == '\0') {
        m_has_text = false;
    }
}

fth::token fth::lexer::iterator::scan() {
    skip_whitespace();

    if (!m_has_text) {
        return {token_kind::eof, {m_location, m_location}, ""};
    }

    source_location begin = m_location;

    while (m_has_text && !std::isspace(current())) {
        advance();
    }

    source_location end = m_location;
    source_span span = {begin, end};

    return token{
            classify_token((*m_text)[span]),
            span,
            std::string{(*m_text)[span]},
    };
}

void fth::lexer::iterator::advance() {
    if (current() == '\n') {
        ++m_location.line;
        m_location.column = 0;
    } else if (current() == '\0') {
        m_has_text = false;
    } else {
        ++m_location.column;
    }
    ++m_location.offset;
}

char fth::lexer::iterator::current() const {
    return (*m_text)[m_location.offset];
}

fth::token_kind fth::lexer::iterator::classify_token(std::string_view text) {
    if (text == ".") {
        return token_kind::period;
    }
    if (text == "CR") {
        return token_kind::kw_cr;
    }
    if (text == "+") {
        return token_kind::plus;
    }
    if (text == "-") {
        return token_kind::minus;
    }
    if (text == "*") {
        return token_kind::star;
    }
    if (text == "/") {
        return token_kind::slash;
    }

    std::int64_t value;
    auto [_, ec] = std::from_chars(text.data(), text.data() + text.size(), value);
    if (ec != std::errc{}) {
        return token_kind::bad;
    }

    return token_kind::number;
}

fth::lexer::iterator::iterator() : m_location(0, 0, 0), m_has_text(false) {}

fth::lexer::iterator::iterator(const fth::source_text* text)
    : m_text(text), m_location(0, 0, 0), m_has_text(true), m_just_scanned(scan()) {}

const fth::lexer::iterator::value_type& fth::lexer::iterator::operator*() const {
    return m_just_scanned;
}

fth::lexer::iterator& fth::lexer::iterator::operator++() {
    m_just_scanned = scan();
    return *this;
}

fth::lexer::iterator fth::lexer::iterator::operator++(int) {
    auto old_it = *this;
    ++(*this);
    return old_it;
}

bool fth::lexer::iterator::operator==(const iterator& other) const {
    if (m_just_scanned.kind() == token_kind::eof &&
            other.m_just_scanned.kind() == token_kind::eof) {
        return true;
    }
    return m_text == other.m_text && m_location == other.m_location;
}

fth::lexer::lexer(const source_text& text) : m_text(text) {}

fth::lexer::iterator fth::lexer::begin() const {
    return iterator{&m_text};
}

fth::lexer::iterator fth::lexer::end() const {
    return iterator{};
}

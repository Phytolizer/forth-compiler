#include "forth/source_text.hpp"

fth::source_text::source_text(std::string&& text) : m_text(std::move(text)) {}

std::string_view fth::source_text::text() const {
    return m_text;
}

char fth::source_text::operator[](std::size_t index) const {
    if (index >= m_text.size()) {
        return '\0';
    }
    return m_text[index];
}

std::string_view fth::source_text::operator[](source_span span) const {
    if (span.begin.offset >= m_text.size()) {
        return "";
    }
    if (span.end.offset >= m_text.size()) {
        return std::string_view{m_text}.substr(span.begin.offset);
    }
    return std::string_view{m_text}.substr(span.begin.offset, span.end.offset - span.begin.offset);
}

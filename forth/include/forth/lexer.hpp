#pragma once

#include "forth/source_location.hpp"
#include "forth/source_text.hpp"
#include "forth/token.hpp"
#include "forth/token_kind.hpp"

#include <bits/ranges_base.h>
#include <concepts>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <string_view>

namespace fth {

class lexer {
    const source_text& m_text;

  public:
    class iterator {
        const source_text* m_text;
        source_location m_location;
        bool m_has_text;
        token m_just_scanned;

        void skip_whitespace();
        token scan();
        void advance();
        char current() const;
        static token_kind classify_token(std::string_view text);

      public:
        using value_type = token;
        using difference_type = std::ptrdiff_t;

        iterator();
        explicit iterator(const source_text* text);

        const value_type& operator*() const;
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& other) const;
    };

    explicit lexer(const source_text& text);

    iterator begin() const;
    iterator end() const;
};

} // namespace fth

static_assert(std::ranges::range<fth::lexer>, "lexer is not iterable");

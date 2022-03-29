#pragma once

#include "magic_enum.hpp"

namespace fth {

enum class token_kind {
    // Special tokens
    bad,
    eof,
    number,

    // Operators
    star,
    plus,
    minus,
    slash,
    period,

    // Keywords
    kw_cr,
};

}

#pragma once

#include "forth/operation.hpp"
#include "forth/token.hpp"

namespace fth {

operation parse_token(token&& token);

} // namespace fth

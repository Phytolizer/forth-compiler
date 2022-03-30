#include "forth/parser.hpp"

#include "forth/operation.hpp"
#include "forth/token_kind.hpp"

#include <cassert>
#include <charconv>
#include <cstdint>

fth::operation fth::parse_token(token&& token) {
    switch (token.kind()) {
        case token_kind::kw_cr:
            return operation{std::move(token), operation_kind::cr};
        case token_kind::minus:
            return operation{std::move(token), operation_kind::minus};
        case token_kind::plus:
            return operation{std::move(token), operation_kind::plus};
        case token_kind::slash:
            return operation{std::move(token), operation_kind::slash};
        case token_kind::star:
            return operation{std::move(token), operation_kind::star};
        case token_kind::period:
            return operation{std::move(token), operation_kind::dump};
        case token_kind::number: {
            std::int64_t operand;
            auto [_, ec] = std::from_chars(
                    token.text().data(), token.text().data() + token.text().size(), operand);
            assert(ec == std::errc{});
            return operation{std::move(token), operation_kind::push, operand};
        }
        default:
            assert(false && "unreachable");
    }
}

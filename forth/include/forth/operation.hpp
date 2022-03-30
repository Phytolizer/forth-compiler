#pragma once

#include "forth/stack_type.hpp"
#include "forth/token.hpp"
#include "magic_enum.hpp"

#include <cstdint>

namespace fth {

enum class operation_kind {
    // Special (have operands)
    push,

    // Operators
    star,
    plus,
    minus,
    slash,
    dump,

    // Words
    cr,
};

class operation final {
    token m_origin;
    operation_kind m_kind;
    stack_type m_operand;

  public:
    explicit operation(token&& origin, operation_kind kind);
    explicit operation(token&& origin, operation_kind kind, stack_type operand);

    constexpr const token& origin() const {
        return m_origin;
    }

    constexpr operation_kind kind() const {
        return m_kind;
    }

    constexpr stack_type operand() const {
        return m_operand;
    }
};

} // namespace fth

template <> struct fmt::formatter<fth::operation> {
    constexpr auto parse(format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const fth::operation& operation, FormatContext& ctx) {
        if (operation.kind() == fth::operation_kind::push) {
            return format_to(ctx.out(), "{{kind: {}, operand: {}}}",
                    magic_enum::enum_name(operation.kind()), operation.operand());
        } else {
            return format_to(ctx.out(), "{{kind: {}}}", magic_enum::enum_name(operation.kind()));
        }
    }
};

#include "forth/operation.hpp"

fth::operation::operation(token&& origin, operation_kind kind)
    : operation(std::move(origin), kind, INT64_C(0)) {}

fth::operation::operation(token&& origin, operation_kind kind, std::int64_t operand)
    : m_origin(std::move(origin)), m_kind(kind), m_operand(operand) {}

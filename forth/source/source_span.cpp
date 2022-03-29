#include "forth/source_span.hpp"

std::ostream& fth::operator<<(std::ostream& os, const source_span& span) {
    return os << "(" << span.begin.line << ", " << span.begin.column << ") .. (" << span.end.line
              << ", " << span.end.column << ")";
}

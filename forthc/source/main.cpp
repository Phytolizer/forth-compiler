#include "fmt/core.h"
#include "forth/lexer.hpp"
#include "forth/parser.hpp"
#include "forth/source_text.hpp"
#include "forth/token_kind.hpp"

#include <cstdio>
#include <iostream>
#include <string>

int main() {
    std::string line;
    while (true) {
        fmt::print("> ");
        if (!std::getline(std::cin, line)) {
            break;
        }

        fth::source_text text{std::string{line}};

        for (auto tok : fth::lexer(text)) {
            if (tok.kind() == fth::token_kind::bad) {
                fmt::print(stderr, "{}: bad token '{}'\n", tok.span(), tok.text());
                continue;
            }
            auto op = fth::parse_token(std::move(tok));
            fmt::print("{}\n", op);
        }
    }
    return 0;
}

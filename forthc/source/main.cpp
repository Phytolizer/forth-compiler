#include "fmt/core.h"
#include "forth/lexer.hpp"
#include "forth/source_text.hpp"

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
            fmt::print("{}\n", tok);
        }
    }
    return 0;
}

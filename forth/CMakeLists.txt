add_library(
    forth "source/lexer.cpp" "source/operation.cpp" "source/parser.cpp"
          "source/source_span.cpp" "source/source_text.cpp" "source/token.cpp"
)

target_include_directories(forth PUBLIC include)
target_link_libraries(forth PUBLIC fmt::fmt magic_enum::magic_enum)

add_library(forth::forth ALIAS forth)

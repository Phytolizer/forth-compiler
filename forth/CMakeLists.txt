add_library(
    forth "source/lexer.cpp" "source/source_text.cpp" "source/token.cpp"
)

target_include_directories(forth PUBLIC include)
target_link_libraries(forth PUBLIC magic_enum::magic_enum)

add_library(forth::forth ALIAS forth)

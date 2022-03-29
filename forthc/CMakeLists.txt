add_executable(forthc "source/main.cpp")
target_link_libraries(forthc PRIVATE forth::forth fmt::fmt)

add_library(view SignerWindow.h SignerWindow.cpp Runner.h Runner.cpp)
add_subdirectory(Controls)
target_include_directories(view PUBLIC Controls)
target_link_libraries(view PUBLIC controls)
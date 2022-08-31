add_library(view SignerWindow.h SignerWindow.cpp)

target_include_directories(
    view
    PUBLIC
    /usr/local/Cellar/sdl2/2.0.20/include/SDL2
)

target_link_libraries(
    view
    /usr/local/Cellar/sdl2/2.0.20/lib/libSDL2-2.0.0.dylib
)
# this way it will build the library
add_library(manager UserHandler.cpp UserHandler.h SQL_Operations.cpp SQL_Operations.h)
target_include_directories(
    manager
    PUBLIC
    /usr/local/include
    ../Model/User.cpp
    )
target_link_libraries(
    manager
    /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib
    models
)

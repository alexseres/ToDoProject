add_library(data_manager SQL_Operations.cpp SQL_Operations.h)
target_include_directories(
    data_manager
    PUBLIC
    /usr/local/include
    )

target_link_libraries(
    data_manager
    PUBLIC
    /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib
    utils
)

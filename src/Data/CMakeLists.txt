add_library(data_manager SQL_Operations.cpp SQL_Operations.h SQL_Abstract.h SQL_Abstract.cpp)
target_include_directories(
    data_manager
    PUBLIC
    /usr/local/include
    )

target_link_libraries(
    data_manager
    PUBLIC
    /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx-7.7.dylib
    utils
)

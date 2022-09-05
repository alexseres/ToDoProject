add_library(models UserHandler.cpp UserHandler.h User.cpp User.h Table.h Table.cpp Card.h Card.cpp)
target_include_directories(
    models
    PUBLIC
    /usr/local/include

    )
target_link_libraries(
    models
    /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib
    data_manager
    utils
)

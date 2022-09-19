add_library(models UserHandler.cpp UserHandler.h User.cpp User.h Table.h Table.cpp Card.h Card.cpp)
target_include_directories(
    models
    PUBLIC
    /usr/local/include

    )
target_link_libraries(
    models
    PUBLIC
    /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx-7.7.dylib
    data_manager
    utils
)

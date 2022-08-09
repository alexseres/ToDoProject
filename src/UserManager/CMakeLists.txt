# this way it will build the library
add_library(user_manager SignIn.cpp SignIn.h UserRegistration.cpp UserRegistration.h)
target_include_directories(user_manager PUBLIC /usr/local/include)
target_link_libraries(user_manager /usr/local/Cellar/libpqxx/7.7.4/lib/libpqxx.dylib)

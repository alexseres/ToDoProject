add_executable(todop main.cpp)
add_subdirectory(Utils)
add_subdirectory(View)
add_subdirectory(Model)
add_subdirectory(Data)
#target_include_directories(todop PUBLIC Model Data View)
#target_link_directories(todop PUBLIC Model Data View)
target_link_libraries(todop PUBLIC models data_manager view)

project(ToDoProject)

add_executable(ToDoProject main.cpp)
add_subdirectory(user_manager)

#this helps when you include with macros, doesnt have to specify which folder, just the filename
target_include_directories(ToDoProject PUBLIC user_manager)

#below it is linking to the executable
target_link_libraries(ToDoProject PUBLIC user_manager)

#below its tells where the file can be found
# target_link_directories(ToDoProject PUBLIC register.h)






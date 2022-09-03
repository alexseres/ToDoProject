add_library(view Signer.h Signer.cpp)
#target_include_directories(view PUBLIC /Users/alexseres/OwnCPlusPlusProjects/ToDoProject/src/Model)
target_link_libraries(view PUBLIC models)
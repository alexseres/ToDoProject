add_library(view Signer.h Signer.cpp MainView.h MainView.cpp)
#target_include_directories(view PUBLIC /Users/alexseres/OwnCPlusPlusProjects/ToDoProject/src/Model)
target_link_libraries(view PUBLIC models)

#include "UserHandler.h"


int UserHandler::create_user(){
    
}


bool UserHandler::check_connection() {
    std::string connectionString = util.getEnvironmentVariableConnectionString();
    bool hasConnected;
    try {
        pqxx::connection connection_object(connectionString);
        if (connection_object.is_open()) {
            std::cout << "Opened database successfully: " << connection_object.dbname() << std::endl;
            hasConnected = true;
        } else {
            std::cout << "Can't open database" << std::endl;
            hasConnected = false;
        }
        connection_object.close();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        hasConnected = false;
    }
    return hasConnected;
}

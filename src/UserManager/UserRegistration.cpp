
#include "UserRegistration.h"
#include "../Utils.h"
Utils util;



int UserRegistration::registerUser() {
    //std::string connectionString = util.getEnvironmentVariableConnectionString();
    try {
        pqxx::connection connection_object("user=alexseres password=szopacs11 dbname=tododb");
        // pqxx::connection connection_object("dbname = tododb user = postgres password = szopacs11 host = 127.0.0.1 port = 5432");
        if (connection_object.is_open()) {
            std::cout << "Opened database successfully: " << connection_object.dbname() << std::endl;
        } else {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
        connection_object.close();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}




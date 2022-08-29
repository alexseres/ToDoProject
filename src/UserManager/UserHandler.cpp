
#include "UserHandler.h"


int UserHandler::create_user(std::string user_name, std::string password){
    try {
      pqxx::connection connection_object(connection_string);
      if (connection_object.is_open()) {
        std::cout << "Opened database successfully: " << connection_object.dbname() << std::endl;
      } else {
        std::cout << "Can't open database" << std::endl;
        return 1;
      }
      unsigned long hashed_password = Utils::hash_password(password);
      /* Create SQL statement */
      std::string sql = "INSERT INTO USERS(" + user_name + "," + hashed_password + ")";

      /* Create a transactional object. */
      pqxx::work W(connection_object);
      
      /* Execute SQL query */
      W.exec(sql);
      W.commit();
      std::cout << user_name <<  "table created successfully" << std::endl;
      connection_object.close();
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
      return 1;
    }
    return 0;
}


bool UserHandler::check_connection() {
    bool hasConnected;
    try {
        pqxx::connection connection_object(connection_string);
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
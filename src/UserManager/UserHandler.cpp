
#include "UserHandler.h"


int UserHandler::create_user(std::string user_name, std::string password, std::string salt){
    try {
      pqxx::connection connection_object(connection_string);
      if(!check_connection(connection_object)) return 0;

      auto hashed_password = std::to_string(Utils::hash_password(password+salt));
      /* Create SQL statement */
      std::string sql = "INSERT INTO \"Users\"(" \
                          "user_id, user_name, hashed_value, salt)" \
                          "VALUES (gen_random_uuid (), '"  + user_name + "', '" + hashed_password + "', '" + salt + "');";

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

int UserHandler::get_user(std::string user_name,std::string password, std::string salt){
    try {
        pqxx::connection connection_object(connection_string);
        if(!check_connection(connection_object)) return 0;
        
        std::string sql = "SELECT * FROM Users WHERE user_name=" + user_name + " AND salt=" + salt + ";";

    
        /* Create a non-transactional object. */
        pqxx::nontransaction nontransactional_object(connection_object);

        pqxx::result r(nontransactional_object.exec(sql));
    
        std::string hashed_password = std::to_string(Utils::hash_password(password+salt));

        // std::string hashed_password_from_db = res[3].as<std::string>();
        // for (auto const &row: r){
        //     std::cout << to_string(row) << std::endl;
        // }



        connection_object.close();
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

bool UserHandler::check_connection(pqxx::connection& connection_object) {
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
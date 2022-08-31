#include "UserHandler.h"




int UserHandler::create_user(std::string user_name, std::string password, std::string salt) {
    try {
        auto hashed_password = std::to_string(Utils::hash_password(password + salt));
        std::string sql_statement = "INSERT INTO \"Users\"(" \
                      "user_id, user_name, hashed_value, salt)" \
                      "VALUES (gen_random_uuid (), '" + user_name + "', '" + hashed_password + "', '" + salt + "');";
        int suceeded = sql_manager.insert_data(sql_statement);

        if(suceeded == 0){
            std::cout << "insert operation succeded" << std::endl;
        }
        else{
            std::cerr <<"insert operation not succeded"<< std::endl;
            throw pqxx::sql_error();
        }

    } catch (const pqxx::sql_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int UserHandler::get_user(std::string user_name,std::string password, std::string salt){
    try {
        std::string sql_statement = "SELECT * FROM \"Users\" WHERE user_name='" + user_name + "' AND salt='" + salt + "';";
        pqxx::result r = sql_manager.get_data(sql_statement);

        std::string given_hashed_password = std::to_string(Utils::hash_password(password + salt));
        std::string hash_value_from_db = pqxx::to_string(r[0][2].c_str());
        if(given_hashed_password == hash_value_from_db) {
            //below converts pqxx val to string and assign those to user members
//            return User(pqxx::to_string(r[0][0].c_str()), pqxx::to_string(r[0][1].c_str()), hash_value_from_db, pqxx::to_string(r[0][3].c_str()));
            return 0;
        }
        else{
            throw std::runtime_error("password is wrong");
        }
    } catch(const pqxx::sql_error &e){
        std::cerr << e.what() << std::endl;
        return 1;
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



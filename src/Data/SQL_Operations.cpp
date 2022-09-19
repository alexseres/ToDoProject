#include "SQL_Operations.h"

int SQL_Operations::insert_data(std::string statement) {
    try {
        std::string conn_str = Utils::getEnvironmentVariableConnectionString();
        pqxx::connection connection_object(conn_str);
        if (!check_connection(connection_object)){
            std::cerr <<"connection has not been established"<< std::endl;
            return 1;
        }
        /* Create a transactional object. */
        pqxx::work W(connection_object);
        /* Execute SQL query */
        W.exec(statement);
        W.commit();
        connection_object.close();
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}


pqxx::result SQL_Operations::get_data(std::string statement) {
    pqxx::connection connection_object(connection_string);
    if(!check_connection(connection_object)) throw pqxx::sql_error("connection has not been established");
    pqxx::nontransaction nontransactional_object(connection_object);
    pqxx::result r(nontransactional_object.exec(statement));
    connection_object.close();
    return r;

}

bool SQL_Operations::check_connection(pqxx::connection &connection_object) {
    bool hasConnected;
    try {
        if (connection_object.is_open()) {
            std::cout << "Opened database successfully: " << connection_object.dbname() << std::endl;
            hasConnected = true;
        } else {
            std::cout << "Can't open database" << std::endl;
            hasConnected = false;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        hasConnected = false;
    }
    return hasConnected;
}
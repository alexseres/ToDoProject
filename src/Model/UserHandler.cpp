#include "UserHandler.h"

void UserHandler::add_table(std::string table_name, std::string user_uuid) {
    std::string table_uuid = Utils::generateUUID();
    std::string sql_statement_add_tables = "INSERT INTO \"tables\"(" \
                        "user_id, table_id, table_name)" \
                        "VALUES ('" + user_uuid + "', '" + table_uuid + "',  '" + table_name + "');";
    sql_manager.insert_data(sql_statement_add_tables);
}


void UserHandler::get_tables(std::string user_uuid, std::vector<Table> &tables) {
    std::string sql_statement = "SELECT * FROM \"tables\" WHERE user_id='" + user_uuid + "';";
    pqxx::result r = sql_manager.get_data(sql_statement);
    for(const auto &row : r){
        std::vector<Card> cards;
        std::string table_uuid = row[1].c_str();
        get_cards(table_uuid, cards);
        Table table(row[0].c_str(), table_uuid, row[2].c_str(), cards);
        tables.push_back(table);
    }
}

void UserHandler::get_cards(std::string table_uuid, std::vector<Card> &cards) {
    std::string sql_statement = "SELECT * FROM \"cards\" WHERE table_id='" + table_uuid + "';";
    pqxx::result r = sql_manager.get_data(sql_statement);
    for(const auto &row : r){
        //           tableuuid, carduuid, description
        Card card(row[0].c_str(), row[1].c_str(), row[2].c_str());
        cards.push_back(card);
    }
}

int UserHandler::create_user(std::string user_name, std::string password, std::string salt) {
    try {
        std::string user_uuid = Utils::generateUUID();

        auto hashed_password = std::to_string(Utils::hash_password(password + salt));
        std::string sql_statement = "INSERT INTO \"users\"(" \
                      "user_id, user_name, hashed_value, salt)" \
                      "VALUES ('" + user_uuid + "', '" + user_name + "', '" + hashed_password + "', '" + salt + "');";
        int suceeded = sql_manager.insert_data(sql_statement);
        if(suceeded == 0){
            add_table("On Progress", user_uuid);
            add_table("On Waiting", user_uuid);
            add_table("DONE", user_uuid);
            std::cout << "insert operation succeded" << std::endl;
            return 0;
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
}

User UserHandler::get_user(std::string user_name, std::string password, std::string salt){
    try {
        std::string sql_statement = "SELECT * FROM \"users\" WHERE user_name='" + user_name + "' AND salt='" + salt + "';";
        pqxx::result r = sql_manager.get_data(sql_statement);

        std::string given_hashed_password = std::to_string(Utils::hash_password(password + salt));
        std::string hash_value_from_db = pqxx::to_string(r[0][2].c_str());
        if(given_hashed_password == hash_value_from_db) {
            //below converts pqxx val to string and assign those to user members
            std::string uuid = pqxx::to_string(r[0][0].c_str());
            std::vector<Table> tables;
            get_tables(uuid, tables);
            return User(uuid, pqxx::to_string(r[0][1].c_str()), hash_value_from_db, pqxx::to_string(r[0][3].c_str()), password, tables);
        }
        else{
            throw std::runtime_error("password is wrong");
        }
    } catch(const pqxx::sql_error &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
    catch(const std::runtime_error &e){
        std::cerr << e.what() << std::endl;
        throw;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}

void UserHandler::add_card_for_table(std::string table_uuid, std::string card_name) {
    std::string card_uuid = Utils::generateUUID();
    std::string sql_statement_add_tables = "INSERT INTO \"cards\"(" \
                        "table_id, card_id, card_name)" \
                        "VALUES ('" + table_uuid + "', '" + card_uuid + "',  '" + card_name + "');";
    sql_manager.insert_data(sql_statement_add_tables);
}

void UserHandler::move_card(std::string card_id, std::string new_table_id) {

    std::string update_card_statement = "UPDATE \"cards\"" \
                                    "SET table_id = '" + new_table_id + "'" \
                                    "WHERE card_id = '" + card_id + "';";
    sql_manager.insert_data(update_card_statement);
}

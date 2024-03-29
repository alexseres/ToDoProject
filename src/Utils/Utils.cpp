#include "Utils.h"
#include <random>
#include <sstream>

std::string Utils::generateUUID() {
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);
    std::stringstream ss;
    int i;
    ss << std::hex;
    for (i = 0; i < 8; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 4; i++) {
        ss << dis(gen);
    }
    ss << "-4";
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    ss << dis2(gen);
    for (i = 0; i < 3; i++) {
        ss << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 12; i++) {
        ss << dis(gen);
    };
    return ss.str();

}


std::string Utils::getEnvironmentVariableConnectionString(){
    const char *conn_string = getenv("todop_conn_str");
    if(conn_string != nullptr) return conn_string;
    else
      std::cout<<"connection string not found"<<std::endl;
      return nullptr;

}

unsigned long const Utils::hash_password(std::string str){
  std::hash<std::string> hash_obj;
  return hash_obj(str);
  
}

int Utils::get_longest_vector_size(std::vector<Table> tables) {
    int table_size = tables[0].get_cards().size();
    for(Table t : tables){
        if(t.get_cards().size() > table_size){
            table_size = t.get_cards().size();
        }
    }
    return table_size;
}

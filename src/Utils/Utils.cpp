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


std::string const Utils::getEnvironmentVariableConnectionString(){

    const char *conn_string = getenv("todop_conn_str");
    if(conn_string != nullptr) return conn_string;
    else
      std::cout<<"connection string nout found"<<std::endl;
      return nullptr;
    
    return "ok";
}

unsigned long const Utils::hash_password(std::string str){
  std::hash<std::string> hash_obj;
  return hash_obj(str);
  
}
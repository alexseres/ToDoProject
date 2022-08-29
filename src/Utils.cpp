#include "Utils.h"

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
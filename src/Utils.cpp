#include "Utils.h"
extern char **environ;

std::string const Utils::getEnvironmentVariableConnectionString(){

    const char *conn_string = getenv("todop_conn_str");
    if(conn_string != nullptr) return conn_string;
    else
      std::cout<<"connection string nout found"<<std::endl;
      return nullptr;
    
    return "ok";
}
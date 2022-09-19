#ifndef TODOPROJECT_SQL_OPERATIONS_H
#define TODOPROJECT_SQL_OPERATIONS_H
#include "SQL_Abstract.h"

class SQL_Operations : public SQL_Abstract{
private:
    std::string connection_string = Utils::getEnvironmentVariableConnectionString();
public:
    bool check_connection(pqxx::connection &connection_object) override;
    int insert_data(std::string statement) override;
    pqxx::result get_data(std::string statement) override;
    std::string get_connection_string() {return connection_string;}
};


#endif //TODOPROJECT_SQL_OPERATIONS_H

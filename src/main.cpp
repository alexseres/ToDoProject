#include <iostream>
#include "View/Signer.h"
#include "Data/SQL_Operations.h"
#include "Model/UserHandler.h"


int main(int argc, char * argv []) {
    SQL_Abstract *sql = new SQL_Operations;
    UserHandler handler(sql);
    Signer signer(handler);
    signer.introduction();
    return 0;

}

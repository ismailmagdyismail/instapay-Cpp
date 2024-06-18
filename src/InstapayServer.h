#ifndef INSTAPAY_INSTAPAYSERVER_H
#define INSTAPAY_INSTAPAYSERVER_H

#include <memory>
#include "../cpp-httplib/httplib.h"
#include "users/dataAccess/IUserDataAccess.hpp"
#include "transactions/dataAccess/ITransactionDataAccess.hpp"

class InstapayServer {
public:
    static InstapayServer* getInstance();
    void run();
private:
    httplib::Server server;
    static InstapayServer* instance;
    std::unique_ptr<IUserDataAccess>userDataAccess;
    std::unique_ptr<ITransactionDataAccess>transactionDataAccess;
    InstapayServer();
};


#endif //INSTAPAY_INSTAPAYSERVER_H

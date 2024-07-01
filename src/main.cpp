#include <iostream>
#include "InstapayServer.h"
#include <optional>
#include <thread>
#include "../cpp-httplib/httplib.h"

int main(){
    std::cout<<"DEMO2\n";
    InstapayServer* instapayServer = InstapayServer::getInstance();
    instapayServer->run();
    delete instapayServer;
}

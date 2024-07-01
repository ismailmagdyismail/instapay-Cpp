#include <iostream>
#include "InstapayServer.h"
#include <optional>
#include <thread>
#include "../cpp-httplib/httplib.h"

int main(){
    InstapayServer* instapayServer = InstapayServer::getInstance();
    instapayServer->run();
    delete instapayServer;
}

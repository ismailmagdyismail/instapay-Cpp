#include <iostream>
#include "InstapayServer.h"
int main(){
    InstapayServer* instapayServer = InstapayServer::getInstance();
    instapayServer->run();
    delete instapayServer;
}

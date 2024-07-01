#include <iostream>
#include "InstapayServer.h"
#include <optional>
#include <thread>
#include "../cpp-httplib/httplib.h"

class Test{
  public:
    virtual void test() = 0 ;
    virtual ~Test() = default;
};

class A{
public :
    A() {std::cout<<"DEF\n";}
    A(const A& other){
        std::cout<<"COPY\n";
    }
    A(A&& other ){
        std::cout<<"MOVE\n";
    }
};

class B{
public:
    B(const A& a):a(a){
    }
    B(A&& a):a(std::move(a)){
    }
    A a;
};
void test(A a){
    std::cout<<"test\n";
}

int main(){
    B(A{});
    // std::cout<<"Hello world";
   InstapayServer* instapayServer = InstapayServer::getInstance();
   instapayServer->run();
   delete instapayServer;

}

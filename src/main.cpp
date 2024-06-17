#include "_tests/GatewayTests.hpp"
#include "_tests/UsersTests.hpp"
#include "users/domain/WalletUser.hpp"
#include "transactions/usecase/TransferUseCase.hpp"
#include "users/dataAccess/InMemoryUsers.hpp"
#include <iostream>

int main(){
    std::unique_ptr<IUserDataAccess> userDataAccess = std::make_unique<InMemoryUsers>();
    userDataAccess->addUser(std::make_unique<WalletUser>(UserProfile{"ismail1", "password", "011223455"}, "vodafone"));
    userDataAccess->addUser(std::make_unique<WalletUser>(UserProfile{"ismail2", "password", "011223466"}, "vodafone"));
    auto response = TransferUseCase::execute("ismail1","ismail2",10.0,userDataAccess);
    std::cout<<response.isSuccessful<<'\n';
    std::cout<<response.statusCode<<'\n';
    std::cout<<response.message<<'\n';
    GatewayTests::run();
    UsersTests::run();
}

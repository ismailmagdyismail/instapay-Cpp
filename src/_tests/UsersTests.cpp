#include <memory>
#include <iostream>
#include <cassert>
#include "UsersTests.hpp"
#include "../users/dataAccess/IUserDataAccess.h"
#include "../users/dataAccess/InMemoryUsers.h"
#include "../users/domain/BankUser.hpp"
#include "../users/domain/WalletUser.hpp"


void testDB(const std::unique_ptr<IUserDataAccess>& dataAccess){
    std::cout<<"=====....Testing User DataAccess....=====\n";
    dataAccess->addUser(std::make_unique<BankUser>(UserProfile{"ismail1","password","011"},"bank","1122"));
    dataAccess->addUser(std::make_unique<WalletUser>(UserProfile{"ismail2","password","011"},"wallet"));
    assert(dataAccess->getUsersCount() == 2);
}

void UsersTests::run() {
    testDB(std::make_unique<InMemoryUsers>());
}
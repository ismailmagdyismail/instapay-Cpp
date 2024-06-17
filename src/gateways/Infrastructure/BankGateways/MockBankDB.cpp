#include "MockBankDB.hpp"

std::unordered_map<std::string,double> MockBankDB::db = std::unordered_map<std::string,double>();
MockBankDB::Initializer MockBankDB::initializer = MockBankDB::Initializer();


bool MockBankDB::isRegisteredUser(std::string accountNumber) {
    return MockBankDB::db.find(accountNumber) != MockBankDB::db.end();
}


std::optional<std::string> MockBankDB::updateUserBalance(std::string accountNumber, double newBalance) {
    if(!isRegisteredUser(accountNumber)){
        return "No bank account with this account number exists "+accountNumber;
    }
    if(newBalance < 0 ){
        return {"Invalid amount , balance cannot be -ve"};
    }
    MockBankDB::db[accountNumber] = newBalance;
    return {};
}

std::optional<double> MockBankDB::getUserBalance(std::string accountNumber) {
    if(!MockBankDB::isRegisteredUser(accountNumber)){
        return {};
    }
    return MockBankDB::db[accountNumber];
}

std::optional<std::string> MockBankDB::addUser(std::string accountNumber) {
    if(MockBankDB::isRegisteredUser(accountNumber)){
        return {"Bank account with this number is already registered"+accountNumber};
    }
    MockBankDB::db[accountNumber] = 0.0;
    return {};
}
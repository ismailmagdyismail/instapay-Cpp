#include "MockBankDB.hpp"

std::unordered_map<std::string,double> MockBankDB::db = std::unordered_map<std::string,double>();
MockBankDB::Initializer MockBankDB::initializer = MockBankDB::Initializer();


bool MockBankDB::isRegisteredUser(std::string accountNumber) {
    return MockBankDB::db.find(accountNumber) != MockBankDB::db.end();
}

Response MockBankDB::updateUserBalance(std::string accountNumber, double newBalance) {
    if(!isRegisteredUser(accountNumber)){
        return Response{false,404,"No bank account with this account number exists "+accountNumber};
    }
    if(newBalance < 0 ){
        return Response{false,400,"Invalid amount , balance cannot be -ve"};
    }
    MockBankDB::db[accountNumber] = newBalance;
    return Response{true,200,""};
}

std::optional<double> MockBankDB::getUserBalance(std::string accountNumber) {
    if(!MockBankDB::isRegisteredUser(accountNumber)){
        return {};
    }
    return MockBankDB::db[accountNumber];
}

Response MockBankDB::addUser(std::string accountNumber) {
    if(MockBankDB::isRegisteredUser(accountNumber)){
        return Response{false,404,"Bank account with this number is already registered"+accountNumber};
    }
    return Response{true,200,""};
}
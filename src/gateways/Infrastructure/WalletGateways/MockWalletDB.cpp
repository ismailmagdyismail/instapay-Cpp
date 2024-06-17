#include "MockWalletDB.hpp"
#include <unordered_map>

std::unordered_map<std::string,double> MockWalletDB::db = std::unordered_map<std::string,double>();
MockWalletDB::Initializer MockWalletDB::initializer = MockWalletDB::Initializer();


bool MockWalletDB::isRegisteredUser(const std::string& phoneNumber) {
    return MockWalletDB::db.find(phoneNumber) != db.end();
}

std::optional<double> MockWalletDB::getUserBalance(const std::string& phoneNumber) {
    if(!MockWalletDB::isRegisteredUser(phoneNumber)){
        return {};
    }
    return db[phoneNumber];
}

Response MockWalletDB::updateUserBalance(const std::string& phoneNumber, const double& newBalance) {
    if(!MockWalletDB::isRegisteredUser(phoneNumber)){
        return Response{false,404,"No Wallet found for this phone number " + phoneNumber};
    }
    if(newBalance < 0 ){
        return Response{false,404,"Invalid amount , balance cannot be -ve"};
    }
    MockWalletDB::db[phoneNumber] = newBalance;
    return  Response{true,200,""};
}

Response MockWalletDB::addUser(const std::string& phoneNumber) {
    if(MockWalletDB::isRegisteredUser(phoneNumber)){
        return Response{false,404,"An account already exists for this phone number" + phoneNumber};
    }
    MockWalletDB::db[phoneNumber] = 0.0;
    return Response{true,200,""};
}
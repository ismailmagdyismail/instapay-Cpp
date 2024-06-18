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

OperationResult MockWalletDB::updateUserBalance(const std::string& phoneNumber, const double& newBalance) {
    if(!MockWalletDB::isRegisteredUser(phoneNumber)){
        return OperationResult{false, 404, "No Wallet found for this phone number " + phoneNumber};
    }
    if(newBalance < 0 ){
        return OperationResult{false, 404, "Invalid amount , balance cannot be -ve"};
    }
    MockWalletDB::db[phoneNumber] = newBalance;
    return  OperationResult{true, 200, ""};
}

OperationResult MockWalletDB::addUser(const std::string& phoneNumber) {
    if(MockWalletDB::isRegisteredUser(phoneNumber)){
        return OperationResult{false, 404, "An account already exists for this phone number" + phoneNumber};
    }
    MockWalletDB::db[phoneNumber] = 0.0;
    return OperationResult{true, 200, ""};
}
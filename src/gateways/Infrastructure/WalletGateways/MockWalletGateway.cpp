#include "MockWalletGateway.hpp"
#include "MockWalletDB.hpp"

MockWalletGateway::MockWalletGateway(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

std::optional<std::string> MockWalletGateway::deposit(const double &amount) {
    std::optional<double> balance = MockWalletDB::getUserBalance(this->phoneNumber);
    if(!balance.has_value()){
        return "No Wallet exists for this phone number "+this->phoneNumber;
    }
    return MockWalletDB::updateUserBalance(this->phoneNumber,balance.value() + amount);
}

std::optional<std::string> MockWalletGateway::withdraw(const double &amount) {
    std::optional<double> balance = MockWalletDB::getUserBalance(this->phoneNumber);
    if(!balance.has_value()){
        return "No Wallet exists for this phone number "+this->phoneNumber;
    }
    return MockWalletDB::updateUserBalance(this->phoneNumber,balance.value() - amount);
}

std::optional<double> MockWalletGateway::getBalance() const {
    return MockWalletDB::getUserBalance(this->phoneNumber);
}
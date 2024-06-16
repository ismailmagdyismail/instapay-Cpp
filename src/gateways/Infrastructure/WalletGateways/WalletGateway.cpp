#include "WalletGateway.hpp"
#include "MockWalletDB.hpp"

WalletGateway::WalletGateway(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

std::optional<std::string> WalletGateway::deposit(const double &amount) {
    std::cout<<"Wallet depositing.. for "<<this->phoneNumber<<'\n';
    return {"Deposit for phone failed"};
}

std::optional<std::string> WalletGateway::withdraw(const double &amount) {
    std::cout<<"Wallet withdrawing... for "<<this->phoneNumber<<'\n';
    return {};
}

std::optional<double> WalletGateway::getBalance() const {
    std::cout<<"Wallet Query... for "<<this->phoneNumber<<'\n';
    return MockWalletDB::getUserBalance(this->phoneNumber);
}
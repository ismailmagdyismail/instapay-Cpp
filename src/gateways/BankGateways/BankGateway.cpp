#include "BankGateway.hpp"
#include "MockBankDB.hpp"

BankGateway::BankGateway(const std::string &bankAccountNumber) {
    this->bankAccountNumber = bankAccountNumber;
}

std::optional<std::string> BankGateway::deposit(const double &amount){
    std::cout<<"Bank Depositing... for "<<this->bankAccountNumber<<'\n';
    MockBankDB::updateUserBalance(this->bankAccountNumber,amount);
    return {};
}

std::optional<std::string> BankGateway::withdraw(const double &amount){
    std::cout<<"Bank Withdrawing... for "<<this->bankAccountNumber<<'\n';
    return "Error in withdrawing";
}

std::optional<double> BankGateway::getBalance()const {
    std::cout<<"Bank Query... for "<<this->bankAccountNumber<<'\n';
    return MockBankDB::getUserBalance(this->bankAccountNumber);
}


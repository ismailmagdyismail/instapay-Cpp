#include "MockBankGateway.hpp"
#include "MockBankDB.hpp"

MockBankGateway::MockBankGateway(const std::string &bankAccountNumber) {
    this->bankAccountNumber = bankAccountNumber;
}

std::optional<std::string> MockBankGateway::deposit(const double &amount){
    std::optional<double> balance = MockBankDB::getUserBalance(this->bankAccountNumber);
    if(!balance.has_value()){
        return "No bank account exists for this account number " +this->bankAccountNumber;
    }
    return MockBankDB::updateUserBalance(this->bankAccountNumber,amount + balance.value());
}

std::optional<std::string> MockBankGateway::withdraw(const double &amount){
    std::optional<double> balance = MockBankDB::getUserBalance(this->bankAccountNumber);
    if(!balance.has_value()){
        return "No bank account exists for this account number " +this->bankAccountNumber;
    }
    return MockBankDB::updateUserBalance(this->bankAccountNumber,balance.value() - amount);
}

std::optional<double> MockBankGateway::getBalance()const {
    return MockBankDB::getUserBalance(this->bankAccountNumber);
}


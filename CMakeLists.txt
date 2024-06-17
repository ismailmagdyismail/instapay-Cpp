cmake_minimum_required(VERSION 3.26)

project(instapay)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/gateways/Infrastructure/BankGateways/MockBankGateway.cpp
        src/gateways/Infrastructure/BankGateways/MockBankGateway.hpp
        src/gateways/IGateway.hpp
        src/users/domain/BankUser.hpp
        src/users/domain/WalletUser.hpp
        src/users/domain/UserProfile.hpp
        src/gateways/Infrastructure/WalletGateways/MockWalletGateway.cpp
        src/gateways/Infrastructure/WalletGateways/MockWalletGateway.hpp
        src/gateways/Infrastructure/WalletGateways/MockWalletDB.cpp
        src/gateways/Infrastructure/WalletGateways/MockWalletDB.hpp
        src/gateways/Infrastructure/BankGateways/MockBankDB.cpp
        src/gateways/Infrastructure/BankGateways/MockBankDB.hpp
        src/users/domain/IUser.hpp
        src/users/domain/IUser.hpp
        src/_tests/GatewayTests.cpp
        src/_tests/GatewayTests.hpp
        src/users/dataAccess/IUserDataAccess.h
        src/presentation/Response.h
        src/users/dataAccess/InMemoryUsers.cpp
        src/users/dataAccess/InMemoryUsers.h
        src/_tests/UsersTests.cpp
        src/_tests/UsersTests.hpp
        src/transactions/domain/ITransaction.hpp
        src/transactions/domain/ITransaction.hpp
        src/transactions/domain/TransferMoney.cpp
        src/transactions/domain/TransferMoney.hpp
        src/transactions/usecase/TransactionUseCase.hpp
)

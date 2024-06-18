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
        src/users/dataAccess/IUserDataAccess.hpp
        src/presentation/Response.hpp
        src/users/dataAccess/InMemoryUsers.cpp
        src/users/dataAccess/InMemoryUsers.hpp
        src/_tests/UsersTests.cpp
        src/_tests/UsersTests.hpp
        src/transactions/domain/entities/ITransaction.hpp
        src/transactions/domain/entities/ITransaction.hpp
        src/transactions/domain/entities/transfers/TransferMoney.cpp
        src/transactions/domain/entities/transfers/TransferMoney.hpp
        src/transactions/usecase/TransferUseCase.hpp
        src/transactions/domain/entities/transfers/TransferAuthorizer.hpp
        src/users/domain/UserType.hpp
        src/transactions/domain/entities/transfers/TransferAuthorizer.cpp
        src/transactions/domain/entities/transfers/Transaction.hpp
        src/transactions/dataAccess/ITransactionDataAccess.hpp
        src/transactions/dataAccess/InMemoryTransactions.cpp
        src/transactions/dataAccess/InMemoryTransactions.hpp
)

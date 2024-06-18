#include "InstapayServer.h"
#include "transactions/controllers/TransactionsHandlers.hpp"
#include "users/domain/WalletUser.hpp"
#include "users/dataAccess/InMemoryUsers.hpp"
#include "transactions/dataAccess/InMemoryTransactions.hpp"

InstapayServer* InstapayServer::instance = nullptr;

InstapayServer::InstapayServer() {
    this->userDataAccess = std::make_unique<InMemoryUsers>();
    this->transactionDataAccess = std::make_unique<InMemoryTransactions>();

    // Dummy accounts for testing
    userDataAccess->addUser(std::make_unique<WalletUser>(UserProfile{"ismail1", "password", "011223455"}, "vodafone"));
    userDataAccess->addUser(std::make_unique<WalletUser>(UserProfile{"ismail2", "password", "011223466"}, "vodafone"));


    /// transactions EndPoints
    server.Post("/api/v1/transfers/",[this](const httplib::Request& req,httplib::Response& res){
        TransactionsHandlers::handleTransfer(req,res,this->userDataAccess,this->transactionDataAccess);
    });
    server.Get("/api/v1/transfers/",[this](const httplib::Request& req,httplib::Response& res){
        TransactionsHandlers::handleGetAllTransfers(req,res,this->transactionDataAccess);
    });


    // users Endpoints
    server.Get("/", [this](const httplib::Request& req,httplib::Response& res){
        res.set_content("Post Request", "application/json");
    });
}

InstapayServer* InstapayServer::getInstance() {
    if(InstapayServer::instance == nullptr){
        InstapayServer::instance = new InstapayServer();
    }
    return InstapayServer::instance;
}

void InstapayServer::run() {
    server.listen("localhost", 8080);
}


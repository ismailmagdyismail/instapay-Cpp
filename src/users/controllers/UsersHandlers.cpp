#include "UsersHandlers.hpp"
#include "../../../json/single_include/nlohmann/json.hpp"
#include "../usecase/UsersUsecase.hpp"

void UsersHandlers::handleSignup(
        const httplib::Request &request,
        httplib::Response &response,
        const std::unique_ptr<IUserDataAccess>& userDataAccess) {
    std::cout<<"Singing up\n";
}

void UsersHandlers::handleGetUserBalance(
        const httplib::Request &request,
        httplib::Response &response,
        const std::unique_ptr<IUserDataAccess>& userDataAccess
        ) {
    using json = nlohmann::json;
    json responseBody;
    std::string userName = request.get_param_value("userName");
    if(userName.empty()){
        response.status = 400;
        responseBody["status"] = "fail";
        responseBody["message"] = "must specify userName";
        response.set_content(responseBody.dump(),"applications/json");
        return;
    }
    auto balance = UsersUsecase::getUserBalance(userName,userDataAccess);
    if(!balance.has_value()){
        response.status = 404;
        responseBody["status"] = "fail";
        responseBody["message"] = "no user with that username exists";
        response.set_content(responseBody.dump(),"applications/json");
        return;
    }
    response.status = 200;
    responseBody["status"] = "success";
    responseBody["balance"] = balance.value();
    response.set_content(responseBody.dump(),"applications/json");
}
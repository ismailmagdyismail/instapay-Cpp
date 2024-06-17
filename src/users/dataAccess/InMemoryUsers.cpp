#include "InMemoryUsers.h"

unsigned int InMemoryUsers::getUsersCount() {
    return this->db.size();
}

std::optional<Response> InMemoryUsers::addUser(const std::unique_ptr<IUser>& newUser) {
    const std::string userName = newUser->getUserProfile().userName;
    if( this->db.find(userName) != this->db.end()){
        return Response{ false, 401, "user already exists with this data"};
    }
    this->db[userName] = newUser->clone();
    return {};
}


std::optional<std::unique_ptr<IUser>> InMemoryUsers::getUserByPhoneNumber(const std::string &phoneNumber) {
//    TODO:implement
    return {};
}

std::optional<std::unique_ptr<IUser>> InMemoryUsers::getUserByUserName(const std::string& userName) {
//    TODO:implement
    return {};
}
#pragma once
#ifndef USER_H
#define USER_H
#include <string>

class User {
protected:
    std::string id;
    std::string name;
	std::string password;
public:
    User();
    User(std::string id,std::string name, std::string password);

    void setID(std::string id);
    std::string getID();

    void setName(std::string name);
    std::string getName();

	void setPassword(std::string password);
	std::string getPassword();
};
User::User() {
    id = "0";
    name = "qwerty";
    password = "12345";
}
User::User(std::string id, std::string name, std::string password) {
    this->id = id;
    this->name = name;
    this->password = password;
}
void User::setID(std::string id) { this->id = id; }
std::string User::getID() { return id; }
void User::setName(std::string name) { this->name = name; }
std::string User::getName() { return name; }
void User::setPassword(std::string password) { this->password = password; }
std::string User::getPassword() { return password; }
#endif
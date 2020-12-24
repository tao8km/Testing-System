#pragma once
#include <string>

class User
{
	std::string name;
	std::string login;
	std::string password;

public:
	User(std::string name, std::string login, std::string password)
		: name{ name }, login{ login }, password{ password }
	{}
	bool isCorrect(std::string password) {
		return this->password == password;
	}
};


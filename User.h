#pragma once
#include <algorithm>
#include <string>

class User
{
	std::string name;
	std::string login;
	std::string password;

	std::string encrypt(std::string str) const {
		const int offset = 3;
		auto encryptor = [offset](char c) {
			return c + offset;
		};
		transform(str.begin(), str.end(), str.begin(), encryptor);
		return str;
	}

public:
	User(std::string name = {}, std::string login = {}, std::string password = {})
		: name{ name }, login{ login }, password{ encrypt(password) }
	{}
	bool isCorrect(std::string password) {
		return this->password == encrypt(password);
	}
	bool operator< (const User& other) const {
		return login < other.login;
	}
};


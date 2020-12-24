#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "User.h"
#include "Test.h"
using namespace std;

class MainApp
{
	map<string, User> users;
	bool isAdmin = false;
	map<string, vector<Test>> tests;

	void menu() {
		cout << "1 - Create test\n";
		cout << "2 - Create user\n";
		cout << "3 - Exit to main menu\n";
	}
	void createTest() {
		Test test;
		string filename;
		cout << "Enter name of file: ";
		cin >> filename;
		ifstream in(filename);
		if (in.is_open()) {
			string category;
			getline(in, category);
			in >> test;
			tests[category].push_back(move(test));
		}
	}
	void createUser() {
		string name, login, password;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> password;
		User user(name, login, password);
		users.emplace(make_pair(login, user));
	}
	void exitToMain() {
		while (!auth()) {
		}
	}
public:
	MainApp() {
		User admin("Vasya Admin", "admin", "123");
		users.emplace(make_pair("admin", admin));
	}

	void run() {
		//void (MainApp::*functions[])() = {
		//	&MainApp::menu, &MainApp::createTest, &MainApp::createUser, &MainApp::exitToMain
		//};
		bool running = true;
		while (running) {
			menu();
			int choice;
			cin >> choice;
			cout << "after\n";
			//if (choice >= 0 && choice < sizeof(functions)/sizeof(functions[0])) {
			//	functions[choice];
			//}
		}
	}

	bool auth() {
		cout << "Enter login: ";
		string login;
		cin >> login;
		cout << "Enter password: ";
		string password;
		cin >> password;

		auto it = users.find(login);
		if (it == users.end() || !it->second.isCorrect(password)) {
			return false;
		}
		isAdmin = login == "admin";
		return true;
	}
};


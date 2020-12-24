#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "User.h"
#include "Test.h"
using namespace std;

struct Statistics {
	vector<double> marks;
};

class MainApp
{
	map<string, User> users;
	bool isAdmin = false;
	map<string, vector<Test>> tests;
	map<User, Statistics> stats;
	User *currentUser = nullptr;

	void menu() {
		if (isAdmin) {
			cout << "1 - Create test\n";
			cout << "2 - Create user\n";
			cout << "3 - Exit to main menu\n";
		}
		else {
			cout << "1 - Start test\n";
			cout << "2 - Exit to main menu\n";
		}
	}
	void readTest(string filename) {
		Test test;
		ifstream in(filename);
		if (in.is_open()) {
			string category;
			getline(in, category);
			in >> test;
			tests[category].push_back(move(test));
		}
	}
	void createTest() {
		string filename;
		cout << "Enter name of file: ";
		cin >> filename;
		readTest(filename);
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
		stats.emplace(make_pair(user, Statistics{}));
	}
	void exitToMain() {
		while (!auth()) {
		}
	}
	void startTest() {
		for (const auto& p : tests) {
			cout << p.first << ": " << p.second.size() << '\n';
			int n;
			do {
				cout << "Enter test number: ";
				cin >> n;
			} while (n <= 0 || n > p.second.size());
			startTest(p.second[n-1]);
		}
	}
	void startTest(const Test& test) {
		int nCorrect = 0;
		for (int i = 0; i < test.getNumberOfQuestions(); i++) {
			const Question& q = test.getQuestion(i);
			cout << q << '\n';
			int n;
			do {
				cout << "Enter answer number: ";
				cin >> n;
			} while (n <= 0 || n > q.getNumberOfAnswers());
			if (n == q.getCorrect())
				++nCorrect;
		}
		double result = (double)nCorrect / test.getNumberOfQuestions();
		cout << "Result: " << result << endl;
		stats[*currentUser].marks.push_back(result);
	}
public:
	MainApp() {
		User admin("Vasya Admin", "admin", "123");
		users.emplace(make_pair("admin", admin));
		stats.emplace(make_pair(admin, Statistics{}));

		users.emplace(make_pair("user", User("Dima User", "user", "1")));
		stats.emplace(make_pair(users["user"], Statistics{}));

		readTest("input.txt");
	}

	void run() {
		void (MainApp::*functions[])() = {
			&MainApp::menu, &MainApp::createTest, &MainApp::createUser, &MainApp::exitToMain
		};
		void (MainApp::*user_functions[])() = {
			&MainApp::menu, &MainApp::startTest, &MainApp::exitToMain
		};
		bool running = true;
		while (running) {
			menu();
			int choice;
			cin >> choice;
			if (choice >= 0 && choice < sizeof(functions)/sizeof(functions[0])) {
				auto p = isAdmin ? functions[choice] : user_functions[choice];
				(this->*p)();
			}
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
		password.erase();
		isAdmin = login == "admin";
		currentUser = &it->second;
		return true;
	}
};


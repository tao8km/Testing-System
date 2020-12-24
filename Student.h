#pragma once
#include <string>
#include <iostream>

class Student
{
private:
	std::string name;
	int marks[10];
	int groupNum;

public:
	//Student();
	Student(std::string name, int groupNum);
	void print();

	void setName(std::string name) {
		this->name = name;
	}

	std::string getName() {
		return name;
	}

	void setGroupNum(int num) {
		groupNum = num;
	}

	int getGroupNum() {
		return groupNum;
	}

	void setMarks(const int marks[], int size) {
		for (int i = 0; i < size; i++) {
			this->marks[i] = marks[i];
		}
	}

	int getMark(int n) {
		return marks[n];
	}
};


#include "Student.h"

Student::Student() {
	for (int i = 0; i < 10; i++) {
		marks[i] = 0;
	}
}

Student::Student(std::string name, int groupNum) {
	this->name = name;
	for (int i = 0; i < 10; i++) {
		marks[i] = 0;
	}
	this->groupNum = groupNum;
}

void Student::print() {
	std::cout << name << std::endl;
	for (int i : marks) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

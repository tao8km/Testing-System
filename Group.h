#pragma once
#include <string>
#include "Student.h"

class Group
{
	Student** students;
	int count = 0;
	int capacity = 10;

public:
	Group() {
		students = new Student* [capacity];
		for (int i = 0; i < capacity; i++)
			students[i] = nullptr;
	}

	~Group() {
		for (int i = 0; i < count; i++)
			delete[] students[i];
		delete[] students;
	}

	void addStudent(Student* student) {
		if (count == capacity) {
			resize(capacity * 2);
		}

		students[count] = student;
		count++;
	}

	Student* findStudent(std::string name) {
		for (int i = 0; i < count; i++) {
			Student* stud = students[i];
			if (stud->getName() == name) {
				return stud;
			}
		}
		return nullptr;
	}

private:
	void resize(int newSize) {
		Student** temp = new Student * [newSize];
		for (int i = 0; i < count; i++) {
			temp[i] = students[i];
		}

		delete[] students;
		capacity = newSize;
		students = temp;
	}
};


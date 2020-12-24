#include "Student.h"
#include "Group.h"

Student* f() {
	Student* g = new Student [4] { Student("Vasya", 123), Student("Vasya", 123), Student("Vasya", 123) };
	for (int i = 0; i < 1000; i++) {
		if (g[i].getName() == "Vasya") {

		}
	}
	return g;
}

int main()
{
	Group group;
	group.addStudent(new Student("Vasya", 122));
	group.addStudent(new Student("Petya", 3334));
	group.addStudent(new Student("Vasya", 122));

	Student* stud = group.findStudent("Petya");
	if (stud != nullptr) {
		stud->print();
	}
}
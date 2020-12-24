#include "Test.h"

istream& operator>> (istream& in, Test& test) {
	Question q;
	while (in) {
		in >> q;
		test.addQuestion(q);
	}
	return in;
}

ostream& operator<< (ostream& out, const Test& test) {
	int i = 0;
	for (const auto& q : test.questions) {
		out << ++i << ") " << q << '\n';
	}
	return out;
}
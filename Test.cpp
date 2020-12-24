#include "Test.h"

istream& operator>> (istream& in, Test& test) {
	Question q;
	while (in) {
		in >> q;
		test.addQuestion(q);
	}
	return in;
}
#pragma once
#include "Question.h"

class Test
{
	vector<Question> questions;
public:
	void addQuestion(const Question& q) {
		questions.push_back(q);
	}
	const Question& getQuestion(int index) const {
		return questions.at(index);
	}
	int getNumberOfQuestions() const {
		return questions.size();
	}

	friend ostream& operator<< (ostream& out, const Test& test);
};

istream& operator>> (istream& in, Test& test);
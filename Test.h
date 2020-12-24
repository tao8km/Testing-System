#pragma once
#include "Question.h"

class Test
{
	vector<Question> questions;
public:
	void addQuestion(const Question& q) {
		questions.push_back(q);
	}
};

istream& operator>> (istream& in, Test& test);
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Question
{
	string question;
	vector<string> answers;
	int correct = 0;
public:
	Question(string q = {}, vector<string> ans = {}, int cor = {})
		: question{ q }, answers{ ans }, correct{ cor }
	{}

	void setQuestion(string q) { question = q; }
	void setAnswers(const vector<string>& a) { answers = a; }
	void setCorrect(int c) { correct = c; }
	friend ostream& operator<< (ostream& out, const Question& q);
	int getNumberOfAnswers() const {
		return answers.size();
	}
	int getCorrect() const {
		return correct;
	}
};

istream& operator>> (istream& in, Question& test);
#include "Question.h"

istream& operator>> (istream& in, Question& test) {
	string question;
	vector<string> answers;
	int correct = 0;

	if (in) {
		getline(in, question);
		char sign;
		for (int i = 1; in; i++) {
			in.get(sign);
			if (sign == '\n' || sign == '\r') { // \r\n
				break;
			}
			if (sign == '+')
				correct = i;
			string ans;
			getline(in, ans);
			if (!ans.empty())
				answers.push_back(ans);
		}
		test.setQuestion(question);
		test.setAnswers(answers);
		test.setCorrect(correct);
	}

	return in;
}

ostream& operator<< (ostream& out, const Question& q) {
	out << q.question << '\n';
	int i = 0;
	for (const auto& ans : q.answers) {
		out << ++i << ' ' << ans << '\n';
	}
	return out;
}
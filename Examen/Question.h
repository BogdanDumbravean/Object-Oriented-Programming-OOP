#pragma once
#include <string>
using namespace std;

class Question
{
private:
	int id;
	string text;
	string answer;
	int score;
public:
	Question(int id = 0, string txt = "", string answ = "", int score = 0);
	~Question();
	friend istream& operator>>(istream& o, Question& p);
	friend ostream& operator<<(ostream& o, Question& p);
	bool operator<(Question other);
	void setId(int id) {
		this->id = id;
	}
	void setText(string t) {
		text = t;
	}
	void setAnswer(string a) {
		answer = a;
	}
	void setScore(int s) {
		score = s;
	}
	int getId() {
		return id;
	}
	string getText() {
		return text;
	}
	string getAnswer() {
		return answer;
	}
	int getScore() {
		return score;
	}
};


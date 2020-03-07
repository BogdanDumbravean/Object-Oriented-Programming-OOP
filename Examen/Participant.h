#pragma once
#include <string>

using namespace std;

class Participant
{
private:
	string name;
	int score;
public:
	Participant(string name = "");
	~Participant();
	friend istream& operator>>(istream& o, Participant& p);
	friend ostream& operator<<(ostream& o, Participant& p);
	void setName(string n) {
		name = n;
	}
	void setScore(int s) {
		score = s;
	}
	string getName() {
		return name;
	}
	int getScore() {
		return score;
	}
};


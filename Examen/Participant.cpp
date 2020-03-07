#include "Participant.h"



Participant::Participant(string name):name(name) {
	score = 0;
}


Participant::~Participant()
{
}


istream& operator>>(istream& o, Participant& p) {
	string name;
	int score;
	o >> name >> score;
	p.setName(name);
	p.setScore(score);
	return o;
}

ostream & operator<<(ostream & o, Participant & p)
{
	o << p.name << ' ' << p.score;
	return o;
}

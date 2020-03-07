#include "Question.h"



Question::Question(int id, string txt, string answ, int score) : id(id), text(txt), answer(answ), score(score)
{
}


Question::~Question()
{
}

bool Question::operator<(Question other)
{
	return this->score > other.score;
}


istream& operator>>(istream& o, Question& q) {
	string text, answer;
	int id, score;
	o >> id >> text >> answer >> score;
	q.setId(id);
	q.setText(text);
	q.setAnswer(answer);
	q.setScore(score);
	return o;
}

ostream & operator<<(ostream & o, Question & q)
{
	o << q.id << ' ' << q.text << ' ' << q.answer << ' ' << q.score;
	return o;
}

#include "Examen.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Question.h"
#include "Participant.h"
#include <iostream>
#include <fstream>
#include <qDebug>
#include "Presenter.h"
#include "QtGuiClass.h"
#include <cassert>

using namespace std;


void test_add() {
	Repository<Question> r;

	Question q(1, "a", "b", 1);
	Question q2(2, "c", "r", 5);
	r.add(q);
	assert(r.getElems().size() == 1);
	r.add(q2);
	assert(r.getElems().size() == 2);
	assert(r.getElems()[0].getId() == 1);
}


void test_addScore() {

	Repository<Participant> r;

	Participant p("name");
	Participant p2("name2");
	r.add(p);
	r.add(p2);
	r.addScore(p, 10);
	assert(r.getElems()[0].getScore() == 10);
	r.addScore(p, 5);
	assert(r.getElems()[0].getScore() == 15);
	r.addScore(p2, 5);
	assert(r.getElems()[1].getScore() == 5);
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	//test_add();
	//test_addScore();

	Repository<Question> repoQ("D://Info//Proiecte_Info//OOP//Examen//q.txt");
	Repository<Participant> repoP("D://Info//Proiecte_Info//OOP//Examen//p.txt");

	Presenter p(repoQ);
	p.show();

	QtGuiClass** parts = new QtGuiClass*[20];
	
	for (int i = 0; i < repoP.getElems().size(); ++i) {
		parts[i] = new QtGuiClass(repoQ, repoP);
		parts[i]->setWindowTitle(QString::fromStdString(repoP.getElems()[i].getName()));
		parts[i]->show();
		repoQ.addObs(parts[i]);
	}
	
	return a.exec();
}

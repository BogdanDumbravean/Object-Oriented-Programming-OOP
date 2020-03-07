#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "Repository.h"
#include "Observer.h"

class QtGuiClass : public QWidget, public Observer
{
	Q_OBJECT

public:
	QtGuiClass(Repository<Question>& qrepo, Repository<Participant>& prepo, QWidget *parent = Q_NULLPTR);
	~QtGuiClass();

private:
	Repository<Question>& qrepo;
	Repository<Participant>& prepo;
	vector<int> answeredId;

	Ui::QtGuiClass ui;
	void populateList();
	void update() override;
	void answer();
	void controlAnswerButton();
};

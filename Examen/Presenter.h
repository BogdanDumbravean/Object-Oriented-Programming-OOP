#pragma once

#include <QWidget>
#include "ui_Presenter.h"
#include "Repository.h"
#include "Observer.h"

class Presenter : public QWidget
{
	Q_OBJECT

public:
	Presenter(Repository<Question>& r, QWidget *parent = Q_NULLPTR);
	~Presenter();
	void populateList();
private:
	Repository<Question>& qrepo;
	Ui::Presenter ui;
private slots:
	void add();
};

#include "Presenter.h"
#include <QListWidgetItem>
#include <QPushButton>
#include <qmessagebox.h>

Presenter::Presenter(Repository<Question>& r, QWidget *parent)
	: QWidget(parent), qrepo(r)
{
	ui.setupUi(this);
	populateList();
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &Presenter::add);
}

Presenter::~Presenter()
{
	qrepo.writeToFile();
}

void Presenter::add() {
	Question q;

	for (auto q : qrepo.getElems()) 
		if (q.getId() == ui.lineEdit->text().toInt()) {
			QMessageBox::warning(this, "Invalid", "ID exists");
			return;
		}

	if (ui.lineEdit_2->text().isEmpty()) {
		QMessageBox::warning(this, "Invalid", "Invalid input");
		return;
	}

	q.setId(ui.lineEdit->text().toInt());
	q.setText(ui.lineEdit_2->text().toStdString());
	q.setAnswer(ui.lineEdit_3->text().toStdString());
	q.setScore(ui.lineEdit_4->text().toInt());
	qrepo.add(q);
	qrepo.notify();
	populateList();
}

bool cmp(Question a, Question b) {
	return a.getId() < b.getId();
}

void Presenter::populateList()
{
	if (this->ui.listWidget->count() > 0)
		this->ui.listWidget->clear();

	std::vector<Question> sortedQ = qrepo.getElems();
	std::sort(sortedQ.begin(), sortedQ.end(), cmp);

	for (auto q : sortedQ)
	{
		QString itemInList = QString::number(q.getId()) + ' ' + QString::fromStdString(q.getText()) + ' ' + QString::fromStdString(q.getAnswer()) + ' ' + QString::number(q.getScore());
		QListWidgetItem *item = new QListWidgetItem(itemInList);
		this->ui.listWidget->addItem(item);
	}

	if (this->ui.listWidget->count() > 0)
		this->ui.listWidget->setCurrentRow(0);

}
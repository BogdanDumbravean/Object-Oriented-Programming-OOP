#include "QtGuiClass.h"
#include <QListWidgetItem>
#include <vector>
#include <algorithm>
#include <string>

QtGuiClass::QtGuiClass(Repository<Question>& qrepo, Repository<Participant>& prepo, QWidget *parent)
	: QWidget(parent), qrepo(qrepo), prepo(prepo)
{
	ui.setupUi(this);
	populateList();
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &QtGuiClass::answer);
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, &QtGuiClass::controlAnswerButton);
}

QtGuiClass::~QtGuiClass()
{
}

void QtGuiClass::populateList()
{
	if (this->ui.listWidget->count() > 0)
		this->ui.listWidget->clear();

	std::vector<Question> sortedQ = qrepo.getElems();
	std::sort(sortedQ.begin(), sortedQ.end());

	for (auto q : sortedQ)
	{
		QString itemList = QString::number(q.getId()) + ' ' + QString::fromStdString(q.getText()) + ' ' + QString::number(q.getScore());
		QListWidgetItem *item = new QListWidgetItem(itemList);
		for (auto id : answeredId)
			if (id == q.getId())
				item->setBackground(Qt::green);

		this->ui.listWidget->addItem(item);
	}

	if (this->ui.listWidget->count() > 0)
		this->ui.listWidget->setCurrentRow(0);

}

void QtGuiClass::update()
{
	populateList();
}

void QtGuiClass::answer() {
	QListWidgetItem* item = ui.listWidget->selectedItems()[0];
	string answer = ui.lineEdit->text().toStdString();
	int nr = stoi(item->text().toStdString().substr(0, item->text().toStdString().find(" ")));
	
	int score = 0;
	for (auto& q : qrepo.getElems())
		if (nr == q.getId() && answer == q.getAnswer())
			score = q.getScore();

	for (auto& p : prepo.getElems())
		if (p.getName() == this->windowTitle().toStdString()) {
			ui.label->setText(QString::number(p.getScore() + score));
			prepo.addScore(p, score);
		}

	answeredId.push_back(nr);
	populateList();
}

void QtGuiClass::controlAnswerButton()
{
	QList<QListWidgetItem*> item = ui.listWidget->selectedItems();
	if (item.size() == 0)
		return;

	string answer = ui.lineEdit->text().toStdString();
	int nr = stoi(item[0]->text().toStdString().substr(0, item[0]->text().toStdString().find(" ")));
	for (auto i : answeredId) 
		if (i == nr) {
			ui.pushButton->setDisabled(true);
			return;
		}
	ui.pushButton->setDisabled(false);
}

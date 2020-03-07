#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Examen.h"

class Examen : public QMainWindow
{
	Q_OBJECT

public:
	Examen(QWidget *parent = Q_NULLPTR);

private:
	Ui::ExamenClass ui;
};

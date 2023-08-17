#pragma once

#include <QMainWindow>
#include "ui_SignUpWindow.h"
#include "Service.h"



class SignUpWindow : public QMainWindow
{
	Q_OBJECT

public:
	SignUpWindow(Service& serv, QWidget *parent = nullptr);
	~SignUpWindow();

private:
	Service& service;
	Ui::SignUpWindowClass ui;

	void initSingUpWindow();
	void signUpUser();
	void connectSignalsAndSlots();
};

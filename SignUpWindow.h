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
	void setParent(QWidget* w);
private:
	Service& service;
	Ui::SignUpWindowClass ui;
	QWidget* logInWindow;
	void initSignUpWindow();
	void signUpUser();
	void connectSignalsAndSlots();
};

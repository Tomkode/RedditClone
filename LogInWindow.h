#pragma once

#include <QMainWindow>
#include "ui_LogInWindow.h"
#include <QMessageBox>
#include "Service.h"
#include "MyLineEdit.h"
class LogInWindow : public QMainWindow
{
	Q_OBJECT

public:
	LogInWindow(Service& serv, QWidget *parent = nullptr);
	~LogInWindow();
	void setChild(QWidget* w);

private:
	MyLineEdit* userNameLineEdit;
	MyLineEdit* passwordLineEdit;
	QLabel* errorLabel;
	Ui::LogInWindowClass ui;
	QWidget* signUpWindow;
	Service& service;
	void initLogInWindow();
	void connectSignalsAndSlots();
	void logIn();
	void signUp();
	void lineEditClicked(bool hasFocus, MyLineEdit* lineEdit);
};

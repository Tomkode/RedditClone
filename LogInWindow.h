#pragma once

#include <QMainWindow>
#include "ui_LogInWindow.h"
#include <QMessageBox>
#include "Service.h"
class LogInWindow : public QMainWindow
{
	Q_OBJECT

public:
	LogInWindow(Service& serv, QWidget *parent = nullptr);
	~LogInWindow();
	void setChild(QWidget* w);

private:
	Ui::LogInWindowClass ui;
	QWidget* signUpWindow;
	Service& service;
	void initLogInWindow();
	void connectSignalsAndSlots();
	void logIn();
	void signUp();
};

#pragma once

#include <QMainWindow>
#include "ui_LogInWindow.h"
class LogInWindow : public QMainWindow
{
	Q_OBJECT

public:
	LogInWindow(QWidget *parent = nullptr);
	~LogInWindow();
	void setChild(QWidget* w);

private:
	Ui::LogInWindowClass ui;
	QWidget* signUpWindow;
	void initLogInWindow();
	void connectSignalsAndSlots();
	void logIn();
	void signUp();
};

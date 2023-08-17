#pragma once

#include <QMainWindow>
#include "ui_LogInWindow.h"
#include <string.h>

class LogInWindow : public QMainWindow
{
	Q_OBJECT

public:
	LogInWindow(QWidget *parent = nullptr);
	~LogInWindow();

private:
	Ui::LogInWindowClass ui;
	void initLogInWindow();
	void connectSignalsAndSlots();
	void logIn();
};

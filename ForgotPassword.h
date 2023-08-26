#pragma once

#include <QWidget>
#include "ui_ForgotPassword.h"
#include "MyLineEdit.h"
#include "Service.h"

class ForgotPassword : public QWidget
{
	Q_OBJECT

public:
	ForgotPassword(Service& serv, QWidget *parent = nullptr);
	~ForgotPassword();

private:
	Ui::ForgotPasswordClass ui;
	void initWindow();
	void connectSignalsAndSlots();
	void resetPassword();
	void passwordChecker();
	void userNameChecker();
	void resetCodeChecker();
	void emailChecker();

	Service& service;
	std::vector<int> windowChanges;

	MyLineEdit* userNameLineEdit;
	MyLineEdit* emailLineEdit;
	MyLineEdit* passwordLineEdit;
	MyLineEdit* resetCodeLineEdit;

	QLabel* userNameErrorLabel;
	QLabel* passwordErrorLabel;
	QLabel* resetCodeErrorLabel;
	QLabel* emailErrorLabel;
};

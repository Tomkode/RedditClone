#pragma once

#include <QMainWindow>
#include "ui_SignUpWindow.h"
#include "Service.h"
#include "MyLineEdit.h"
class SignUpWindow : public QMainWindow
{
	Q_OBJECT

public:
	SignUpWindow(Service& serv, QWidget *parent = nullptr);
	~SignUpWindow();
	void setParent(QWidget* w);
private:
	MyLineEdit* userNameLineEdit;
	MyLineEdit* passwordLineEdit;
	MyLineEdit* confirmPasswordLineEdit;
	MyLineEdit* emailLineEdit;
	MyLineEdit* passwordResetCodeLineEdit;
	QLabel* userNameErrorLabel;
	QLabel* emailErrorLabel;
	QLabel* passwordErrorLabel;
	QLabel* confirmPasswordErrorLabel;
	QLabel* passwordResetCodeErrorLabel;
	std::vector<int> windowChanges;

	Service& service;
	Ui::SignUpWindowClass ui;
	QWidget* logInWindow;
	void initSignUpWindow();
	void signUpUser();
	void connectSignalsAndSlots();
	void switchWindows();
	void lineEditClicked(bool hasFocus, MyLineEdit* lineEdit);
	void passwordChecker();
	void userNameChecker();
	void emailChecker();
	void confirmPasswordChecker();
	void resetCodeChecker();
};

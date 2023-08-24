#include "SignUpWindow.h"
using namespace std;
SignUpWindow::SignUpWindow(Service& serv, QWidget* parent)
	: QMainWindow(parent), service{ serv }
{
	ui.setupUi(this);
	initSignUpWindow();
	connectSignalsAndSlots();
}

SignUpWindow::~SignUpWindow()
{}

void SignUpWindow::setParent(QWidget* w)
{
	this->logInWindow = w;
}


void SignUpWindow::initSignUpWindow()
{
	QPixmap pixmap("images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);
	passwordLineEdit = new MyLineEdit();
	confirmPasswordLineEdit = new MyLineEdit();
	emailLineEdit = new MyLineEdit();
	userNameLineEdit = new MyLineEdit();
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
	userNameLineEdit->setPlaceholderText("Username");
	passwordLineEdit->setPlaceholderText("Password");
	emailLineEdit->setPlaceholderText("Email");
	confirmPasswordLineEdit->setPlaceholderText("Confirm Password");
	userNameLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	passwordLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	confirmPasswordLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	emailLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");

	QSize lineEditSize(100, 30);
	passwordLineEdit->setMinimumSize(lineEditSize);
	userNameLineEdit->setMinimumSize(lineEditSize);
	emailLineEdit->setMinimumSize(lineEditSize);
	confirmPasswordLineEdit->setMinimumSize(lineEditSize);
	this->ui.lineEditLayout->addWidget(userNameLineEdit);
	this->ui.lineEditLayout->addWidget(passwordLineEdit);
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

}

void SignUpWindow::signUpUser()
{
	//clear the error labels 69
	this->ui.userNameErrorLabel->setText("");
	this->ui.emailErrorLabel->setText("");
	this->ui.passwordErrorLabel->setText("");
	this->ui.confirmPasswordErrorLabel->setText("");
	string userName = this->userNameLineEdit->text().toLocal8Bit().constData();
	string password = this->passwordLineEdit->text().toLocal8Bit().constData();
	string email = this->emailLineEdit->text().toLocal8Bit().constData();
	string confirmPassword = this->confirmPasswordLineEdit->text().toLocal8Bit().constData();
	try {
		service.createUserAccount(userName, password, confirmPassword, email);

		//clear line edits

		this->switchWindows();
	}
	catch (InvalidUsernameException& err) {
		this->ui.userNameErrorLabel->setText(err.what());
	}
	catch (InvalidPasswordException& err) {
		this->ui.passwordErrorLabel->setText(err.what());
	}
	catch (InvalidEmailException& err) {
		this->ui.emailErrorLabel->setText(err.what());
	}
	catch (DifferentPasswordsException& err) {
		this->ui.confirmPasswordErrorLabel->setText(err.what());
	}
	catch (ExistentUsernameException& err)
	{
		this->ui.userNameErrorLabel->setText(err.what());
	}
	catch (ExistentEmailException& err)
	{
		this->ui.emailErrorLabel->setText(err.what());
	}
	catch (exception& err)
	{
		this->ui.generalErrorLabel->setText("Unknown Error");
	}
	//after creating the account,close this window and redirect the user to the login window

}

void SignUpWindow::connectSignalsAndSlots()
{
	connect(this->ui.signUpButton, &QPushButton::clicked, this, &SignUpWindow::signUpUser);
	connect(this->ui.logInButton, &QPushButton::clicked, this, &SignUpWindow::switchWindows);
	connect(this->passwordLineEdit, &MyLineEdit::focussed, this, &SignUpWindow::lineEditClicked);
	connect(this->userNameLineEdit, &MyLineEdit::focussed, this, &SignUpWindow::lineEditClicked);
	connect(this->confirmPasswordLineEdit, &MyLineEdit::focussed, this, &SignUpWindow::lineEditClicked);
	connect(this->emailLineEdit, &MyLineEdit::focussed, this, &SignUpWindow::lineEditClicked);
}

void SignUpWindow::switchWindows()
{
	this->userNameLineEdit->clear();
	this->passwordLineEdit->clear();
	this->emailLineEdit->clear();
	this->confirmPasswordLineEdit->clear();
	this->logInWindow->show();
	this->hide();
}

void SignUpWindow::lineEditClicked(bool hasFocus, MyLineEdit* lineEdit)
{
	if (hasFocus)
		lineEdit->setStyleSheet("QLineEdit{border: 1px solid #d93a00;border-radius: 13px;}");
	else
		lineEdit->setStyleSheet("QLineEdit{ border: 1px solid #808080; border-radius: 13px; }");
}

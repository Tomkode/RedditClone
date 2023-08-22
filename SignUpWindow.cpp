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
	ui.passwordLineEdit->setEchoMode(QLineEdit::Password);
	ui.confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
}

void SignUpWindow::signUpUser()
{
	//clear the error labels 69
	this->ui.userNameErrorLabel->setText("");
	this->ui.emailErrorLabel->setText("");
	this->ui.passwordErrorLabel->setText("");
	this->ui.confirmPasswordErrorLabel->setText("");
	string userName = this->ui.userNameLineEdit->text().toLocal8Bit().constData();
	string password = this->ui.passwordLineEdit->text().toLocal8Bit().constData();
	string email = this->ui.emailLineEdit->text().toLocal8Bit().constData();
	string confirmPassword = this->ui.confirmPasswordLineEdit->text().toLocal8Bit().constData();
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
}

void SignUpWindow::switchWindows()
{
	this->ui.userNameLineEdit->clear();
	this->ui.passwordLineEdit->clear();
	this->ui.emailLineEdit->clear();
	this->ui.confirmPasswordLineEdit->clear();
	this->logInWindow->show();
	this->hide();
}

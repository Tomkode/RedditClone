#include "LogInWindow.h"
#include <QPixmap>

using namespace std;

LogInWindow::LogInWindow(Service& serv, QWidget* parent)
	: QMainWindow(parent), service(serv)
{
	ui.setupUi(this);
	this->initLogInWindow();
}

LogInWindow::~LogInWindow()
{}

void LogInWindow::setChild(QWidget* w) {
	this->signUpWindow = w;
}

void LogInWindow::initLogInWindow()
{
	QPixmap pixmap("images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);
	ui.passwordLineEdit->setEchoMode(QLineEdit::Password);
	connectSignalsAndSlots();
}

void LogInWindow::connectSignalsAndSlots()
{
	connect(this->ui.logInButton, &QAbstractButton::clicked, this, &LogInWindow::logIn);
	connect(this->ui.signUpButton, &QAbstractButton::clicked, this, &LogInWindow::signUp);
}

void LogInWindow::logIn()
{
	this->ui.errorLabel->setText("");
	string userName = this->ui.userNameLineEdit->text().toLocal8Bit().constData();
	string password = this->ui.passwordLineEdit->text().toLocal8Bit().constData();
	if (userName == "" || password == "")
	{
		this->ui.errorLabel->setText("You must fill in both fields!");
		return;
	}
	try {
		service.verifyAccountCredentials(userName, service.hashToSHA256(password));
		this->ui.errorLabel->setText("Granted access!");
	}
	catch (InexistentAcccountException& err) {
		this->ui.errorLabel->setText("The account doesn't exist.Create one or reset your password!");
	}

}

void LogInWindow::signUp()
{
	this->ui.userNameLineEdit->clear();
	this->ui.passwordLineEdit->clear();
	this->signUpWindow->show();
	this->hide();
}
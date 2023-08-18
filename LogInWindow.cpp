#include "LogInWindow.h"
#include <QPixmap>

using namespace std;

LogInWindow::LogInWindow(QWidget *parent)
	: QMainWindow(parent)
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
	string userName = this->ui.userNameLineEdit->text().toStdString();
	string password = this->ui.passwordLineEdit->text().toStdString();
}

void LogInWindow::signUp()
{
	this->signUpWindow->show();
	this->hide();
}

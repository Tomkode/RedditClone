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

void LogInWindow::initLogInWindow()
{
	QPixmap pixmap("images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);

	connectSignalsAndSlots();
}

void LogInWindow::connectSignalsAndSlots()
{
	connect(this->ui.logInButton, &QAbstractButton::clicked, this, &LogInWindow::logIn);
}

void LogInWindow::logIn()
{
	string userName = this->ui.userNameLineEdit->text().toStdString();
	string password = this->ui.passwordLineEdit->text().toStdString();
}

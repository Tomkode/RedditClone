#include "SignUpWindow.h"
using namespace std;
SignUpWindow::SignUpWindow(Service& serv, QWidget *parent)
	: QMainWindow(parent), service{serv}
{
	ui.setupUi(this);
}

SignUpWindow::~SignUpWindow()
{}

void SignUpWindow::initSingUpWindow()
{
	QPixmap pixmap("images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);

	connectSignalsAndSlots();
}

void SignUpWindow::signUpUser()
{
	string userName = this->ui.userNameLineEdit->text().toStdString();
	string password = this->ui.passwordLineEdit->text().toStdString();
	string email = this->ui.emailLineEdit->text().toStdString();
	service.createUserAccount(userName, password, email);
}

void SignUpWindow::connectSignalsAndSlots()
{
	connect(this->ui.signUpButton, &QPushButton::clicked, this, &SignUpWindow::signUpUser);
}

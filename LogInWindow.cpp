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

void LogInWindow::setForgotPasswordWindow(QWidget* w)
{
	this->forgotPasswordWindow = w;
}

void LogInWindow::initLogInWindow()
{
	QPixmap pixmap("images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);
	userNameLineEdit = new MyLineEdit();
	passwordLineEdit = new MyLineEdit();
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	userNameLineEdit->setPlaceholderText("Username");
	passwordLineEdit->setPlaceholderText("Password");
	userNameLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	passwordLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");

	QSize lineEditSize(100, 30);
	passwordLineEdit->setMinimumSize(lineEditSize);
	userNameLineEdit->setMinimumSize(lineEditSize);
	this->ui.lineEditLayout->addWidget(userNameLineEdit);
	this->ui.lineEditLayout->addWidget(passwordLineEdit);
	errorLabel = nullptr;
	connectSignalsAndSlots();

}

void LogInWindow::connectSignalsAndSlots()
{
	connect(this->ui.logInButton, &QAbstractButton::clicked, this, &LogInWindow::logIn);
	connect(this->ui.signUpButton, &QAbstractButton::clicked, this, &LogInWindow::signUp);
	connect(this->passwordLineEdit, &MyLineEdit::focussed, this, &LogInWindow::lineEditClicked);
	connect(this->userNameLineEdit, &MyLineEdit::focussed, this, &LogInWindow::lineEditClicked);
	connect(this->ui.forgotPasswordLabel, &ClickableLabel::clicked, this, &LogInWindow::forgotPassword);

}

void LogInWindow::logIn()
{
	if (errorLabel != nullptr)
	{
		delete errorLabel;
		errorLabel = nullptr;
	}
	string username = this->userNameLineEdit->text().toLocal8Bit().constData();
	string password = this->passwordLineEdit->text().toLocal8Bit().constData();
	if (username == "" || password == "")
	{
		errorLabel = new QLabel();
		this->ui.buttonsLayout->insertWidget(0, errorLabel);
		errorLabel->setText("You must fill in both fields!");
		return;
	}
	try {
		service.verifyAccountCredentials(username, service.hashToSHA256(password));
		errorLabel = new QLabel();
		this->ui.buttonsLayout->insertWidget(0, errorLabel);
		errorLabel->setText("Granted access!");
	}
	catch (InexistentAcccountException& err) {
		errorLabel = new QLabel();
		this->ui.buttonsLayout->insertWidget(0, errorLabel);
		errorLabel->setText("We couldn't verify your account.");
	}

}

void LogInWindow::signUp()
{
	this->userNameLineEdit->clear();
	this->passwordLineEdit->clear();
	if (errorLabel != nullptr)
	{
		delete errorLabel;
		errorLabel = nullptr;
	}
	this->signUpWindow->show();
	this->hide();
}

void LogInWindow::lineEditClicked(bool hasFocus, MyLineEdit* lineEdit)
{
	if (hasFocus)
		lineEdit->setStyleSheet("QLineEdit{border: 1px solid #d93a00;border-radius: 13px;}");
	else
		lineEdit->setStyleSheet("QLineEdit{ border: 1px solid #808080; border-radius: 13px; }"); 
}

void LogInWindow::forgotPassword()
{
	this->forgotPasswordWindow->show();
}

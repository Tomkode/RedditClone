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
	this->ui.lineEditLayout->addWidget(emailLineEdit);
	this->ui.lineEditLayout->addWidget(passwordLineEdit);
	this->ui.lineEditLayout->addWidget(confirmPasswordLineEdit);
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);


	userNameErrorLabel = nullptr;
	passwordErrorLabel = nullptr;
	emailErrorLabel = nullptr;
	confirmPasswordErrorLabel = nullptr;

}

void SignUpWindow::signUpUser()
{
	
	if (userNameErrorLabel != nullptr) {
		delete userNameErrorLabel;
		userNameErrorLabel = nullptr;
	}
		if (passwordErrorLabel != nullptr) {
			delete passwordErrorLabel;
			passwordErrorLabel = nullptr;
		}
		if (emailErrorLabel != nullptr) {
			delete emailErrorLabel;
			emailErrorLabel = nullptr;
		}
		if (confirmPasswordErrorLabel != nullptr) {
			delete confirmPasswordErrorLabel;
			confirmPasswordErrorLabel = nullptr;
		}
	
	/*this->emailErrorLabel->setText("");
	this->passwordErrorLabel->setText("");
	this->confirmPasswordErrorLabel->setText("");*/
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
		userNameErrorLabel = new QLabel;
		userNameErrorLabel->setWordWrap(1);
		this->userNameErrorLabel->setText(err.what());
		this->ui.lineEditLayout->insertWidget(1, userNameErrorLabel);
	}
	catch (ExistentUsernameException& err)
	{
		userNameErrorLabel = new QLabel;
		userNameErrorLabel->setWordWrap(1);
		this->userNameErrorLabel->setText(err.what());
		this->ui.lineEditLayout->insertWidget(1, userNameErrorLabel);
	}
	catch (InvalidEmailException& err) {
		emailErrorLabel = new QLabel;
		emailErrorLabel->setWordWrap(1);
		this->emailErrorLabel->setText(err.what());
		this->ui.lineEditLayout->insertWidget(2, emailErrorLabel);
	}
	catch (ExistentEmailException& err)
	{
		emailErrorLabel = new QLabel;
		emailErrorLabel->setWordWrap(1);
		this->emailErrorLabel->setText(err.what());
		this->ui.lineEditLayout->insertWidget(2, emailErrorLabel);
	}
	catch (InvalidPasswordException& err) {
		passwordErrorLabel = new QLabel;
		passwordErrorLabel->setWordWrap(1);
		this->passwordErrorLabel->setText(err.what());
		this->ui.lineEditLayout->insertWidget(3, passwordErrorLabel);
	}
	
	catch (DifferentPasswordsException& err) {
		confirmPasswordErrorLabel = new QLabel;
		confirmPasswordErrorLabel->setWordWrap(1);
		this->confirmPasswordErrorLabel->setText(err.what());
		this->ui.lineEditLayout->insertWidget(4, confirmPasswordErrorLabel);
	}	
	catch (exception& err)
	{
		/*this->.generalErrorLabel->setText("Unknown Error");*/
		;
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

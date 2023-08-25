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
	this->ui.userNameLayout->addWidget(userNameLineEdit);
	this->ui.emailLayout->addWidget(emailLineEdit);
	this->ui.passwordLayout->addWidget(passwordLineEdit);
	this->ui.confirmPasswordLayout->addWidget(confirmPasswordLineEdit);
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);


	userNameErrorLabel = nullptr;
	passwordErrorLabel = nullptr;
	emailErrorLabel = nullptr;
	confirmPasswordErrorLabel = nullptr;


	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
}

void SignUpWindow::signUpUser()
{
	// **************************************************************************************
	// This function should be redone to call functions like passwordChecker from this window
	//
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
		this->ui.userNameLayout->insertWidget(1, userNameErrorLabel);
		QSize size = this->userNameErrorLabel->size();
		this->setFixedHeight(size.height());
	}
	catch (ExistentUsernameException& err)
	{
		userNameErrorLabel = new QLabel;
		userNameErrorLabel->setWordWrap(1);
		this->userNameErrorLabel->setText(err.what());
		this->ui.userNameLayout->insertWidget(1, userNameErrorLabel);
		QSize size = this->userNameErrorLabel->size();
		this->setFixedHeight(size.height());
	}
	catch (InvalidEmailException& err) {
		emailErrorLabel = new QLabel;
		emailErrorLabel->setWordWrap(1);
		this->emailErrorLabel->setText(err.what());
		this->ui.emailLayout->insertWidget(1, emailErrorLabel);
		QSize size = this->emailErrorLabel->size();
		this->setFixedHeight(size.height());
	}
	catch (ExistentEmailException& err)
	{
		emailErrorLabel = new QLabel;
		emailErrorLabel->setWordWrap(1);
		this->emailErrorLabel->setText(err.what());
		this->ui.emailLayout->insertWidget(1, emailErrorLabel);
		QSize size = this->emailErrorLabel->size();
		this->setFixedHeight(size.height());
	}
	catch (InvalidPasswordException& err) {
		passwordErrorLabel = new QLabel;
		passwordErrorLabel->setWordWrap(1);
		this->passwordErrorLabel->setText(err.what());
		this->ui.passwordLayout->insertWidget(1, passwordErrorLabel);
		QSize size = this->passwordErrorLabel->size();
		this->setFixedHeight(size.height());
	}
	
	catch (DifferentPasswordsException& err) {
		confirmPasswordErrorLabel = new QLabel;
		confirmPasswordErrorLabel->setWordWrap(1);
		this->confirmPasswordErrorLabel->setText(err.what());
		this->ui.confirmPasswordLayout->insertWidget(1, confirmPasswordErrorLabel);
		QSize size = this->passwordErrorLabel->size();
		this->setFixedHeight(size.height());
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
	
	connect(this->userNameLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::userNameChecker);
	connect(this->emailLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::emailChecker);
	connect(this->passwordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::passwordChecker);
	connect(this->passwordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::confirmPasswordChecker);
	connect(this->confirmPasswordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::confirmPasswordChecker);
	connect(this->confirmPasswordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::passwordChecker);

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

void SignUpWindow::passwordChecker()
{

	if (passwordErrorLabel != nullptr) {
		delete passwordErrorLabel;
		passwordErrorLabel = nullptr;
	}
	//validations for username, password and email
	string password = this->passwordLineEdit->text().toStdString();
	try {
		service.verifyPassword(password);
		//undo the resize cause by the errorLabel69
		this->setFixedHeight(this->size().height() - windowChanges[2]);
		windowChanges[2] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		passwordErrorLabel = new QLabel;
		passwordErrorLabel->setWordWrap(1);
		this->passwordErrorLabel->setText(err.what());
		this->passwordErrorLabel->setStyleSheet("color:#ff3333");
		this->ui.passwordLayout->insertWidget(1, passwordErrorLabel);

		//resize the window only once after adding the errorLabel
		if (windowChanges[2]==0) {
			QSize size = this->passwordErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[2] = size.height();
		}
	}
	catch (exception& err)
	{
		
		;
	}
	
}

void SignUpWindow::userNameChecker()
{
	
	if (userNameErrorLabel != nullptr) {
		
		delete userNameErrorLabel;
		userNameErrorLabel = nullptr;
	}
	//validations for username, password and email
	string userName = this->userNameLineEdit->text().toStdString();
	try {
		service.verifyUsername(userName);
		this->setFixedHeight(this->size().height() - windowChanges[0]);
		windowChanges[0] = 0;
	}
	catch (IncorrectCredentialsException& err)
	{
		userNameErrorLabel = new QLabel;
		userNameErrorLabel->setWordWrap(1);
		this->userNameErrorLabel->setText(err.what());
		this->userNameErrorLabel->setStyleSheet("color:#ff3333");
		this->ui.userNameLayout->insertWidget(1, userNameErrorLabel);
		if (windowChanges[0] == 0) {
			QSize size = this->userNameErrorLabel->sizeHint();
			this->setFixedHeight(size.height()+this->size().height());
			windowChanges[0] = size.height();
		}
	}
	catch (exception& err)
	{
		;
	}
}

void SignUpWindow::emailChecker()
{
	if (emailErrorLabel != nullptr) {
		delete emailErrorLabel;
		emailErrorLabel = nullptr;
	}
	//validations for username, password and email
	string email = this->emailLineEdit->text().toStdString();
	try {
		service.verifyEmail(email);


		this->setFixedHeight(this->size().height() - windowChanges[1]);
		windowChanges[1] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		emailErrorLabel = new QLabel;
		emailErrorLabel->setWordWrap(1);
		this->emailErrorLabel->setText(err.what());
		this->emailErrorLabel->setStyleSheet("color:#ff3333");
		this->ui.emailLayout->insertWidget(1, emailErrorLabel);
		if (windowChanges[1] == 0) {
			QSize size = this->emailErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[1] = size.height();
		}
	}
	catch (exception& err)
	{
		;
	}
}

void SignUpWindow::confirmPasswordChecker()
{
	if (confirmPasswordErrorLabel != nullptr) {
		delete confirmPasswordErrorLabel;
		confirmPasswordErrorLabel = nullptr;
	}
	string confirmPassword = this->confirmPasswordLineEdit->text().toStdString();
	string password = this->passwordLineEdit->text().toStdString();

	try {
		service.verifyConfirmPassword(password, confirmPassword);
		this->setFixedHeight(this->size().height() - windowChanges[3]);
		windowChanges[3] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		confirmPasswordErrorLabel = new QLabel;
		confirmPasswordErrorLabel->setWordWrap(1);
		this->confirmPasswordErrorLabel->setText(err.what());
		this->confirmPasswordErrorLabel->setStyleSheet("color:#ff3333");
		this->ui.confirmPasswordLayout->insertWidget(1, confirmPasswordErrorLabel);
		if (windowChanges[3] == 0) {
			QSize size = this->confirmPasswordErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[3] = size.height();
		}
	}
	catch (exception& err)
	{
		;
	}
}

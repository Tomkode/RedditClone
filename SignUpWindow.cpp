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
	passwordResetCodeLineEdit = new MyLineEdit();
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
	userNameLineEdit->setPlaceholderText("Username");
	passwordLineEdit->setPlaceholderText("Password");
	passwordResetCodeLineEdit->setPlaceholderText("Reset Password Code");
	emailLineEdit->setPlaceholderText("Email");
	confirmPasswordLineEdit->setPlaceholderText("Confirm Password");
	userNameLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	passwordLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	confirmPasswordLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	emailLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	passwordResetCodeLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");

	QSize lineEditSize(100, 30);
	passwordLineEdit->setMinimumSize(lineEditSize);
	userNameLineEdit->setMinimumSize(lineEditSize);
	emailLineEdit->setMinimumSize(lineEditSize);
	confirmPasswordLineEdit->setMinimumSize(lineEditSize);
	passwordResetCodeLineEdit->setMinimumSize(lineEditSize);
	this->ui.userNameLayout->addWidget(userNameLineEdit);
	this->ui.emailLayout->addWidget(emailLineEdit);
	this->ui.passwordLayout->addWidget(passwordLineEdit);
	this->ui.confirmPasswordLayout->addWidget(confirmPasswordLineEdit);
	this->ui.passwordResetCodeLayout->addWidget(passwordResetCodeLineEdit);
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);


	userNameErrorLabel = nullptr;
	passwordErrorLabel = nullptr;
	emailErrorLabel = nullptr;
	confirmPasswordErrorLabel = nullptr;
	passwordResetCodeErrorLabel = nullptr;


	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
}

void SignUpWindow::signUpUser()
{

	//checks if there exists any errorlabels or any lineEdits with empty contents,in which case it won't do anything
	if (userNameErrorLabel == nullptr && passwordErrorLabel == nullptr && confirmPasswordErrorLabel == nullptr && emailErrorLabel == nullptr && passwordResetCodeErrorLabel == nullptr)
	{
	string userName = this->userNameLineEdit->text().toLocal8Bit().constData();
	string password = this->passwordLineEdit->text().toLocal8Bit().constData();
	string email = this->emailLineEdit->text().toLocal8Bit().constData();
	string confirmPassword = this->confirmPasswordLineEdit->text().toLocal8Bit().constData();
	string passwordResetCode = this->passwordResetCodeLineEdit->text().toLocal8Bit().constData();
		if (userName != "" && password != "" && email != "" && confirmPassword != "" && passwordResetCode != "")
		{
			service.createUserAccount(userName, password, confirmPassword, email, passwordResetCode);
			this->switchWindows();
		}
		else {
			userNameChecker();
			emailChecker();
			passwordChecker();
			confirmPasswordChecker();
			resetCodeChecker();
		}

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
	connect(this->passwordResetCodeLineEdit, &MyLineEdit::focussed, this, &SignUpWindow::lineEditClicked);
	
	connect(this->userNameLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::userNameChecker);
	connect(this->emailLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::emailChecker);
	connect(this->passwordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::passwordChecker);
	connect(this->passwordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::confirmPasswordChecker);
	connect(this->confirmPasswordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::confirmPasswordChecker);
	connect(this->confirmPasswordLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::passwordChecker);
	connect(this->passwordResetCodeLineEdit, &MyLineEdit::textChanged, this, &SignUpWindow::resetCodeChecker);

}

void SignUpWindow::switchWindows()
{
	this->userNameLineEdit->clear();
	this->passwordLineEdit->clear();
	this->emailLineEdit->clear();
	this->confirmPasswordLineEdit->clear();
	this->passwordResetCodeLineEdit->clear();
	if (userNameErrorLabel != nullptr) {
		delete userNameErrorLabel;
		userNameErrorLabel = nullptr;
		this->setFixedHeight(this->size().height() - windowChanges[0]);
		windowChanges[0] = 0;
	}
	if (passwordErrorLabel != nullptr) {
		delete passwordErrorLabel;
		passwordErrorLabel = nullptr;
		this->setFixedHeight(this->size().height() - windowChanges[2]);
		windowChanges[2] = 0;
	}
	if (emailErrorLabel != nullptr) {
		delete emailErrorLabel;
		emailErrorLabel = nullptr;
		this->setFixedHeight(this->size().height() - windowChanges[1]);
		windowChanges[1] = 0;
	}
	if (confirmPasswordErrorLabel != nullptr) {
		delete confirmPasswordErrorLabel;
		confirmPasswordErrorLabel = nullptr;
		this->setFixedHeight(this->size().height() - windowChanges[3]);
		windowChanges[3] = 0;
	}
	if (passwordResetCodeErrorLabel != nullptr) {
		delete passwordResetCodeErrorLabel;
		passwordResetCodeErrorLabel = nullptr;
		this->setFixedHeight(this->size().height() - windowChanges[4]);
		windowChanges[4] = 0;
	}
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

void SignUpWindow::resetCodeChecker()
{
	if (passwordResetCodeErrorLabel != nullptr) {
		delete passwordResetCodeErrorLabel;
		passwordResetCodeErrorLabel = nullptr;
	}
	string resetCode = this->passwordResetCodeLineEdit->text().toStdString();

	try {
		service.verifyResetCode(resetCode);
		this->setFixedHeight(this->size().height() - windowChanges[4]);
		windowChanges[4] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		passwordResetCodeErrorLabel = new QLabel;
		passwordResetCodeErrorLabel->setWordWrap(1);
		this->passwordResetCodeErrorLabel->setText(err.what());
		this->passwordResetCodeErrorLabel->setStyleSheet("color:#ff3333");
		this->ui.passwordResetCodeLayout->insertWidget(1, passwordResetCodeErrorLabel);
		if (windowChanges[4] == 0) {
			QSize size = this->passwordResetCodeErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[4] = size.height();
		}
	}
	catch (exception& err)
	{
		;
	}
}

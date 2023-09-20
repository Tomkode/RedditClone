#include "ForgotPassword.h"
using namespace std;
ForgotPassword::ForgotPassword(Service& serv, QWidget *parent)
	: QWidget(parent), service{serv}
{
	ui.setupUi(this);
	this->initWindow();
	this->connectSignalsAndSlots();
}

ForgotPassword::~ForgotPassword()
{}

void ForgotPassword::initWindow()
{
	QPixmap pixmap("images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);
	userNameLineEdit = new MyLineEdit();
	passwordLineEdit = new MyLineEdit();
	emailLineEdit = new MyLineEdit();
	resetCodeLineEdit = new MyLineEdit();
	passwordLineEdit->setEchoMode(QLineEdit::Password);
	userNameLineEdit->setPlaceholderText("Username");
	passwordLineEdit->setPlaceholderText("New Password");
	emailLineEdit->setPlaceholderText("Email");
	resetCodeLineEdit->setPlaceholderText("Reset Code");
	userNameLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	passwordLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	emailLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");
	resetCodeLineEdit->setStyleSheet("QLineEdit{border: 1px solid #808080;border-radius: 13px;}");

	QSize lineEditSize(100, 30);
	passwordLineEdit->setMinimumSize(lineEditSize);
	userNameLineEdit->setMinimumSize(lineEditSize);
	emailLineEdit->setMinimumSize(lineEditSize);
	resetCodeLineEdit->setMinimumSize(lineEditSize);
	this->ui.usernameLayout->addWidget(userNameLineEdit);
	this->ui.newPassLayout->addWidget(passwordLineEdit);
	this->ui.resetCodeLayout->addWidget(resetCodeLineEdit);
	this->ui.emailLayout->addWidget(emailLineEdit);

	userNameErrorLabel = nullptr;
	passwordErrorLabel = nullptr;
	emailErrorLabel = nullptr;
	resetCodeErrorLabel = nullptr;
	incorrectErrorLabel = nullptr;

	ui.resetPassButton->setCursor(QCursor(Qt::PointingHandCursor));

	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
	windowChanges.push_back(0);
}

void ForgotPassword::connectSignalsAndSlots()
{
	connect(this->ui.resetPassButton, &QPushButton::clicked, this, &ForgotPassword::resetPassword);
	connect(this->userNameLineEdit, &MyLineEdit::textChanged, this, [this] {
		userNameChecker();
		if (incorrectErrorLabel != nullptr)
		{
			delete incorrectErrorLabel;
			incorrectErrorLabel = nullptr;
			this->setFixedHeight(this->size().height() - windowChanges[4]);
			windowChanges[4] = 0;
		}
		});
	connect(this->passwordLineEdit, &MyLineEdit::textChanged, this, [this] {
		passwordChecker();
		if (incorrectErrorLabel != nullptr)
		{
			delete incorrectErrorLabel;
			incorrectErrorLabel = nullptr;
			this->setFixedHeight(this->size().height() - windowChanges[4]);
			windowChanges[4] = 0;
		}
		});
	connect(this->emailLineEdit, &MyLineEdit::textChanged, this, [this] {
		emailChecker();
		if (incorrectErrorLabel != nullptr)
		{
			delete incorrectErrorLabel;
			incorrectErrorLabel = nullptr;
			this->setFixedHeight(this->size().height() - windowChanges[4]);
			windowChanges[4] = 0;
		}
		});
	connect(this->resetCodeLineEdit, &MyLineEdit::textChanged, this, [this] {
		resetCodeChecker();
		if (incorrectErrorLabel != nullptr)
		{
			delete incorrectErrorLabel;
			incorrectErrorLabel = nullptr;
			this->setFixedHeight(this->size().height() - windowChanges[4]);
			windowChanges[4] = 0;
		}
		});
	connect(this, &ForgotPassword::closing, this, &ForgotPassword::closeWindow);
}

void ForgotPassword::resetPassword()
{
	if (userNameErrorLabel == nullptr && emailErrorLabel == nullptr && passwordErrorLabel == nullptr && resetCodeErrorLabel == nullptr)
	{
		string userName = this->userNameLineEdit->text().toLocal8Bit().constData();
		string password = this->passwordLineEdit->text().toLocal8Bit().constData();
		string email = this->emailLineEdit->text().toLocal8Bit().constData();
		string passwordResetCode = this->resetCodeLineEdit->text().toLocal8Bit().constData();
		if (userName != "" && password != "" && email != "" && passwordResetCode != "")
		{
			try {
				service.resetUserPassword(userName, email, passwordResetCode, password);
				closeWindow();
			}
			catch (IncorrectCredentialsException& err)
			{
				incorrectErrorLabel = new QLabel;
				incorrectErrorLabel->setWordWrap(1);
				incorrectErrorLabel->setText(err.what());
				incorrectErrorLabel->setStyleSheet("color:#ff3333");
				incorrectErrorLabel->setMaximumHeight(20);
				this->ui.layout->insertWidget(6, incorrectErrorLabel);
				if (windowChanges[4] == 0) {
					QSize size = this->incorrectErrorLabel->sizeHint();
					this->setFixedHeight(size.height() + this->size().height());
					windowChanges[4] = size.height();
				}
			}
		}
		else {
			userNameChecker();
			emailChecker();
			passwordChecker();
			resetCodeChecker();
		}
	}

}

void ForgotPassword::passwordChecker()
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
		this->setFixedHeight(this->size().height() - windowChanges[3]);
		windowChanges[3] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		passwordErrorLabel = new QLabel;
		passwordErrorLabel->setWordWrap(1);
		this->passwordErrorLabel->setText(err.what());
		this->passwordErrorLabel->setStyleSheet("color:#ff3333");
		this->passwordErrorLabel->setMaximumHeight(48);
		this->ui.newPassLayout->insertWidget(1, passwordErrorLabel);

		//resize the window only once after adding the errorLabel
		if (windowChanges[3] == 0) {
			QSize size = this->passwordErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[3] = size.height();
		}
	}
	catch (exception& err)
	{

		;
	}
}

void ForgotPassword::userNameChecker()
{
	if (userNameErrorLabel != nullptr) {

		delete userNameErrorLabel;
		userNameErrorLabel = nullptr;
	}
	//validations for username, password and email
	string userName = this->userNameLineEdit->text().toStdString();
	try {
		Validator v;
		v.isValidUsername(userName);
		this->setFixedHeight(this->size().height() - windowChanges[0]);
		windowChanges[0] = 0;
	}
	catch (IncorrectCredentialsException& err)
	{
		userNameErrorLabel = new QLabel;
		userNameErrorLabel->setWordWrap(1);
		this->userNameErrorLabel->setText(err.what());
		this->userNameErrorLabel->setStyleSheet("color:#ff3333");
		this->userNameErrorLabel->setMaximumHeight(35);
		this->ui.usernameLayout->insertWidget(1, userNameErrorLabel);
		if (windowChanges[0] == 0) {
			QSize size = this->userNameErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[0] = size.height();
		}
	}
	catch (exception& err)
	{
		;
	}
}

void ForgotPassword::resetCodeChecker()
{
	if (resetCodeErrorLabel != nullptr) {
		delete resetCodeErrorLabel;
		resetCodeErrorLabel = nullptr;
	}
	string resetCode = this->resetCodeLineEdit->text().toStdString();

	try {
		service.verifyResetCode(resetCode);
		this->setFixedHeight(this->size().height() - windowChanges[2]);
		windowChanges[2] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		resetCodeErrorLabel = new QLabel;
		resetCodeErrorLabel->setWordWrap(1);
		this->resetCodeErrorLabel->setText(err.what());
		this->resetCodeErrorLabel->setStyleSheet("color:#ff3333");
		this->resetCodeErrorLabel->setMaximumHeight(20);
		this->ui.resetCodeLayout->insertWidget(1, resetCodeErrorLabel);
		if (windowChanges[2] == 0) {
			QSize size = this->resetCodeErrorLabel->sizeHint();
			this->setFixedHeight(size.height() + this->size().height());
			windowChanges[2] = size.height();
		}
	}
	catch (exception& err)
	{
		;
	}
}

void ForgotPassword::emailChecker()
{
	if (emailErrorLabel != nullptr) {
		delete emailErrorLabel;
		emailErrorLabel = nullptr;
	}
	//validations for username, password and email
	string email = this->emailLineEdit->text().toStdString();
	try {
		Validator v;
		v.isValidEmail(email);


		this->setFixedHeight(this->size().height() - windowChanges[1]);
		windowChanges[1] = 0;
	}
	catch (IncorrectCredentialsException& err) {
		emailErrorLabel = new QLabel;
		emailErrorLabel->setWordWrap(1);
		this->emailErrorLabel->setText(err.what());
		this->emailErrorLabel->setStyleSheet("color:#ff3333");
		this->emailErrorLabel->setMaximumHeight(20);
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

void ForgotPassword::closeWindow()
{
	this->userNameLineEdit->clear();
	this->passwordLineEdit->clear();
	this->emailLineEdit->clear();
	this->resetCodeLineEdit->clear();
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
	if (resetCodeErrorLabel != nullptr) {
		delete resetCodeErrorLabel;
		resetCodeErrorLabel = nullptr;
		this->setFixedHeight(this->size().height() - windowChanges[3]);
		windowChanges[3] = 0;
	}
	this->hide();
}

void ForgotPassword::closeEvent(QCloseEvent* event)
{
	emit closing();
	event->accept();
}

#include "LogInWindow.h"
#include <QPixmap>
#include <openssl/sha.h>
#include <openssl/evp.h>
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
	QPixmap pixmap("D:\\GitHub\\RedditClone\\images\\Reddit Logo");
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
	int size = password.size();
	char* input_string = new char[size+1];
	strcpy(input_string, password.c_str());
	size_t input_len = strlen(input_string);
	unsigned char hash[SHA256_DIGEST_LENGTH];
	char hash_str[2 * SHA256_DIGEST_LENGTH + 1];  // +1 for null terminator

	
	SHA256((const unsigned char*)input_string, input_len, hash);
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		sprintf(&hash_str[i * 2], "%02x", hash[i]);
	}
	this->setWindowTitle("x");
}

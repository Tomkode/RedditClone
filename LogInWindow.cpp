#include "LogInWindow.h"
#include <QPixmap>
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

}

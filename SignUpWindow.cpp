#include "SignUpWindow.h"

SignUpWindow::SignUpWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

SignUpWindow::~SignUpWindow()
{}

void SignUpWindow::initSingUpWindow()
{
	QPixmap pixmap("D:\\GitHub\\RedditClone\\images\\Reddit Logo");
	ui.logoLabel->setPixmap(pixmap);
	ui.logoLabel->setMask(pixmap.mask());
	ui.logoLabel->show();
	ui.logoLabel->setScaledContents(true);
}

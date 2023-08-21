#include "Reddit69.h"
#include <QtWidgets/QApplication>
#include "LogInWindow.h"
#include "SignUpWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service service;
    LogInWindow* login = new LogInWindow(service);
    SignUpWindow* signup = new SignUpWindow(service);
    login->setChild(signup);
    signup->setParent(login);
    login->show();
    return a.exec();
}

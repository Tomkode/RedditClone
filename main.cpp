#include "Reddit69.h"
#include <QtWidgets/QApplication>
#include "LogInWindow.h"
#include "SignUpWindow.h"

int app(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service service;
    LogInWindow* login = new LogInWindow(service);
    SignUpWindow* signup = new SignUpWindow(service);
    ForgotPassword* forgor = new ForgotPassword;
    login->setChild(signup);
    login->setForgotPasswordWindow(forgor);
    signup->setParent(login);
    login->show();
    return a.exec();
}

int main(int argc, char* argv[])
{
    app(argc, argv);
    _CrtDumpMemoryLeaks();
}

#include "Reddit69.h"
#include <QtWidgets/QApplication>
#include "LogInWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogInWindow w;
    w.show();

    return a.exec();


}

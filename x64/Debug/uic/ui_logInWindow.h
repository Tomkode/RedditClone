/********************************************************************************
** Form generated from reading UI file 'LogInWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInWindowClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *logoLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *passwordLineEdit;
    QLineEdit *userNameLineEdit;
    QPushButton *logInButton;
    QPushButton *signUpButton;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogInWindowClass)
    {
        if (LogInWindowClass->objectName().isEmpty())
            LogInWindowClass->setObjectName("LogInWindowClass");
        LogInWindowClass->resize(388, 559);
        LogInWindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(LogInWindowClass);
        centralWidget->setObjectName("centralWidget");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 30, 204, 431));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        logoLabel = new QLabel(widget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMaximumSize(QSize(200, 100));

        verticalLayout_2->addWidget(logoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName("passwordLineEdit");

        verticalLayout->addWidget(passwordLineEdit);

        userNameLineEdit = new QLineEdit(widget);
        userNameLineEdit->setObjectName("userNameLineEdit");

        verticalLayout->addWidget(userNameLineEdit);

        logInButton = new QPushButton(widget);
        logInButton->setObjectName("logInButton");

        verticalLayout->addWidget(logInButton);

        signUpButton = new QPushButton(widget);
        signUpButton->setObjectName("signUpButton");

        verticalLayout->addWidget(signUpButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        LogInWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LogInWindowClass);
        statusBar->setObjectName("statusBar");
        LogInWindowClass->setStatusBar(statusBar);

        retranslateUi(LogInWindowClass);

        QMetaObject::connectSlotsByName(LogInWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *LogInWindowClass)
    {
        LogInWindowClass->setWindowTitle(QCoreApplication::translate("LogInWindowClass", "LogInWindow", nullptr));
        logoLabel->setText(QCoreApplication::translate("LogInWindowClass", "<html><head/><body><p><img src=\":/Reddit69/images/Reddit Logo\"/></p></body></html>", nullptr));
        passwordLineEdit->setText(QCoreApplication::translate("LogInWindowClass", "User Name", nullptr));
        userNameLineEdit->setText(QCoreApplication::translate("LogInWindowClass", "Password", nullptr));
        logInButton->setText(QCoreApplication::translate("LogInWindowClass", "Log In", nullptr));
        signUpButton->setText(QCoreApplication::translate("LogInWindowClass", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogInWindowClass: public Ui_LogInWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

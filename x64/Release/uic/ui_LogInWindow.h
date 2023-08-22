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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *logoLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *userNameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *logInButton;
    QPushButton *signUpButton;
    QLabel *errorLabel;
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
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 30, 204, 431));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        logoLabel = new QLabel(layoutWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMaximumSize(QSize(200, 100));

        verticalLayout_2->addWidget(logoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        userNameLineEdit = new QLineEdit(layoutWidget);
        userNameLineEdit->setObjectName("userNameLineEdit");

        verticalLayout->addWidget(userNameLineEdit);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");

        verticalLayout->addWidget(passwordLineEdit);

        logInButton = new QPushButton(layoutWidget);
        logInButton->setObjectName("logInButton");

        verticalLayout->addWidget(logInButton);

        signUpButton = new QPushButton(layoutWidget);
        signUpButton->setObjectName("signUpButton");

        verticalLayout->addWidget(signUpButton);

        errorLabel = new QLabel(layoutWidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setMinimumSize(QSize(0, 50));
        errorLabel->setWordWrap(true);

        verticalLayout->addWidget(errorLabel);

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
        userNameLineEdit->setText(QString());
        userNameLineEdit->setPlaceholderText(QCoreApplication::translate("LogInWindowClass", "User Name", nullptr));
        passwordLineEdit->setText(QString());
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("LogInWindowClass", "Password", nullptr));
        logInButton->setText(QCoreApplication::translate("LogInWindowClass", "Log In", nullptr));
        signUpButton->setText(QCoreApplication::translate("LogInWindowClass", "Sign Up", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogInWindowClass: public Ui_LogInWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

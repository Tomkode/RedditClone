/********************************************************************************
** Form generated from reading UI file 'LogInWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
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
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogInWindowClass)
    {
        if (LogInWindowClass->objectName().isEmpty())
            LogInWindowClass->setObjectName("LogInWindowClass");
        LogInWindowClass->resize(404, 356);
        LogInWindowClass->setMinimumSize(QSize(400, 300));
        LogInWindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(LogInWindowClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        logoLabel = new QLabel(centralWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMaximumSize(QSize(200, 100));

        verticalLayout_2->addWidget(logoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        userNameLineEdit = new QLineEdit(centralWidget);
        userNameLineEdit->setObjectName("userNameLineEdit");

        verticalLayout->addWidget(userNameLineEdit);

        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");

        verticalLayout->addWidget(passwordLineEdit);

        logInButton = new QPushButton(centralWidget);
        logInButton->setObjectName("logInButton");

        verticalLayout->addWidget(logInButton);

        signUpButton = new QPushButton(centralWidget);
        signUpButton->setObjectName("signUpButton");

        verticalLayout->addWidget(signUpButton);

        errorLabel = new QLabel(centralWidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setMinimumSize(QSize(0, 50));
        errorLabel->setWordWrap(true);

        verticalLayout->addWidget(errorLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);

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

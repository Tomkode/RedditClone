/********************************************************************************
** Form generated from reading UI file 'SignUpWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *logoLabel;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *userNameLayout;
    QVBoxLayout *emailLayout;
    QVBoxLayout *passwordLayout;
    QVBoxLayout *confirmPasswordLayout;
    QVBoxLayout *passwordResetCodeLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *signUpButton;
    QPushButton *logInButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignUpWindowClass)
    {
        if (SignUpWindowClass->objectName().isEmpty())
            SignUpWindowClass->setObjectName("SignUpWindowClass");
        SignUpWindowClass->resize(325, 450);
        SignUpWindowClass->setMinimumSize(QSize(325, 450));
        SignUpWindowClass->setMaximumSize(QSize(325, 450));
        SignUpWindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(SignUpWindowClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);

        logoLabel = new QLabel(centralWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(230, 98));
        logoLabel->setMaximumSize(QSize(200, 85));
        logoLabel->setLayoutDirection(Qt::LeftToRight);
        logoLabel->setScaledContents(false);
        logoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(logoLabel, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        userNameLayout = new QVBoxLayout();
        userNameLayout->setSpacing(6);
        userNameLayout->setObjectName("userNameLayout");

        verticalLayout->addLayout(userNameLayout);

        emailLayout = new QVBoxLayout();
        emailLayout->setSpacing(6);
        emailLayout->setObjectName("emailLayout");

        verticalLayout->addLayout(emailLayout);

        passwordLayout = new QVBoxLayout();
        passwordLayout->setSpacing(6);
        passwordLayout->setObjectName("passwordLayout");

        verticalLayout->addLayout(passwordLayout);

        confirmPasswordLayout = new QVBoxLayout();
        confirmPasswordLayout->setSpacing(6);
        confirmPasswordLayout->setObjectName("confirmPasswordLayout");

        verticalLayout->addLayout(confirmPasswordLayout);

        passwordResetCodeLayout = new QVBoxLayout();
        passwordResetCodeLayout->setSpacing(6);
        passwordResetCodeLayout->setObjectName("passwordResetCodeLayout");

        verticalLayout->addLayout(passwordResetCodeLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        signUpButton = new QPushButton(centralWidget);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setMinimumSize(QSize(0, 29));
        signUpButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#d93a00; /* Set the background color */\n"
"    color: white; /* Set the text color */\n"
"	border: none;\n"
"    border-radius: 13px;\n"
"	font-size: 12px;\n"
"	font-weight: bold;\n"
"}"));

        verticalLayout->addWidget(signUpButton);

        logInButton = new QPushButton(centralWidget);
        logInButton->setObjectName("logInButton");
        logInButton->setMinimumSize(QSize(0, 29));
        logInButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#d93a00; /* Set the background color */\n"
"    color: white; /* Set the text color */\n"
"	border: none;\n"
"    border-radius: 13px;\n"
"	font-size: 12px;\n"
"	font-weight: bold;\n"
"}"));

        verticalLayout->addWidget(logInButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        SignUpWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SignUpWindowClass);
        statusBar->setObjectName("statusBar");
        SignUpWindowClass->setStatusBar(statusBar);

        retranslateUi(SignUpWindowClass);

        QMetaObject::connectSlotsByName(SignUpWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpWindowClass)
    {
        SignUpWindowClass->setWindowTitle(QCoreApplication::translate("SignUpWindowClass", "SignUpWindow", nullptr));
        logoLabel->setText(QCoreApplication::translate("SignUpWindowClass", "<html><head/><body><p><img src=\":/Reddit69/images/Reddit Logo.png\"/></p></body></html>", nullptr));
        signUpButton->setText(QCoreApplication::translate("SignUpWindowClass", "Sign Up", nullptr));
        logInButton->setText(QCoreApplication::translate("SignUpWindowClass", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindowClass: public Ui_SignUpWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H

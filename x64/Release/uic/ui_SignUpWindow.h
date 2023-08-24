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
    QVBoxLayout *lineEditLayout;
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
        SignUpWindowClass->resize(325, 496);
        SignUpWindowClass->setMinimumSize(QSize(325, 496));
        SignUpWindowClass->setMaximumSize(QSize(325, 496));
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
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        logoLabel = new QLabel(centralWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(200, 40));
        logoLabel->setMaximumSize(QSize(200, 100));
        logoLabel->setLayoutDirection(Qt::LeftToRight);
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(logoLabel, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        lineEditLayout = new QVBoxLayout();
        lineEditLayout->setSpacing(6);
        lineEditLayout->setObjectName("lineEditLayout");

        verticalLayout->addLayout(lineEditLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

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
        logoLabel->setText(QString());
        signUpButton->setText(QCoreApplication::translate("SignUpWindowClass", "Sign Up", nullptr));
        logInButton->setText(QCoreApplication::translate("SignUpWindowClass", "Log In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindowClass: public Ui_SignUpWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H

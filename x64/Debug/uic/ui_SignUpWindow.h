/********************************************************************************
** Form generated from reading UI file 'SignUpWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindowClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *logoLabel;
    QVBoxLayout *verticalLayout;
    QLineEdit *userNameLineEdit;
    QLabel *userNameErrorLabel;
    QLineEdit *emailLineEdit;
    QLabel *emailErrorLabel;
    QLineEdit *passwordLineEdit;
    QLabel *passwordErrorLabel;
    QLineEdit *confirmPasswordLineEdit;
    QLabel *confirmPasswordErrorLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *signUpButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignUpWindowClass)
    {
        if (SignUpWindowClass->objectName().isEmpty())
            SignUpWindowClass->setObjectName("SignUpWindowClass");
        SignUpWindowClass->resize(306, 426);
        centralWidget = new QWidget(SignUpWindowClass);
        centralWidget->setObjectName("centralWidget");
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 241, 311));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        logoLabel = new QLabel(layoutWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(200, 40));

        verticalLayout_2->addWidget(logoLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        userNameLineEdit = new QLineEdit(layoutWidget);
        userNameLineEdit->setObjectName("userNameLineEdit");

        verticalLayout->addWidget(userNameLineEdit);

        userNameErrorLabel = new QLabel(layoutWidget);
        userNameErrorLabel->setObjectName("userNameErrorLabel");

        verticalLayout->addWidget(userNameErrorLabel);

        emailLineEdit = new QLineEdit(layoutWidget);
        emailLineEdit->setObjectName("emailLineEdit");

        verticalLayout->addWidget(emailLineEdit);

        emailErrorLabel = new QLabel(layoutWidget);
        emailErrorLabel->setObjectName("emailErrorLabel");

        verticalLayout->addWidget(emailErrorLabel);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout->addWidget(passwordLineEdit);

        passwordErrorLabel = new QLabel(layoutWidget);
        passwordErrorLabel->setObjectName("passwordErrorLabel");

        verticalLayout->addWidget(passwordErrorLabel);

        confirmPasswordLineEdit = new QLineEdit(layoutWidget);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");

        verticalLayout->addWidget(confirmPasswordLineEdit);

        confirmPasswordErrorLabel = new QLabel(layoutWidget);
        confirmPasswordErrorLabel->setObjectName("confirmPasswordErrorLabel");

        verticalLayout->addWidget(confirmPasswordErrorLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        signUpButton = new QPushButton(layoutWidget);
        signUpButton->setObjectName("signUpButton");

        verticalLayout->addWidget(signUpButton);


        verticalLayout_2->addLayout(verticalLayout);

        SignUpWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SignUpWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 306, 22));
        SignUpWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SignUpWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        SignUpWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SignUpWindowClass);
        statusBar->setObjectName("statusBar");
        SignUpWindowClass->setStatusBar(statusBar);

        retranslateUi(SignUpWindowClass);

        QMetaObject::connectSlotsByName(SignUpWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpWindowClass)
    {
        SignUpWindowClass->setWindowTitle(QCoreApplication::translate("SignUpWindowClass", "SignUpWindow", nullptr));
        logoLabel->setText(QCoreApplication::translate("SignUpWindowClass", "TextLabel", nullptr));
        userNameLineEdit->setText(QString());
        userNameLineEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindowClass", "User Name", nullptr));
        userNameErrorLabel->setText(QString());
        emailLineEdit->setText(QString());
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindowClass", "Email", nullptr));
        emailErrorLabel->setText(QString());
        passwordLineEdit->setText(QString());
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindowClass", "Password", nullptr));
        passwordErrorLabel->setText(QString());
        confirmPasswordLineEdit->setText(QString());
        confirmPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindowClass", "Confirm Password", nullptr));
        confirmPasswordErrorLabel->setText(QString());
        signUpButton->setText(QCoreApplication::translate("SignUpWindowClass", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindowClass: public Ui_SignUpWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H

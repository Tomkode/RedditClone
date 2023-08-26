/********************************************************************************
** Form generated from reading UI file 'ForgotPassword.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASSWORD_H
#define UI_FORGOTPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgotPasswordClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *layout;
    QLabel *logoLabel;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *usernameLayout;
    QVBoxLayout *emailLayout;
    QVBoxLayout *resetCodeLayout;
    QVBoxLayout *newPassLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *resetPassButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ForgotPasswordClass)
    {
        if (ForgotPasswordClass->objectName().isEmpty())
            ForgotPasswordClass->setObjectName("ForgotPasswordClass");
        ForgotPasswordClass->resize(326, 449);
        ForgotPasswordClass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(ForgotPasswordClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        layout = new QVBoxLayout();
        layout->setSpacing(6);
        layout->setObjectName("layout");
        logoLabel = new QLabel(ForgotPasswordClass);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(230, 98));
        logoLabel->setMaximumSize(QSize(230, 98));

        layout->addWidget(logoLabel);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layout->addItem(verticalSpacer_3);

        usernameLayout = new QVBoxLayout();
        usernameLayout->setSpacing(6);
        usernameLayout->setObjectName("usernameLayout");

        layout->addLayout(usernameLayout);

        emailLayout = new QVBoxLayout();
        emailLayout->setSpacing(6);
        emailLayout->setObjectName("emailLayout");

        layout->addLayout(emailLayout);

        resetCodeLayout = new QVBoxLayout();
        resetCodeLayout->setSpacing(6);
        resetCodeLayout->setObjectName("resetCodeLayout");

        layout->addLayout(resetCodeLayout);

        newPassLayout = new QVBoxLayout();
        newPassLayout->setSpacing(6);
        newPassLayout->setObjectName("newPassLayout");

        layout->addLayout(newPassLayout);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        layout->addItem(verticalSpacer_4);

        resetPassButton = new QPushButton(ForgotPasswordClass);
        resetPassButton->setObjectName("resetPassButton");
        resetPassButton->setMinimumSize(QSize(229, 29));
        resetPassButton->setMaximumSize(QSize(300, 29));
        resetPassButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:#d93a00; /* Set the background color */\n"
"    color: white; /* Set the text color */\n"
"	border: none;\n"
"    border-radius: 13px;\n"
"	font-size: 12px;\n"
"	font-weight: bold;\n"
"}"));

        layout->addWidget(resetPassButton);


        horizontalLayout->addLayout(layout);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(ForgotPasswordClass);

        QMetaObject::connectSlotsByName(ForgotPasswordClass);
    } // setupUi

    void retranslateUi(QWidget *ForgotPasswordClass)
    {
        ForgotPasswordClass->setWindowTitle(QCoreApplication::translate("ForgotPasswordClass", "ForgotPassword", nullptr));
        logoLabel->setText(QCoreApplication::translate("ForgotPasswordClass", "TextLabel", nullptr));
        resetPassButton->setText(QCoreApplication::translate("ForgotPasswordClass", "Reset Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgotPasswordClass: public Ui_ForgotPasswordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORD_H

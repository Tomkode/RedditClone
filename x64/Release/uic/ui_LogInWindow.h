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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ClickableLabel.h"

QT_BEGIN_NAMESPACE

class Ui_LogInWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *logoLabel;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *lineEditLayout;
    QSpacerItem *verticalSpacer_4;
    ClickableLabel *forgotPasswordLabel;
    QVBoxLayout *buttonsLayout;
    QPushButton *logInButton;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line_2;
    QLabel *label;
    QFrame *line;
    QPushButton *signUpButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LogInWindowClass)
    {
        if (LogInWindowClass->objectName().isEmpty())
            LogInWindowClass->setObjectName("LogInWindowClass");
        LogInWindowClass->resize(307, 420);
        LogInWindowClass->setMinimumSize(QSize(307, 420));
        LogInWindowClass->setMaximumSize(QSize(307, 420));
        LogInWindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(LogInWindowClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_3 = new QSpacerItem(15, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        logoLabel = new QLabel(centralWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(230, 98));
        logoLabel->setMaximumSize(QSize(200, 100));
        logoLabel->setScaledContents(false);

        verticalLayout_2->addWidget(logoLabel, 0, Qt::AlignHCenter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        lineEditLayout = new QVBoxLayout();
        lineEditLayout->setSpacing(6);
        lineEditLayout->setObjectName("lineEditLayout");

        verticalLayout->addLayout(lineEditLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        forgotPasswordLabel = new ClickableLabel(centralWidget);
        forgotPasswordLabel->setObjectName("forgotPasswordLabel");
        forgotPasswordLabel->setOpenExternalLinks(false);

        verticalLayout->addWidget(forgotPasswordLabel);

        buttonsLayout = new QVBoxLayout();
        buttonsLayout->setSpacing(6);
        buttonsLayout->setObjectName("buttonsLayout");
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

        buttonsLayout->addWidget(logInButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName("line_2");
        line_2->setMinimumSize(QSize(95, 1));
        line_2->setMaximumSize(QSize(120, 16777215));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 17));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"color:#808080;\n"
"	font-weight: bold;\n"
"}"));

        horizontalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        line = new QFrame(centralWidget);
        line->setObjectName("line");
        line->setMinimumSize(QSize(95, 0));
        line->setMaximumSize(QSize(100, 16777215));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);


        buttonsLayout->addLayout(horizontalLayout_2);

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

        buttonsLayout->addWidget(signUpButton);


        verticalLayout->addLayout(buttonsLayout);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);

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
        forgotPasswordLabel->setText(QCoreApplication::translate("LogInWindowClass", "Forgor password?", nullptr));
        logInButton->setText(QCoreApplication::translate("LogInWindowClass", "Log In", nullptr));
        label->setText(QCoreApplication::translate("LogInWindowClass", "OR", nullptr));
        signUpButton->setText(QCoreApplication::translate("LogInWindowClass", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogInWindowClass: public Ui_LogInWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

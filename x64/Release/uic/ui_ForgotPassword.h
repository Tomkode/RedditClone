/********************************************************************************
** Form generated from reading UI file 'ForgotPassword.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGOTPASSWORD_H
#define UI_FORGOTPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForgotPasswordClass
{
public:

    void setupUi(QWidget *ForgotPasswordClass)
    {
        if (ForgotPasswordClass->objectName().isEmpty())
            ForgotPasswordClass->setObjectName("ForgotPasswordClass");
        ForgotPasswordClass->resize(600, 400);

        retranslateUi(ForgotPasswordClass);

        QMetaObject::connectSlotsByName(ForgotPasswordClass);
    } // setupUi

    void retranslateUi(QWidget *ForgotPasswordClass)
    {
        ForgotPasswordClass->setWindowTitle(QCoreApplication::translate("ForgotPasswordClass", "ForgotPassword", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForgotPasswordClass: public Ui_ForgotPasswordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGOTPASSWORD_H

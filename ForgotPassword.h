#pragma once

#include <QWidget>
#include "ui_ForgotPassword.h"

class ForgotPassword : public QWidget
{
	Q_OBJECT

public:
	ForgotPassword(QWidget *parent = nullptr);
	~ForgotPassword();

private:
	Ui::ForgotPasswordClass ui;
};

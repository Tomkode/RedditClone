#include "MyLineEdit.h"
MyLineEdit::MyLineEdit(QWidget* parent)
	: QLineEdit(parent)
{}

MyLineEdit::~MyLineEdit()
{}

void MyLineEdit::focusInEvent(QFocusEvent* e)
{
	QLineEdit::focusInEvent(e);
	emit(focussed(true,this));
}

void MyLineEdit::focusOutEvent(QFocusEvent* e)
{
	QLineEdit::focusOutEvent(e);
	emit(focussed(false,this));
}
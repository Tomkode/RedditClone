#pragma once
#include <QLineEdit>
class MyLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	MyLineEdit(QWidget* parent = 0);
	~MyLineEdit();

signals:
	void focussed(bool hasFocus, MyLineEdit* lineEdit);

protected:
	void focusInEvent(QFocusEvent* e) override;
	void focusOutEvent(QFocusEvent* e) override;
};
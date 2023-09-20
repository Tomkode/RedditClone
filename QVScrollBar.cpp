#include "QVScrollBar.h"

QVScrollBar::QVScrollBar(QWidget* parent)
{
}

QVScrollBar::~QVScrollBar()
{
	QObject::connect(this, &QScrollBar::valueChanged, this, &QVScrollBar::checkIfScrolled);
}

void QVScrollBar::checkIfScrolled()
{
	if (this->value() == this->maximum())
		emit scrolledEntirely();
}

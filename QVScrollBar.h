#pragma once
#include <QScrollBar>
class QVScrollBar:public QScrollBar
{
	Q_OBJECT
public:
	QVScrollBar(QWidget* parent = 0);
	~QVScrollBar();
signals:
	void scrolledEntirely();
protected:
	void checkIfScrolled();
};


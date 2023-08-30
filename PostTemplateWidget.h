#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QFrame>
#include <QStackedLayout>
#include <QLabel>
class PostTemplateWidget : public QWidget
{
public:
	PostTemplateWidget( QWidget* parent = nullptr);
	~PostTemplateWidget();
private:
	QWidget* leftBar;
	QWidget* header;
	QWidget* footer;
	QWidget* contentWidget;
	QVBoxLayout* verticalLayout;
	QHBoxLayout* horizontalLayout;
	QHBoxLayout* headerLayout;
	QHBoxLayout* footerLayout;
	QHBoxLayout* contentLayout;
	QLabel* titleLabel;
	QLabel* contentLabel;
	QLabel* footerLabel;
	void initWidget();
};


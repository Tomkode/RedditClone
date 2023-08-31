#include "PostTemplateWidget.h"

PostTemplateWidget::PostTemplateWidget( QWidget* parent) : QWidget(parent)
{
	//setMinimumHeight(height);
	setStyleSheet("background-color: gray;");
	this->setFixedHeight(200);
	initWidget();

}

PostTemplateWidget::~PostTemplateWidget()
{
	delete leftBar;
	delete header;
	delete footer;
	delete contentWidget;
	delete verticalLayout;
	delete horizontalLayout;
	delete contentLayout;
	delete headerLayout;
	delete footerLayout;
	delete titleLabel;
	delete contentLabel;
	delete footerLabel;
}

void PostTemplateWidget::initWidget()
{
	leftBar = new QWidget;
	header = new QWidget;
	footer = new QWidget;
	contentWidget = new QWidget;
	verticalLayout = new QVBoxLayout;
	horizontalLayout = new QHBoxLayout;
	contentLayout = new QHBoxLayout;
	headerLayout = new QHBoxLayout;
	footerLayout = new QHBoxLayout;
	titleLabel = new QLabel(header);
	contentLabel = new QLabel(contentWidget);
	footerLabel = new QLabel(footer);

	leftBar->setFixedWidth(30);
	leftBar->setStyleSheet("background-color: lightgray; border: 0px");
	
	header->setFixedHeight(40);
	header->setStyleSheet("background-color: white; border: 0px;");
	header->setLayout(headerLayout);

	footer->setFixedHeight(40);
	footer->setStyleSheet("background-color: white; border: 0px;");
	footer->setLayout(footerLayout);

	contentWidget->setStyleSheet("background-color: white; border: 0px;");
	contentWidget->setMinimumHeight(80);
	contentWidget->setLayout(contentLayout);
	//add them labels
	
	titleLabel->setText("Title");
	titleLabel->setStyleSheet("font-size: 20px; font-weight: bold;");
	titleLabel->setAlignment(Qt::AlignCenter);
	titleLabel->setWordWrap(true);

	
	contentLabel->setText("Content");
	contentLabel->setStyleSheet("font-size: 15px; font-weight: normal;");
	contentLabel->setAlignment(Qt::AlignLeft);
	contentLabel->setWordWrap(true);

	
	footerLabel->setText("Footer");
	footerLabel->setStyleSheet("font-size: 15px; font-weight: normal;");
	footerLabel->setAlignment(Qt::AlignLeft);
	footerLabel->setWordWrap(true);
	
	verticalLayout->setSpacing(0);
	verticalLayout->addWidget(header);
	verticalLayout->addWidget(contentWidget);
	verticalLayout->addWidget(footer);
	
	
	horizontalLayout->setContentsMargins(0, 0, 0, 0);
	horizontalLayout->setSpacing(0);
	horizontalLayout->addWidget(leftBar);
	horizontalLayout->addLayout(verticalLayout);

	headerLayout->setContentsMargins(0, 0, 0, 0);
	headerLayout->setSpacing(0);	
	headerLayout->addWidget(titleLabel);

	contentLayout->setContentsMargins(0, 0, 0, 0);
	contentLayout->setSpacing(0);
	contentLayout->addWidget(contentLabel);

	footerLayout->setContentsMargins(0, 0, 0, 0);
	footerLayout->setSpacing(0);
	footerLayout->addWidget(footerLabel);



	setLayout(horizontalLayout);
	
}

void PostTemplateWidget::setTitle(std::string title)
{
	this->titleLabel->setText(QString::fromStdString(title));
}

void PostTemplateWidget::setText(std::string text)
{
	this->contentLabel->setText(QString::fromStdString(text));
}

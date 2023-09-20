#include "PostTemplateWidget.h"

PostTemplateWidget::PostTemplateWidget( QWidget* parent) : QWidget(parent)
{
	//setMinimumHeight(height);
	setStyleSheet("background-color: gray;");
	this->setMinimumHeight(100);
	initWidget();

}

PostTemplateWidget::~PostTemplateWidget()
{
}

void PostTemplateWidget::initWidget()
{
	//leftBar = new QWidget;
	//header = new QWidget;
	//footer = new QWidget;
	//contentWidget = new QWidget;
	//verticalLayout = new QVBoxLayout;
	//horizontalLayout = new QHBoxLayout;
	//contentLayout = new QHBoxLayout;
	//headerLayout = new QVBoxLayout;
	//footerLayout = new QHBoxLayout;
	//titleLabel = new QLabel(header);
	//posterLabel = new QLabel(header);
	//contentLabel = new QLabel(contentWidget);
	//footerLabel = new QLabel(footer);

	//leftBar->setFixedWidth(30);
	//leftBar->setStyleSheet("background-color: lightgray; border: 0px");
	//
	//header->setFixedHeight(50);
	//
	//header->setStyleSheet("background-color: white; border: 0px;");
	//header->setLayout(headerLayout);

	//footer->setFixedHeight(40);
	//footer->setStyleSheet("background-color: white; border: 0px;");
	//footer->setLayout(footerLayout);

	//contentWidget->setStyleSheet("background-color: white; border: 0px;");
	//contentWidget->setMinimumHeight(80);
	//contentWidget->setLayout(contentLayout);
	////add them labels
	//
	//titleLabel->setText("Title");
	//titleLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
	//titleLabel->setAlignment(Qt::AlignLeft);
	//titleLabel->setWordWrap(true);

	//posterLabel->setText("Title");
	//posterLabel->setStyleSheet("font-size: 12px; color: #a5acac");
	//posterLabel->setAlignment(Qt::AlignLeft);
	//posterLabel->setWordWrap(true);

	//contentLabel->setText("Content");
	//contentLabel->setStyleSheet("font-size: 15px; font-weight: normal;");
	//contentLabel->setAlignment(Qt::AlignLeft);
	//contentLabel->setWordWrap(true);

	//
	//footerLabel->setText("Footer");
	//footerLabel->setStyleSheet("font-size: 15px; font-weight: normal;");
	//footerLabel->setAlignment(Qt::AlignLeft);
	//footerLabel->setWordWrap(true);
	//
	//verticalLayout->setSpacing(0);
	//verticalLayout->addWidget(header);
	//verticalLayout->addWidget(contentWidget);
	//verticalLayout->addWidget(footer);
	//
	//
	//horizontalLayout->setContentsMargins(0, 0, 0, 0);
	//horizontalLayout->setSpacing(0);
	//horizontalLayout->addWidget(leftBar);
	//horizontalLayout->addLayout(verticalLayout);

	//headerLayout->setContentsMargins(7, 5, 0, 0);
	//headerLayout->setSpacing(5);	
	//headerLayout->addWidget(posterLabel);
	//auto lineA = new QFrame;
	//lineA->setFrameShape(QFrame::HLine);
	//lineA->setFrameShadow(QFrame::Sunken);
	//lineA->setStyleSheet(QString("background-color: #c0c0c0;"));
	//headerLayout->addWidget(lineA);
	//headerLayout->addWidget(titleLabel);
	//

	//contentLayout->setContentsMargins(7, 7, 0, 0);
	//contentLayout->setSpacing(0);
	//contentLayout->addWidget(contentLabel);

	//footerLayout->setContentsMargins(0, 0, 0, 0);
	//footerLayout->setSpacing(0);
	//footerLayout->addWidget(footerLabel);


	//

	//setLayout(horizontalLayout);
   
    this->setObjectName("postWidget");
    this->setGeometry(QRect(130, 10, 651, 221));
    this->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    verticalLayout_3 = new QVBoxLayout(this);
    verticalLayout_3->setSpacing(0);
    verticalLayout_3->setContentsMargins(11, 11, 11, 11);
    verticalLayout_3->setObjectName("verticalLayout_3");
    verticalLayout_3->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName("horizontalLayout");
    sideBarWidget = new QWidget(this);
    sideBarWidget->setObjectName("sideBarWidget");
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(sideBarWidget->sizePolicy().hasHeightForWidth());
    sideBarWidget->setSizePolicy(sizePolicy);
    sideBarWidget->setMinimumSize(QSize(45, 0));
    sideBarWidget->setStyleSheet(QString::fromUtf8("background-color: #F5F5F5;"));
    verticalLayout_4 = new QVBoxLayout(sideBarWidget);
    verticalLayout_4->setSpacing(6);
    verticalLayout_4->setContentsMargins(11, 11, 11, 11);
    verticalLayout_4->setObjectName("verticalLayout_4");
    verticalLayout_4->setContentsMargins(5, -1, 2, -1);
    verticalSpacer_2 = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout_4->addItem(verticalSpacer_2);

    upvoteBox = new QSpinBox(sideBarWidget);
    upvoteBox->setObjectName("upvoteBox");
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(upvoteBox->sizePolicy().hasHeightForWidth());
    upvoteBox->setSizePolicy(sizePolicy1);
    upvoteBox->setMinimumSize(QSize(40, 45));
    upvoteBox->setLayoutDirection(Qt::LeftToRight);
    upvoteBox->setStyleSheet(QString::fromUtf8(""));
    upvoteBox->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);

    verticalLayout_4->addWidget(upvoteBox);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_4->addItem(verticalSpacer);


    horizontalLayout->addWidget(sideBarWidget);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName("verticalLayout");
    headerWidget = new QWidget(this);
    headerWidget->setObjectName("headerWidget");
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(headerWidget->sizePolicy().hasHeightForWidth());
    headerWidget->setSizePolicy(sizePolicy2);
    headerWidget->setMinimumSize(QSize(0, 75));
    headerWidget->setMaximumSize(QSize(16777215, 70));
    verticalLayout_7 = new QVBoxLayout(headerWidget);
    verticalLayout_7->setSpacing(5);
    verticalLayout_7->setContentsMargins(11, 11, 11, 11);
    verticalLayout_7->setObjectName("verticalLayout_7");
    verticalLayout_7->setContentsMargins(-1, 5, -1, -1);
    authorLabel = new QLabel(headerWidget);
    authorLabel->setObjectName("authorLabel");
    authorLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
        "{\n"
        "	\n"
        "	color: #808080;\n"
        "	font-size:11px;\n"
        "	font-weight:500;\n"
        "\n"
        "}"));

    verticalLayout_7->addWidget(authorLabel);

    line = new QFrame(headerWidget);
    line->setObjectName("line");
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout_7->addWidget(line);

    titleLabel = new QLabel(headerWidget);
    titleLabel->setObjectName("titleLabel");
    titleLabel->setStyleSheet(QString::fromUtf8("\n"
        "QLabel{\n"
        "font: 9pt \"Sans Serif Collection\";\n"
        "font-size: 17px;\n"
        "font-weight:550;\n"
        "}\n"
        ""));
    titleLabel->setWordWrap(false);

    verticalLayout_7->addWidget(titleLabel);


    verticalLayout->addWidget(headerWidget);

    contentWidget = new QWidget(this);
    contentWidget->setObjectName("contentWidget");
    QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(contentWidget->sizePolicy().hasHeightForWidth());
    contentWidget->setSizePolicy(sizePolicy3);
    contentWidget->setMinimumSize(QSize(0, 0));
    horizontalLayout_2 = new QHBoxLayout(contentWidget);
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_2->setObjectName("horizontalLayout_2");
    horizontalLayout_2->setContentsMargins(9, 3, -1, -1);
    contentLabel = new QLabel(contentWidget);
    contentLabel->setObjectName("contentLabel");
    contentLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
        "{\n"
        "font-size: 13px;\n"
        "font-weight:400;\n"
        "}"));
    contentLabel->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);
    contentLabel->setWordWrap(true);

    horizontalLayout_2->addWidget(contentLabel);


    verticalLayout->addWidget(contentWidget);

    footerWidget = new QWidget(this);
    footerWidget->setObjectName("footerWidget");
    QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(40);
    sizePolicy4.setHeightForWidth(footerWidget->sizePolicy().hasHeightForWidth());
    footerWidget->setSizePolicy(sizePolicy4);
    footerWidget->setMinimumSize(QSize(0, 40));
    horizontalLayout_3 = new QHBoxLayout(footerWidget);
    horizontalLayout_3->setSpacing(0);
    horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_3->setObjectName("horizontalLayout_3");
    horizontalLayout_3->setContentsMargins(4, 4, -1, 2);
    commentIconLayout = new QVBoxLayout();
    commentIconLayout->setSpacing(6);
    commentIconLayout->setObjectName("commentIconLayout");
    commentIconLayout->setContentsMargins(-1, 5, -1, -1);
    commentIconLabel = new QLabel(footerWidget);
    commentIconLabel->setObjectName("commentIconLabel");
    sizePolicy1.setHeightForWidth(commentIconLabel->sizePolicy().hasHeightForWidth());
    commentIconLabel->setSizePolicy(sizePolicy1);
    commentIconLabel->setMinimumSize(QSize(31, 21));
    commentIconLabel->setMaximumSize(QSize(31, 21));
    commentIconLabel->setPixmap(QPixmap(QString::fromUtf8("C:/Users/mario/OneDrive/Desktop/icon.png")));
    commentIconLabel->setScaledContents(true);

    commentIconLayout->addWidget(commentIconLabel);


    horizontalLayout_3->addLayout(commentIconLayout);

    commentsInfoLabel = new QLabel(footerWidget);
    commentsInfoLabel->setObjectName("commentsInfoLabel");
    commentsInfoLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
        "{\n"
        "	\n"
        "	color: #808080;\n"
        "	font-size:11px;\n"
        "	font-weight:700;\n"
        "\n"
        "}"));

    horizontalLayout_3->addWidget(commentsInfoLabel);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer);


    verticalLayout->addWidget(footerWidget);


    horizontalLayout->addLayout(verticalLayout);


    verticalLayout_3->addLayout(horizontalLayout);

    

	
}

void PostTemplateWidget::setTitle(std::string title)
{
	this->titleLabel->setText(QString::fromStdString(title));
}

void PostTemplateWidget::setText(std::string text)
{
	this->contentLabel->setText(QString::fromStdString(text));
}

void PostTemplateWidget::setPostInfo(std::string author, std::string time)
{
	std::string text = "Posted by " + author+" "+time+" hours ago";
	this->authorLabel->setText(QString::fromStdString(text));
}

void PostTemplateWidget::setComments(int commentsNum)
{
    std::string text = std::to_string(commentsNum) + " Comments";
    this->commentsInfoLabel->setText(QString::fromStdString(text));
}

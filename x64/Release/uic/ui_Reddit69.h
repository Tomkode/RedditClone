/********************************************************************************
** Form generated from reading UI file 'Reddit69.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDDIT69_H
#define UI_REDDIT69_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reddit69Class
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *searchBarLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QScrollArea *postArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_5;
    QWidget *postAreaWidget;
    QSpacerItem *horizontalSpacer_3;
    QWidget *rightWidget;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *rightWidgetLayout;
    QWidget *postWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *postWidgetLayout;
    QLineEdit *titleLineEdit;
    QLineEdit *textLineEdit;
    QPushButton *postButton;

    void setupUi(QWidget *Reddit69Class)
    {
        if (Reddit69Class->objectName().isEmpty())
            Reddit69Class->setObjectName("Reddit69Class");
        Reddit69Class->resize(1063, 648);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(Reddit69Class->sizePolicy().hasHeightForWidth());
        Reddit69Class->setSizePolicy(sizePolicy);
        Reddit69Class->setStyleSheet(QString::fromUtf8("\n"
"background-color: #dae0e6\n"
""));
        horizontalLayout_4 = new QHBoxLayout(Reddit69Class);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(Reddit69Class);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(0, 50));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/Reddit Logo For Bar.png")));
        label_2->setScaledContents(false);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(37, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        searchBarLineEdit = new QLineEdit(widget);
        searchBarLineEdit->setObjectName("searchBarLineEdit");
        searchBarLineEdit->setMinimumSize(QSize(0, 32));
        searchBarLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {background-color:#f6f7f8;color: black; border: none;border-radius: 13px;font-size: 12px;font-weight: bold;}"));

        horizontalLayout_2->addWidget(searchBarLineEdit);

        horizontalSpacer_2 = new QSpacerItem(37, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        postArea = new QScrollArea(Reddit69Class);
        postArea->setObjectName("postArea");
        postArea->setStyleSheet(QString::fromUtf8(""));
        postArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 409, 558));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        postAreaWidget = new QWidget(scrollAreaWidgetContents);
        postAreaWidget->setObjectName("postAreaWidget");

        horizontalLayout_5->addWidget(postAreaWidget);

        postArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(postArea);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        rightWidget = new QWidget(Reddit69Class);
        rightWidget->setObjectName("rightWidget");
        rightWidget->setMinimumSize(QSize(350, 0));
        rightWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);"));
        horizontalLayout_7 = new QHBoxLayout(rightWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        rightWidgetLayout = new QHBoxLayout();
        rightWidgetLayout->setSpacing(6);
        rightWidgetLayout->setObjectName("rightWidgetLayout");
        postWidget = new QWidget(rightWidget);
        postWidget->setObjectName("postWidget");
        postWidget->setMinimumSize(QSize(0, 200));
        postWidget->setMaximumSize(QSize(16777215, 150));
        postWidget->setStyleSheet(QString::fromUtf8("background-color: gray;"));
        verticalLayout_3 = new QVBoxLayout(postWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        postWidgetLayout = new QVBoxLayout();
        postWidgetLayout->setSpacing(6);
        postWidgetLayout->setObjectName("postWidgetLayout");
        titleLineEdit = new QLineEdit(postWidget);
        titleLineEdit->setObjectName("titleLineEdit");
        titleLineEdit->setMaximumSize(QSize(16777215, 25));
        titleLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        postWidgetLayout->addWidget(titleLineEdit);

        textLineEdit = new QLineEdit(postWidget);
        textLineEdit->setObjectName("textLineEdit");
        textLineEdit->setMinimumSize(QSize(0, 75));
        textLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textLineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        postWidgetLayout->addWidget(textLineEdit);

        postButton = new QPushButton(postWidget);
        postButton->setObjectName("postButton");
        postButton->setMaximumSize(QSize(100, 25));

        postWidgetLayout->addWidget(postButton);


        verticalLayout_3->addLayout(postWidgetLayout);


        rightWidgetLayout->addWidget(postWidget);


        horizontalLayout_7->addLayout(rightWidgetLayout);


        horizontalLayout->addWidget(rightWidget);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(Reddit69Class);

        QMetaObject::connectSlotsByName(Reddit69Class);
    } // setupUi

    void retranslateUi(QWidget *Reddit69Class)
    {
        Reddit69Class->setWindowTitle(QCoreApplication::translate("Reddit69Class", "Reddit69", nullptr));
        label->setText(QString());
        searchBarLineEdit->setText(QString());
        searchBarLineEdit->setPlaceholderText(QCoreApplication::translate("Reddit69Class", "Search...", nullptr));
        titleLineEdit->setPlaceholderText(QCoreApplication::translate("Reddit69Class", "Title", nullptr));
        textLineEdit->setPlaceholderText(QCoreApplication::translate("Reddit69Class", "Text", nullptr));
        postButton->setText(QCoreApplication::translate("Reddit69Class", "Post", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reddit69Class: public Ui_Reddit69Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDDIT69_H

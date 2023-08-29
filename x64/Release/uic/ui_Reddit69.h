/********************************************************************************
** Form generated from reading UI file 'Reddit69.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
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
    QSpacerItem *horizontalSpacer_3;
    QScrollBar *verticalScrollBar;
    QListWidget *listWidget;

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
        postArea->setStyleSheet(QString::fromUtf8("border: 1px solid;"));
        postArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 540, 558));
        postArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(postArea);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalScrollBar = new QScrollBar(Reddit69Class);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        listWidget = new QListWidget(Reddit69Class);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        listWidget->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(listWidget);


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
    } // retranslateUi

};

namespace Ui {
    class Reddit69Class: public Ui_Reddit69Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDDIT69_H

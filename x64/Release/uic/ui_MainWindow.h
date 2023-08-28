/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *homeAction;
    QAction *actionProfile;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QScrollArea *postArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QToolBar *topBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(1038, 652);
        MainWindowClass->setStyleSheet(QString::fromUtf8("background-color: rgb(218, 224, 230);"));
        homeAction = new QAction(MainWindowClass);
        homeAction->setObjectName("homeAction");
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Reddit Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeAction->setIcon(icon);
        homeAction->setMenuRole(QAction::NoRole);
        actionProfile = new QAction(MainWindowClass);
        actionProfile->setObjectName("actionProfile");
        actionProfile->setMenuRole(QAction::NoRole);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(9, 9, 641, 561));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        postArea = new QScrollArea(layoutWidget);
        postArea->setObjectName("postArea");
        postArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 612, 555));
        postArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(postArea);

        verticalScrollBar = new QScrollBar(layoutWidget);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalScrollBar);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindowClass->setCentralWidget(centralWidget);
        topBar = new QToolBar(MainWindowClass);
        topBar->setObjectName("topBar");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy);
        topBar->setMinimumSize(QSize(0, 0));
        topBar->setMaximumSize(QSize(16777215, 16777215));
        topBar->setBaseSize(QSize(300, 0));
        topBar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        topBar->setMovable(false);
        topBar->setIconSize(QSize(100, 45));
        topBar->setFloatable(true);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, topBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName("statusBar");
        MainWindowClass->setStatusBar(statusBar);

        topBar->addAction(homeAction);
        topBar->addAction(actionProfile);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        homeAction->setText(QCoreApplication::translate("MainWindowClass", "home", nullptr));
        actionProfile->setText(QCoreApplication::translate("MainWindowClass", "Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

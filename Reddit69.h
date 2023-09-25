#pragma once

#include <QtWidgets/QWidget>
#include "ui_Reddit69.h"
#include <vector>
#include "PostTemplateWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Service.h"
class Reddit69 : public QWidget
{
    Q_OBJECT

public:
    Reddit69(Service& serv, User user , QWidget *parent = nullptr);
    void initWindow();
    ~Reddit69();
signals:
    void maximumScrollReached();
private:
    Ui::Reddit69Class ui;
    std::vector<QWidget*> posts;
    Service& service;
    User user;
    QVBoxLayout* mainLayout;
    void uploadPost();
    QWidget* createWidgetPost(Post post);
    void connectSignalsAndSlots();
    void displayPosts();
    void displayPost(Post post);
    void checkScrollValue();
};

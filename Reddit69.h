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

private:
    Ui::Reddit69Class ui;
    std::vector<QWidget*> posts;
    Service& service;
    User user;
    QVBoxLayout* mainLayout;
    void uploadPost();
    QWidget* createWidgetWithPost(std::string title, std::string text, std::string author);
    void connectSignalsAndSlots();
};

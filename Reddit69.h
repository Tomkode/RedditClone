#pragma once

#include <QtWidgets/QWidget>
#include "ui_Reddit69.h"

class Reddit69 : public QWidget
{
    Q_OBJECT

public:
    Reddit69(QWidget *parent = nullptr);
    void initWindow();
    ~Reddit69();

private:
    Ui::Reddit69Class ui;
};

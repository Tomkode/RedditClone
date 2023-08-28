#include "Reddit69.h"
#include <QLabel>

Reddit69::Reddit69(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    initWindow();
}

void Reddit69::initWindow()
{
    QAction* searchBarAction = new QAction();
    QIcon icon;
    icon.addPixmap(QPixmap("images/searchBarIcon.png"));
    searchBarAction->setIcon(icon);
    this->ui.searchBarLineEdit->addAction(searchBarAction, QLineEdit::LeadingPosition);
}

Reddit69::~Reddit69()
{}

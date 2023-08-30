#include "Reddit69.h"
#include <QLabel>

Reddit69::Reddit69(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    initWindow();
    addPostWidget();
}

void Reddit69::initWindow()
{
    QAction* searchBarAction = new QAction();
    QIcon icon;
    mainLayout = new QHBoxLayout(ui.postAreaWidget);
    icon.addPixmap(QPixmap("images/searchBarIcon.png"));
    searchBarAction->setIcon(icon);
    this->ui.searchBarLineEdit->addAction(searchBarAction, QLineEdit::LeadingPosition);
    this->ui.horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
    //ui.postArea->setWidget(ui.postAreaWidget);
    //ui.postAreaWidget->setLayout(mainLayout);
}

Reddit69::~Reddit69()
{}

void Reddit69::addPostWidget()
{
    auto postWidget = new PostTemplateWidget();
    mainLayout->addWidget(postWidget, 0, Qt::AlignTop);
}

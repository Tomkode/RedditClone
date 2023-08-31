#include "Reddit69.h"
#include <QLabel>

Reddit69::Reddit69(Service& serv, User user, QWidget *parent)
    : QWidget(parent), service{ serv }, user{ user }
{
    ui.setupUi(this);
    initWindow();
}

void Reddit69::initWindow()
{
    QAction* searchBarAction = new QAction();
    QIcon icon;
    mainLayout = new QVBoxLayout(ui.postAreaWidget);
    mainLayout->setSpacing(15);
    mainLayout->setAlignment(Qt::AlignTop);
    icon.addPixmap(QPixmap("images/searchBarIcon.png"));
    searchBarAction->setIcon(icon);
    this->ui.searchBarLineEdit->addAction(searchBarAction, QLineEdit::LeadingPosition);
    this->ui.horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
    this->ui.rightWidgetLayout->setContentsMargins(0, 0, 0, 0);
    this->ui.rightWidgetLayout->setAlignment(Qt::AlignTop);
    this->ui.rightWidgetLayout->setSpacing(0);
    this->ui.postWidgetLayout->setAlignment(Qt::AlignCenter);
    //ui.postArea->setWidget(ui.postAreaWidget);
    //ui.postAreaWidget->setLayout(mainLayout);

    connectSignalsAndSlots();
}

Reddit69::~Reddit69()
{}

void Reddit69::uploadPost()
{
   std::string title = this->ui.titleLineEdit->text().toStdString();
   std::string text = this->ui.textLineEdit->text().toStdString();
   std::string userName = this->user.getUsername();
   std::string author = " - Posted by " + userName;
   if (title == "" || text == "")
   {
       //make an error label somewhere
       return;
   }
   auto postWidget = createWidgetWithPost(title, text, author);
   posts.push_back(postWidget);
   this->mainLayout->addWidget(postWidget);
   this->ui.titleLineEdit->clear();
   this->ui.textLineEdit->clear();
}

QWidget* Reddit69::createWidgetWithPost(std::string title, std::string text, std::string author)
{
    auto postWidget = new PostTemplateWidget;
    postWidget->setTitle(title + author);
    postWidget->setText(text);

    return postWidget;
}

void Reddit69::connectSignalsAndSlots()
{
	QObject::connect(this->ui.postButton, &QPushButton::clicked, this, &Reddit69::uploadPost);
}



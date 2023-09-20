#include "Reddit69.h"
#include <QLabel>
#include "QVScrollBar.h"

using namespace std;
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
    displayPosts();
    connectSignalsAndSlots();
}

Reddit69::~Reddit69()
{}

void Reddit69::uploadPost()
{
   std::string title = this->ui.titleLineEdit->text().toStdString();
   std::string text = this->ui.textLineEdit->text().toStdString();
   int userId = this->user.getUserId();
   Post post(userId, title, text, user.getUsername());
   if (title == "" || text == "")
   {
       //make an error label somewhere
       return;
   }
   auto postWidget = createWidgetWithPost(post);
   posts.push_back(postWidget);
   displayPost(post);
   this->ui.titleLineEdit->clear();
   this->ui.textLineEdit->clear();
   service.addPostByUser(title, text, user);
}

QWidget* Reddit69::createWidgetWithPost(Post post)
{
    auto postWidget = new PostTemplateWidget;
    postWidget->setTitle(post.getTitle());
    postWidget->setText(post.getText());
    postWidget->setPostInfo(post.getAuthorUsername(), "3");
    postWidget->setComments(10);

    return postWidget;
}

void Reddit69::connectSignalsAndSlots()
{
	QObject::connect(this->ui.postButton, &QPushButton::clicked, this, &Reddit69::uploadPost);
	QObject::connect(this->ui.postArea->verticalScrollBar(), &QScrollBar::valueChanged, this, &Reddit69::checkScrollValue);
    QObject::connect(this, &Reddit69::maximumScrollReached, this, &Reddit69::displayPosts);
}

void Reddit69::displayPosts()
{
    vector<Post> requestedPosts = service.requestPosts(10);
    for (Post post : requestedPosts)
    {
        displayPost(post);
    }

    

}

void Reddit69::displayPost(Post post)
{
    auto postWidget = createWidgetWithPost(post);
    this->mainLayout->addWidget(postWidget);
}

void Reddit69::checkScrollValue()
{
    if (this->ui.postArea->verticalScrollBar()->value() == this->ui.postArea->verticalScrollBar()->maximum())
        emit maximumScrollReached();

}



#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QFrame>
#include <QStackedLayout>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
class PostTemplateWidget : public QWidget
{
public:
	PostTemplateWidget( QWidget* parent = nullptr);
	~PostTemplateWidget();
	void setTitle(std::string title);
	void setText(std::string text);
	void setPostInfo(std::string author, std::string time);
    void setComments(int commentsNum);
    void setLikes(int likesNum);
private:
    QWidget* centralWidget;
    QWidget* postWidget;
    QVBoxLayout* verticalLayout_3;
    QHBoxLayout* horizontalLayout;
    QWidget* sideBarWidget;
    QVBoxLayout* verticalLayout_4;
    QSpacerItem* verticalSpacer_2;
    QVBoxLayout* postButtonsLayout;
    QHBoxLayout* upvoteButtonLayout;
    QPushButton* upvoteButton;
    QLabel* likesNumLabel;
    QHBoxLayout* downvoteButtonLayout;
    QPushButton* downvoteButton;
    QSpacerItem* verticalSpacer;
    QVBoxLayout* verticalLayout;
    QWidget* headerWidget;
    QVBoxLayout* verticalLayout_7;
    QLabel* authorLabel;
    QFrame* line;
    QLabel* titleLabel;
    QWidget* contentWidget;
    QHBoxLayout* horizontalLayout_2;
    QLabel* contentLabel;
    QWidget* footerWidget;
    QHBoxLayout* horizontalLayout_3;
    QVBoxLayout* commentIconLayout;
    QLabel* commentIconLabel;
    QLabel* commentInfoLabel;
    QSpacerItem* horizontalSpacer;
  
	void initWidget();

};


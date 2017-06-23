/********************************************************************************
** Form generated from reading UI file 'quiz.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZ_H
#define UI_QUIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuizClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QListWidget *questionsListWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *answerLineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QuizClass)
    {
        if (QuizClass->objectName().isEmpty())
            QuizClass->setObjectName(QStringLiteral("QuizClass"));
        QuizClass->resize(370, 497);
        centralWidget = new QWidget(QuizClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 19, 331, 411));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        questionsListWidget = new QListWidget(verticalLayoutWidget);
        questionsListWidget->setObjectName(QStringLiteral("questionsListWidget"));

        verticalLayout_6->addWidget(questionsListWidget);


        verticalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_7->addLayout(horizontalLayout);

        submitButton = new QPushButton(verticalLayoutWidget);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        verticalLayout_7->addWidget(submitButton);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        answerLineEdit = new QLineEdit(verticalLayoutWidget);
        answerLineEdit->setObjectName(QStringLiteral("answerLineEdit"));

        horizontalLayout_6->addWidget(answerLineEdit);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_7);

        QuizClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QuizClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 370, 21));
        QuizClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuizClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QuizClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QuizClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QuizClass->setStatusBar(statusBar);

        retranslateUi(QuizClass);

        QMetaObject::connectSlotsByName(QuizClass);
    } // setupUi

    void retranslateUi(QMainWindow *QuizClass)
    {
        QuizClass->setWindowTitle(QApplication::translate("QuizClass", "Quiz", 0));
        label_3->setText(QApplication::translate("QuizClass", "Score:", 0));
        submitButton->setText(QApplication::translate("QuizClass", "Submit answer", 0));
        label->setText(QApplication::translate("QuizClass", "Answer:", 0));
    } // retranslateUi

};

namespace Ui {
    class QuizClass: public Ui_QuizClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZ_H

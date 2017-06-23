/********************************************************************************
** Form generated from reading UI file 'coderevision.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEREVISION_H
#define UI_CODEREVISION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodeRevisionClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *toReviseLabel;
    QLabel *label_3;
    QLabel *revisedLabel;
    QListWidget *listWidget;
    QPushButton *reviseButton;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLineEdit *fileNameLineEdit;
    QPushButton *addButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CodeRevisionClass)
    {
        if (CodeRevisionClass->objectName().isEmpty())
            CodeRevisionClass->setObjectName(QStringLiteral("CodeRevisionClass"));
        CodeRevisionClass->resize(600, 400);
        centralWidget = new QWidget(CodeRevisionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 581, 331));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        toReviseLabel = new QLabel(horizontalLayoutWidget);
        toReviseLabel->setObjectName(QStringLiteral("toReviseLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, toReviseLabel);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        revisedLabel = new QLabel(horizontalLayoutWidget);
        revisedLabel->setObjectName(QStringLiteral("revisedLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, revisedLabel);


        verticalLayout_2->addLayout(formLayout);

        listWidget = new QListWidget(horizontalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        reviseButton = new QPushButton(horizontalLayoutWidget);
        reviseButton->setObjectName(QStringLiteral("reviseButton"));

        verticalLayout_2->addWidget(reviseButton);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        fileNameLineEdit = new QLineEdit(horizontalLayoutWidget);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, fileNameLineEdit);

        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, addButton);


        verticalLayout->addLayout(formLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        CodeRevisionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CodeRevisionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        CodeRevisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CodeRevisionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CodeRevisionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CodeRevisionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CodeRevisionClass->setStatusBar(statusBar);

        retranslateUi(CodeRevisionClass);

        QMetaObject::connectSlotsByName(CodeRevisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *CodeRevisionClass)
    {
        CodeRevisionClass->setWindowTitle(QApplication::translate("CodeRevisionClass", "CodeRevision", 0));
        label->setText(QApplication::translate("CodeRevisionClass", "Number of files left to revise:", 0));
        toReviseLabel->setText(QApplication::translate("CodeRevisionClass", "0", 0));
        label_3->setText(QApplication::translate("CodeRevisionClass", "Number of files revised so far:", 0));
        revisedLabel->setText(QApplication::translate("CodeRevisionClass", "0", 0));
        reviseButton->setText(QApplication::translate("CodeRevisionClass", "Revise Selected", 0));
        label_5->setText(QApplication::translate("CodeRevisionClass", "Source file name:", 0));
        addButton->setText(QApplication::translate("CodeRevisionClass", "ADD ", 0));
    } // retranslateUi

};

namespace Ui {
    class CodeRevisionClass: public Ui_CodeRevisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEREVISION_H

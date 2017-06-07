/********************************************************************************
** Form generated from reading UI file 'AdoptionListView.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADOPTIONLISTVIEW_H
#define UI_ADOPTIONLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdoptionListView
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *exitButton;
    QTableView *tableView;

    void setupUi(QWidget *AdoptionListView)
    {
        if (AdoptionListView->objectName().isEmpty())
            AdoptionListView->setObjectName(QStringLiteral("AdoptionListView"));
        AdoptionListView->resize(613, 469);
        verticalLayoutWidget = new QWidget(AdoptionListView);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 19, 591, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        exitButton = new QPushButton(verticalLayoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        verticalLayout->addWidget(exitButton);

        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(AdoptionListView);

        QMetaObject::connectSlotsByName(AdoptionListView);
    } // setupUi

    void retranslateUi(QWidget *AdoptionListView)
    {
        AdoptionListView->setWindowTitle(QApplication::translate("AdoptionListView", "AdoptionListView", 0));
        exitButton->setText(QApplication::translate("AdoptionListView", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class AdoptionListView: public Ui_AdoptionListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADOPTIONLISTVIEW_H

/********************************************************************************
** Form generated from reading UI file 'userchoice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCHOICE_H
#define UI_USERCHOICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserChoice
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *csvRadioButton;
    QRadioButton *htmlRadioButton;
    QPushButton *pushButton;

    void setupUi(QWidget *UserChoice)
    {
        if (UserChoice->objectName().isEmpty())
            UserChoice->setObjectName(QStringLiteral("UserChoice"));
        UserChoice->resize(451, 163);
        verticalLayoutWidget = new QWidget(UserChoice);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 431, 151));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        csvRadioButton = new QRadioButton(verticalLayoutWidget);
        csvRadioButton->setObjectName(QStringLiteral("csvRadioButton"));
        csvRadioButton->setChecked(true);

        horizontalLayout_2->addWidget(csvRadioButton);

        htmlRadioButton = new QRadioButton(verticalLayoutWidget);
        htmlRadioButton->setObjectName(QStringLiteral("htmlRadioButton"));

        horizontalLayout_2->addWidget(htmlRadioButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(UserChoice);

        QMetaObject::connectSlotsByName(UserChoice);
    } // setupUi

    void retranslateUi(QWidget *UserChoice)
    {
        UserChoice->setWindowTitle(QApplication::translate("UserChoice", "UserChoice", 0));
        label->setText(QApplication::translate("UserChoice", "Chose the type of the file for the user list:", 0));
        csvRadioButton->setText(QApplication::translate("UserChoice", "CSVFile", 0));
        htmlRadioButton->setText(QApplication::translate("UserChoice", "HTMLFile", 0));
        pushButton->setText(QApplication::translate("UserChoice", "Okay", 0));
    } // retranslateUi

};

namespace Ui {
    class UserChoice: public Ui_UserChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCHOICE_H

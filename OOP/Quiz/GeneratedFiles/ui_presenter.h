/********************************************************************************
** Form generated from reading UI file 'presenter.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESENTER_H
#define UI_PRESENTER_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_presenter
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QListWidget *questionListWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *idLineEdit;
    QLabel *label_2;
    QLineEdit *textLineEdit;
    QLabel *label_3;
    QLineEdit *answerLineEdit;
    QLabel *label_4;
    QLineEdit *scoreLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *presenter)
    {
        if (presenter->objectName().isEmpty())
            presenter->setObjectName(QStringLiteral("presenter"));
        presenter->resize(639, 449);
        horizontalLayoutWidget = new QWidget(presenter);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 19, 601, 411));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        questionListWidget = new QListWidget(horizontalLayoutWidget);
        questionListWidget->setObjectName(QStringLiteral("questionListWidget"));

        verticalLayout_2->addWidget(questionListWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        idLineEdit = new QLineEdit(horizontalLayoutWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        textLineEdit = new QLineEdit(horizontalLayoutWidget);
        textLineEdit->setObjectName(QStringLiteral("textLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textLineEdit);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        answerLineEdit = new QLineEdit(horizontalLayoutWidget);
        answerLineEdit->setObjectName(QStringLiteral("answerLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, answerLineEdit);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        scoreLineEdit = new QLineEdit(horizontalLayoutWidget);
        scoreLineEdit->setObjectName(QStringLiteral("scoreLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, scoreLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(4, QFormLayout::LabelRole, horizontalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton);


        verticalLayout->addLayout(formLayout);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(presenter);

        QMetaObject::connectSlotsByName(presenter);
    } // setupUi

    void retranslateUi(QWidget *presenter)
    {
        presenter->setWindowTitle(QApplication::translate("presenter", "presenter", 0));
        label->setText(QApplication::translate("presenter", "ID:", 0));
        label_2->setText(QApplication::translate("presenter", "Text:", 0));
        label_3->setText(QApplication::translate("presenter", "Answer:", 0));
        label_4->setText(QApplication::translate("presenter", "Score:", 0));
        pushButton->setText(QApplication::translate("presenter", "Add Question", 0));
    } // retranslateUi

};

namespace Ui {
    class presenter: public Ui_presenter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESENTER_H

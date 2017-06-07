/********************************************************************************
** Form generated from reading UI file 'dogshelterqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOGSHELTERQT_H
#define UI_DOGSHELTERQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DogShelterQTClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QComboBox *filterCombo;
    QListWidget *dogListWidget;
    QHBoxLayout *buttonLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QFormLayout *formLayout;
    QLabel *breedLabel;
    QLineEdit *breedLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *ageLabel;
    QLineEdit *ageLineEdit;
    QLabel *linkLabel;
    QLineEdit *linkLineEdit;
    QPushButton *toUserMode;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QPushButton *statButton;
    QVBoxLayout *rightLayout;
    QLabel *nextLabel;
    QHBoxLayout *nextLayout;
    QLineEdit *nextDogLineEdit;
    QPushButton *nextButton;
    QPushButton *adoptCurrent;
    QListWidget *adoptedListWidget;
    QLabel *filterLabel;
    QFormLayout *filterForm;
    QLabel *breedLabel2;
    QLineEdit *breedLineEditFilter;
    QLabel *ageLabel2;
    QLineEdit *ageLineEditFilter;
    QPushButton *filterButton;
    QLabel *fileNameLabel;
    QLineEdit *fileNameLineEdit;
    QPushButton *savetoFileButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *adoptAll;
    QPushButton *toAdminMode;
    QMenuBar *menuBar;
    QMenu *menuMain;
    QMenu *menuStatistics;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DogShelterQTClass)
    {
        if (DogShelterQTClass->objectName().isEmpty())
            DogShelterQTClass->setObjectName(QStringLiteral("DogShelterQTClass"));
        DogShelterQTClass->resize(848, 555);
        centralWidget = new QWidget(DogShelterQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        leftLayout = new QVBoxLayout();
        leftLayout->setSpacing(6);
        leftLayout->setObjectName(QStringLiteral("leftLayout"));
        leftLayout->setContentsMargins(0, -1, -1, 1);
        filterCombo = new QComboBox(centralWidget);
        filterCombo->setObjectName(QStringLiteral("filterCombo"));

        leftLayout->addWidget(filterCombo);

        dogListWidget = new QListWidget(centralWidget);
        dogListWidget->setObjectName(QStringLiteral("dogListWidget"));

        leftLayout->addWidget(dogListWidget);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(6);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        buttonLayout->addWidget(addButton);

        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        buttonLayout->addWidget(removeButton);

        updateButton = new QPushButton(centralWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        buttonLayout->addWidget(updateButton);


        leftLayout->addLayout(buttonLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        breedLabel = new QLabel(centralWidget);
        breedLabel->setObjectName(QStringLiteral("breedLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, breedLabel);

        breedLineEdit = new QLineEdit(centralWidget);
        breedLineEdit->setObjectName(QStringLiteral("breedLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, breedLineEdit);

        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(centralWidget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nameLineEdit);

        ageLabel = new QLabel(centralWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ageLabel);

        ageLineEdit = new QLineEdit(centralWidget);
        ageLineEdit->setObjectName(QStringLiteral("ageLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ageLineEdit);

        linkLabel = new QLabel(centralWidget);
        linkLabel->setObjectName(QStringLiteral("linkLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, linkLabel);

        linkLineEdit = new QLineEdit(centralWidget);
        linkLineEdit->setObjectName(QStringLiteral("linkLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, linkLineEdit);


        leftLayout->addLayout(formLayout);

        toUserMode = new QPushButton(centralWidget);
        toUserMode->setObjectName(QStringLiteral("toUserMode"));

        leftLayout->addWidget(toUserMode);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));

        horizontalLayout_4->addWidget(undoButton);

        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));

        horizontalLayout_4->addWidget(redoButton);


        leftLayout->addLayout(horizontalLayout_4);

        statButton = new QPushButton(centralWidget);
        statButton->setObjectName(QStringLiteral("statButton"));

        leftLayout->addWidget(statButton);


        mainLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setSpacing(6);
        rightLayout->setObjectName(QStringLiteral("rightLayout"));
        nextLabel = new QLabel(centralWidget);
        nextLabel->setObjectName(QStringLiteral("nextLabel"));

        rightLayout->addWidget(nextLabel);

        nextLayout = new QHBoxLayout();
        nextLayout->setSpacing(6);
        nextLayout->setObjectName(QStringLiteral("nextLayout"));
        nextDogLineEdit = new QLineEdit(centralWidget);
        nextDogLineEdit->setObjectName(QStringLiteral("nextDogLineEdit"));

        nextLayout->addWidget(nextDogLineEdit);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        nextLayout->addWidget(nextButton);

        adoptCurrent = new QPushButton(centralWidget);
        adoptCurrent->setObjectName(QStringLiteral("adoptCurrent"));

        nextLayout->addWidget(adoptCurrent);


        rightLayout->addLayout(nextLayout);

        adoptedListWidget = new QListWidget(centralWidget);
        adoptedListWidget->setObjectName(QStringLiteral("adoptedListWidget"));
        adoptedListWidget->setEnabled(true);

        rightLayout->addWidget(adoptedListWidget);

        filterLabel = new QLabel(centralWidget);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));

        rightLayout->addWidget(filterLabel);

        filterForm = new QFormLayout();
        filterForm->setSpacing(6);
        filterForm->setObjectName(QStringLiteral("filterForm"));
        breedLabel2 = new QLabel(centralWidget);
        breedLabel2->setObjectName(QStringLiteral("breedLabel2"));

        filterForm->setWidget(1, QFormLayout::LabelRole, breedLabel2);

        breedLineEditFilter = new QLineEdit(centralWidget);
        breedLineEditFilter->setObjectName(QStringLiteral("breedLineEditFilter"));

        filterForm->setWidget(1, QFormLayout::FieldRole, breedLineEditFilter);

        ageLabel2 = new QLabel(centralWidget);
        ageLabel2->setObjectName(QStringLiteral("ageLabel2"));

        filterForm->setWidget(0, QFormLayout::LabelRole, ageLabel2);

        ageLineEditFilter = new QLineEdit(centralWidget);
        ageLineEditFilter->setObjectName(QStringLiteral("ageLineEditFilter"));

        filterForm->setWidget(0, QFormLayout::FieldRole, ageLineEditFilter);


        rightLayout->addLayout(filterForm);

        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        rightLayout->addWidget(filterButton);

        fileNameLabel = new QLabel(centralWidget);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));

        rightLayout->addWidget(fileNameLabel);

        fileNameLineEdit = new QLineEdit(centralWidget);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));

        rightLayout->addWidget(fileNameLineEdit);

        savetoFileButton = new QPushButton(centralWidget);
        savetoFileButton->setObjectName(QStringLiteral("savetoFileButton"));

        rightLayout->addWidget(savetoFileButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adoptAll = new QPushButton(centralWidget);
        adoptAll->setObjectName(QStringLiteral("adoptAll"));

        horizontalLayout->addWidget(adoptAll);

        toAdminMode = new QPushButton(centralWidget);
        toAdminMode->setObjectName(QStringLiteral("toAdminMode"));

        horizontalLayout->addWidget(toAdminMode);


        rightLayout->addLayout(horizontalLayout);


        mainLayout->addLayout(rightLayout);


        horizontalLayout_2->addLayout(mainLayout);

        DogShelterQTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DogShelterQTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 21));
        menuMain = new QMenu(menuBar);
        menuMain->setObjectName(QStringLiteral("menuMain"));
        menuStatistics = new QMenu(menuBar);
        menuStatistics->setObjectName(QStringLiteral("menuStatistics"));
        DogShelterQTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DogShelterQTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DogShelterQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DogShelterQTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DogShelterQTClass->setStatusBar(statusBar);

        menuBar->addAction(menuMain->menuAction());
        menuBar->addAction(menuStatistics->menuAction());

        retranslateUi(DogShelterQTClass);

        QMetaObject::connectSlotsByName(DogShelterQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *DogShelterQTClass)
    {
        DogShelterQTClass->setWindowTitle(QApplication::translate("DogShelterQTClass", "DogShelterQT", 0));
        filterCombo->clear();
        filterCombo->insertItems(0, QStringList()
         << QApplication::translate("DogShelterQTClass", "Detailed", 0)
         << QApplication::translate("DogShelterQTClass", "Short", 0)
        );
        addButton->setText(QApplication::translate("DogShelterQTClass", "Add", 0));
        removeButton->setText(QApplication::translate("DogShelterQTClass", "Remove", 0));
        updateButton->setText(QApplication::translate("DogShelterQTClass", "Update", 0));
        breedLabel->setText(QApplication::translate("DogShelterQTClass", "Breed:", 0));
        nameLabel->setText(QApplication::translate("DogShelterQTClass", "Name:", 0));
        ageLabel->setText(QApplication::translate("DogShelterQTClass", "Age:", 0));
        linkLabel->setText(QApplication::translate("DogShelterQTClass", "Link:", 0));
        toUserMode->setText(QApplication::translate("DogShelterQTClass", "Go to User Mode", 0));
        undoButton->setText(QApplication::translate("DogShelterQTClass", "Undo", 0));
        redoButton->setText(QApplication::translate("DogShelterQTClass", "Redo", 0));
        statButton->setText(QApplication::translate("DogShelterQTClass", "Statistics", 0));
        nextLabel->setText(QApplication::translate("DogShelterQTClass", "Current Dog:", 0));
        nextButton->setText(QApplication::translate("DogShelterQTClass", "Next", 0));
        adoptCurrent->setText(QApplication::translate("DogShelterQTClass", "Adopt this dog", 0));
        filterLabel->setText(QApplication::translate("DogShelterQTClass", "Filter details:", 0));
        breedLabel2->setText(QApplication::translate("DogShelterQTClass", "Breed:", 0));
        breedLineEditFilter->setText(QString());
        ageLabel2->setText(QApplication::translate("DogShelterQTClass", "Age:", 0));
        filterButton->setText(QApplication::translate("DogShelterQTClass", "Filter", 0));
        fileNameLabel->setText(QApplication::translate("DogShelterQTClass", "File name:", 0));
        savetoFileButton->setText(QApplication::translate("DogShelterQTClass", "Save to file", 0));
        adoptAll->setText(QApplication::translate("DogShelterQTClass", "Adopt all dogs", 0));
        toAdminMode->setText(QApplication::translate("DogShelterQTClass", "Go to Admin Mode", 0));
        menuMain->setTitle(QApplication::translate("DogShelterQTClass", "Main", 0));
        menuStatistics->setTitle(QApplication::translate("DogShelterQTClass", "Statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class DogShelterQTClass: public Ui_DogShelterQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOGSHELTERQT_H

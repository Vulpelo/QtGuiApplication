/********************************************************************************
** Form generated from reading UI file 'AddMainWord.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMAINWORD_H
#define UI_ADDMAINWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMainWord
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *NewMainWord_lineEdit;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AddButton;
    QPushButton *CancelButton;

    void setupUi(QWidget *AddMainWord)
    {
        if (AddMainWord->objectName().isEmpty())
            AddMainWord->setObjectName(QStringLiteral("AddMainWord"));
        AddMainWord->resize(394, 115);
        AddMainWord->setMinimumSize(QSize(394, 115));
        AddMainWord->setMaximumSize(QSize(396, 115));
        horizontalLayoutWidget = new QWidget(AddMainWord);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        NewMainWord_lineEdit = new QLineEdit(horizontalLayoutWidget);
        NewMainWord_lineEdit->setObjectName(QStringLiteral("NewMainWord_lineEdit"));

        verticalLayout->addWidget(NewMainWord_lineEdit);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        AddButton = new QPushButton(horizontalLayoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setAutoDefault(true);

        verticalLayout_2->addWidget(AddButton);

        CancelButton = new QPushButton(horizontalLayoutWidget);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setAutoDefault(true);

        verticalLayout_2->addWidget(CancelButton);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(AddMainWord);

        QMetaObject::connectSlotsByName(AddMainWord);
    } // setupUi

    void retranslateUi(QWidget *AddMainWord)
    {
        AddMainWord->setWindowTitle(QApplication::translate("AddMainWord", "AddMainWord", Q_NULLPTR));
        label->setText(QApplication::translate("AddMainWord", "S\305\202owo g\305\202\303\263wne", Q_NULLPTR));
        AddButton->setText(QApplication::translate("AddMainWord", "Add", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("AddMainWord", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddMainWord: public Ui_AddMainWord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMAINWORD_H

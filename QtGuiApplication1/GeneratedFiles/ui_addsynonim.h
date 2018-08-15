/********************************************************************************
** Form generated from reading UI file 'addsynonim.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSYNONIM_H
#define UI_ADDSYNONIM_H

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

class Ui_AddSynonim
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *mainWordLineEdit;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *newWordLineEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *AddSynonim)
    {
        if (AddSynonim->objectName().isEmpty())
            AddSynonim->setObjectName(QStringLiteral("AddSynonim"));
        AddSynonim->resize(387, 149);
        AddSynonim->setMinimumSize(QSize(387, 149));
        AddSynonim->setMaximumSize(QSize(387, 149));
        horizontalLayoutWidget = new QWidget(AddSynonim);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 371, 131));
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

        mainWordLineEdit = new QLineEdit(horizontalLayoutWidget);
        mainWordLineEdit->setObjectName(QStringLiteral("mainWordLineEdit"));

        verticalLayout->addWidget(mainWordLineEdit);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        newWordLineEdit = new QLineEdit(horizontalLayoutWidget);
        newWordLineEdit->setObjectName(QStringLiteral("newWordLineEdit"));

        verticalLayout->addWidget(newWordLineEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setAutoDefault(true);

        verticalLayout_2->addWidget(addButton);

        cancelButton = new QPushButton(horizontalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(true);

        verticalLayout_2->addWidget(cancelButton);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(AddSynonim);

        addButton->setDefault(false);
        cancelButton->setDefault(false);


        QMetaObject::connectSlotsByName(AddSynonim);
    } // setupUi

    void retranslateUi(QWidget *AddSynonim)
    {
        AddSynonim->setWindowTitle(QApplication::translate("AddSynonim", "AddSynonim", Q_NULLPTR));
        label->setText(QApplication::translate("AddSynonim", "S\305\202owo podstawowe", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddSynonim", "Synonim do s\305\202owa podstawowego", Q_NULLPTR));
        addButton->setText(QApplication::translate("AddSynonim", "Add", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AddSynonim", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddSynonim: public Ui_AddSynonim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSYNONIM_H

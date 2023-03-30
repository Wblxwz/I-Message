/********************************************************************************
** Form generated from reading UI file 'AddFriends.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIENDS_H
#define UI_ADDFRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriendsClass
{
public:
    QLineEdit *chazhao;
    QPushButton *chazhaobutton;
    QTableView *tableView;

    void setupUi(QWidget *AddFriendsClass)
    {
        if (AddFriendsClass->objectName().isEmpty())
            AddFriendsClass->setObjectName(QString::fromUtf8("AddFriendsClass"));
        AddFriendsClass->resize(600, 400);
        chazhao = new QLineEdit(AddFriendsClass);
        chazhao->setObjectName(QString::fromUtf8("chazhao"));
        chazhao->setGeometry(QRect(70, 0, 211, 31));
        QFont font;
        font.setPointSize(10);
        chazhao->setFont(font);
        chazhaobutton = new QPushButton(AddFriendsClass);
        chazhaobutton->setObjectName(QString::fromUtf8("chazhaobutton"));
        chazhaobutton->setGeometry(QRect(440, 0, 81, 31));
        chazhaobutton->setFont(font);
        tableView = new QTableView(AddFriendsClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(70, 50, 451, 331));

        retranslateUi(AddFriendsClass);

        QMetaObject::connectSlotsByName(AddFriendsClass);
    } // setupUi

    void retranslateUi(QWidget *AddFriendsClass)
    {
        AddFriendsClass->setWindowTitle(QCoreApplication::translate("AddFriendsClass", "AddFriends", nullptr));
        chazhao->setPlaceholderText(QCoreApplication::translate("AddFriendsClass", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267/\346\230\265\347\247\260", nullptr));
        chazhaobutton->setText(QCoreApplication::translate("AddFriendsClass", "\346\237\245\346\211\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriendsClass: public Ui_AddFriendsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIENDS_H

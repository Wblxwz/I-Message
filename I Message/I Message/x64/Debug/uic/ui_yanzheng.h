/********************************************************************************
** Form generated from reading UI file 'yanzheng.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YANZHENG_H
#define UI_YANZHENG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_yanzhengClass
{
public:
    QLabel *account;
    QLabel *name;
    QTextEdit *yanzheng;
    QPushButton *fasong;
    QPushButton *guanbi;

    void setupUi(QWidget *yanzhengClass)
    {
        if (yanzhengClass->objectName().isEmpty())
            yanzhengClass->setObjectName(QString::fromUtf8("yanzhengClass"));
        yanzhengClass->resize(487, 302);
        account = new QLabel(yanzhengClass);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(10, 60, 161, 41));
        QFont font;
        font.setPointSize(12);
        account->setFont(font);
        name = new QLabel(yanzhengClass);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 10, 211, 41));
        QFont font1;
        font1.setPointSize(16);
        name->setFont(font1);
        yanzheng = new QTextEdit(yanzhengClass);
        yanzheng->setObjectName(QString::fromUtf8("yanzheng"));
        yanzheng->setGeometry(QRect(140, 30, 301, 191));
        QFont font2;
        font2.setPointSize(10);
        yanzheng->setFont(font2);
        fasong = new QPushButton(yanzhengClass);
        fasong->setObjectName(QString::fromUtf8("fasong"));
        fasong->setGeometry(QRect(210, 270, 75, 24));
        fasong->setFont(font2);
        guanbi = new QPushButton(yanzhengClass);
        guanbi->setObjectName(QString::fromUtf8("guanbi"));
        guanbi->setGeometry(QRect(340, 270, 75, 24));
        guanbi->setFont(font2);

        retranslateUi(yanzhengClass);

        QMetaObject::connectSlotsByName(yanzhengClass);
    } // setupUi

    void retranslateUi(QWidget *yanzhengClass)
    {
        yanzhengClass->setWindowTitle(QCoreApplication::translate("yanzhengClass", "yanzheng", nullptr));
        account->setText(QCoreApplication::translate("yanzhengClass", "account", nullptr));
        name->setText(QCoreApplication::translate("yanzhengClass", "name", nullptr));
        yanzheng->setPlaceholderText(QCoreApplication::translate("yanzhengClass", "\351\252\214\350\257\201\344\277\241\346\201\257\357\274\232\346\210\221\346\230\257...", nullptr));
        fasong->setText(QCoreApplication::translate("yanzhengClass", "\345\217\221\351\200\201", nullptr));
        guanbi->setText(QCoreApplication::translate("yanzhengClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class yanzhengClass: public Ui_yanzhengClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YANZHENG_H

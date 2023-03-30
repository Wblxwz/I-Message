/********************************************************************************
** Form generated from reading UI file 'XinShenQing.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XINSHENQING_H
#define UI_XINSHENQING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XinShenQingClass
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *tongyi;
    QPushButton *jujue;

    void setupUi(QMainWindow *XinShenQingClass)
    {
        if (XinShenQingClass->objectName().isEmpty())
            XinShenQingClass->setObjectName(QString::fromUtf8("XinShenQingClass"));
        XinShenQingClass->resize(600, 400);
        centralWidget = new QWidget(XinShenQingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(60, 20, 481, 321));
        tongyi = new QPushButton(centralWidget);
        tongyi->setObjectName(QString::fromUtf8("tongyi"));
        tongyi->setGeometry(QRect(130, 370, 75, 24));
        QFont font;
        font.setPointSize(10);
        tongyi->setFont(font);
        jujue = new QPushButton(centralWidget);
        jujue->setObjectName(QString::fromUtf8("jujue"));
        jujue->setGeometry(QRect(350, 370, 75, 24));
        jujue->setFont(font);
        XinShenQingClass->setCentralWidget(centralWidget);

        retranslateUi(XinShenQingClass);

        QMetaObject::connectSlotsByName(XinShenQingClass);
    } // setupUi

    void retranslateUi(QMainWindow *XinShenQingClass)
    {
        XinShenQingClass->setWindowTitle(QCoreApplication::translate("XinShenQingClass", "XinShenQing", nullptr));
        tongyi->setText(QCoreApplication::translate("XinShenQingClass", "\345\220\214\346\204\217", nullptr));
        jujue->setText(QCoreApplication::translate("XinShenQingClass", "\346\213\222\347\273\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XinShenQingClass: public Ui_XinShenQingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XINSHENQING_H

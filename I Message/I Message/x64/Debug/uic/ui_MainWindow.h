/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_3;
    QListView *lianxiren;
    QWidget *tab_2;
    QLabel *name;
    QPushButton *addButton;
    QPushButton *xinhaoyou;
    QLabel *bian;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(301, 675);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 50, 311, 591));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{width:102.5}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        lianxiren = new QListView(tab_3);
        lianxiren->setObjectName(QString::fromUtf8("lianxiren"));
        lianxiren->setGeometry(QRect(10, 10, 281, 551));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        name = new QLabel(centralWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(0, 0, 221, 41));
        QFont font1;
        font1.setPointSize(17);
        name->setFont(font1);
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(0, 650, 75, 24));
        addButton->setFont(font);
        xinhaoyou = new QPushButton(centralWidget);
        xinhaoyou->setObjectName(QString::fromUtf8("xinhaoyou"));
        xinhaoyou->setGeometry(QRect(204, 650, 91, 24));
        xinhaoyou->setFont(font);
        bian = new QLabel(centralWidget);
        bian->setObjectName(QString::fromUtf8("bian"));
        bian->setGeometry(QRect(230, 10, 71, 31));
        bian->setFont(font);
        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindowClass", "\346\266\210\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindowClass", "\350\201\224\347\263\273\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindowClass", "\347\251\272\351\227\264", nullptr));
        name->setText(QCoreApplication::translate("MainWindowClass", "wblxwz", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindowClass", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        xinhaoyou->setText(QCoreApplication::translate("MainWindowClass", "\346\226\260\345\245\275\345\217\213(0)", nullptr));
        bian->setText(QCoreApplication::translate("MainWindowClass", "bian", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

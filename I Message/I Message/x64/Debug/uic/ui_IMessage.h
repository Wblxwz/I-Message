/********************************************************************************
** Form generated from reading UI file 'IMessage.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMESSAGE_H
#define UI_IMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IMessageClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *pwd;
    QPushButton *zhuce;
    QSpacerItem *verticalSpacer_5;
    QCheckBox *jizhu;
    QSpacerItem *horizontalSpacer;
    QPushButton *denglu;
    QCheckBox *zidong;
    QPushButton *zhaohui;
    QComboBox *account;
    QWidget *page_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QCheckBox *queren;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QLabel *nametishi;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QPushButton *lijizhuce;
    QSpacerItem *verticalSpacer_8;
    QLabel *pwdtishi;
    QLabel *tishi;
    QLineEdit *name;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *password;

    void setupUi(QMainWindow *IMessageClass)
    {
        if (IMessageClass->objectName().isEmpty())
            IMessageClass->setObjectName(QString::fromUtf8("IMessageClass"));
        IMessageClass->resize(425, 305);
        centralWidget = new QWidget(IMessageClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, -10, 431, 321));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        widget = new QWidget(page_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, -20, 431, 341));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        pwd = new QLineEdit(widget);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        QFont font;
        font.setPointSize(10);
        pwd->setFont(font);
        pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(pwd, 3, 1, 1, 3);

        zhuce = new QPushButton(widget);
        zhuce->setObjectName(QString::fromUtf8("zhuce"));
        zhuce->setFont(font);

        gridLayout->addWidget(zhuce, 8, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 7, 1, 1, 1);

        jizhu = new QCheckBox(widget);
        jizhu->setObjectName(QString::fromUtf8("jizhu"));
        jizhu->setFont(font);

        gridLayout->addWidget(jizhu, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        denglu = new QPushButton(widget);
        denglu->setObjectName(QString::fromUtf8("denglu"));
        denglu->setFont(font);

        gridLayout->addWidget(denglu, 6, 1, 1, 3);

        zidong = new QCheckBox(widget);
        zidong->setObjectName(QString::fromUtf8("zidong"));
        zidong->setFont(font);

        gridLayout->addWidget(zidong, 4, 1, 1, 1);

        zhaohui = new QPushButton(widget);
        zhaohui->setObjectName(QString::fromUtf8("zhaohui"));
        zhaohui->setFont(font);

        gridLayout->addWidget(zhaohui, 4, 3, 1, 1);

        account = new QComboBox(widget);
        account->setObjectName(QString::fromUtf8("account"));

        gridLayout->addWidget(account, 1, 1, 1, 3);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        widget_2 = new QWidget(page_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 10, 421, 301));
        widget_2->setFont(font);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 6, 2, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout_2->addWidget(label, 7, 2, 1, 1);

        queren = new QCheckBox(widget_2);
        queren->setObjectName(QString::fromUtf8("queren"));

        gridLayout_2->addWidget(queren, 7, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 9, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 2, 1, 1);

        nametishi = new QLabel(widget_2);
        nametishi->setObjectName(QString::fromUtf8("nametishi"));
        nametishi->setEnabled(true);
        QFont font1;
        font1.setPointSize(10);
        font1.setStyleStrategy(QFont::PreferDefault);
        nametishi->setFont(font1);

        gridLayout_2->addWidget(nametishi, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 3, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 3, 2, 1, 1);

        lijizhuce = new QPushButton(widget_2);
        lijizhuce->setObjectName(QString::fromUtf8("lijizhuce"));
        lijizhuce->setFont(font);

        gridLayout_2->addWidget(lijizhuce, 9, 2, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 11, 2, 1, 1);

        pwdtishi = new QLabel(widget_2);
        pwdtishi->setObjectName(QString::fromUtf8("pwdtishi"));
        pwdtishi->setEnabled(true);
        pwdtishi->setFont(font1);

        gridLayout_2->addWidget(pwdtishi, 5, 2, 1, 1);

        tishi = new QLabel(widget_2);
        tishi->setObjectName(QString::fromUtf8("tishi"));
        tishi->setEnabled(true);
        tishi->setFont(font1);

        gridLayout_2->addWidget(tishi, 10, 2, 1, 1);

        name = new QLineEdit(widget_2);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);
        name->setMaxLength(16);

        gridLayout_2->addWidget(name, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 7, 0, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_9, 8, 2, 1, 1);

        password = new QLineEdit(widget_2);
        password->setObjectName(QString::fromUtf8("password"));
        password->setFont(font);
        password->setMaxLength(16);
        password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(password, 4, 2, 1, 1);

        stackedWidget->addWidget(page_4);
        IMessageClass->setCentralWidget(centralWidget);

        retranslateUi(IMessageClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IMessageClass);
    } // setupUi

    void retranslateUi(QMainWindow *IMessageClass)
    {
        IMessageClass->setWindowTitle(QCoreApplication::translate("IMessageClass", "IMessage", nullptr));
        pwd->setInputMask(QString());
        zhuce->setText(QCoreApplication::translate("IMessageClass", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        jizhu->setText(QCoreApplication::translate("IMessageClass", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        denglu->setText(QCoreApplication::translate("IMessageClass", "\347\231\273\345\275\225", nullptr));
        zidong->setText(QCoreApplication::translate("IMessageClass", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        zhaohui->setText(QCoreApplication::translate("IMessageClass", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("IMessageClass", "\346\210\221\345\267\262\351\230\205\350\257\273\345\271\266\345\220\214\346\204\217\346\234\215\345\212\241\345\215\217\350\256\256\345\222\214\351\232\220\347\247\201\344\277\235\346\212\244\346\214\207\345\274\225", nullptr));
        queren->setText(QString());
        nametishi->setText(QCoreApplication::translate("IMessageClass", "\346\230\265\347\247\260\344\270\215\345\217\257\344\273\245\344\270\272\347\251\272", nullptr));
        lijizhuce->setText(QCoreApplication::translate("IMessageClass", "\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        pwdtishi->setText(QCoreApplication::translate("IMessageClass", "\345\257\206\347\240\201\344\270\215\350\203\275\344\270\272\347\251\272", nullptr));
        tishi->setText(QCoreApplication::translate("IMessageClass", "\350\257\267\345\205\210\345\220\214\346\204\217\346\234\215\345\212\241\346\235\241\346\254\276\345\222\214\351\232\220\347\247\201\346\224\277\347\255\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IMessageClass: public Ui_IMessageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMESSAGE_H

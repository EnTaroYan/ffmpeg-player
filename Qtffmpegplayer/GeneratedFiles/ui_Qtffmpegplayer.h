/********************************************************************************
** Form generated from reading UI file 'Qtffmpegplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTFFMPEGPLAYER_H
#define UI_QTFFMPEGPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtffmpegplayerClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_a;
    QPushButton *pushButton_b;
    QLabel *labela;
    QLabel *labelb;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtffmpegplayerClass)
    {
        if (QtffmpegplayerClass->objectName().isEmpty())
            QtffmpegplayerClass->setObjectName(QStringLiteral("QtffmpegplayerClass"));
        QtffmpegplayerClass->resize(1423, 573);
        centralWidget = new QWidget(QtffmpegplayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_a = new QPushButton(centralWidget);
        pushButton_a->setObjectName(QStringLiteral("pushButton_a"));
        pushButton_a->setGeometry(QRect(10, 10, 91, 31));
        pushButton_b = new QPushButton(centralWidget);
        pushButton_b->setObjectName(QStringLiteral("pushButton_b"));
        pushButton_b->setGeometry(QRect(10, 60, 91, 31));
        labela = new QLabel(centralWidget);
        labela->setObjectName(QStringLiteral("labela"));
        labela->setGeometry(QRect(120, 10, 640, 480));
        labelb = new QLabel(centralWidget);
        labelb->setObjectName(QStringLiteral("labelb"));
        labelb->setGeometry(QRect(760, 10, 640, 480));
        QtffmpegplayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtffmpegplayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1423, 23));
        QtffmpegplayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtffmpegplayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtffmpegplayerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtffmpegplayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtffmpegplayerClass->setStatusBar(statusBar);

        retranslateUi(QtffmpegplayerClass);
        QObject::connect(pushButton_a, SIGNAL(clicked()), QtffmpegplayerClass, SLOT(button_a_click()));
        QObject::connect(pushButton_b, SIGNAL(clicked()), QtffmpegplayerClass, SLOT(button_b_click()));

        QMetaObject::connectSlotsByName(QtffmpegplayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtffmpegplayerClass)
    {
        QtffmpegplayerClass->setWindowTitle(QApplication::translate("QtffmpegplayerClass", "Qtffmpegplayer", Q_NULLPTR));
        pushButton_a->setText(QApplication::translate("QtffmpegplayerClass", "PushButton_a", Q_NULLPTR));
        pushButton_b->setText(QApplication::translate("QtffmpegplayerClass", "PushButton_b", Q_NULLPTR));
        labela->setText(QString());
        labelb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtffmpegplayerClass: public Ui_QtffmpegplayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTFFMPEGPLAYER_H

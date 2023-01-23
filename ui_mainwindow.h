/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QHBoxLayout *layoutMain;
    QVBoxLayout *layoutBtn;
    QPushButton *confrontaPk;
    QPushButton *resetType;
    QPushButton *resetSort;
    QPushButton *close;
    QVBoxLayout *layoutFiltri;
    QCheckBox *normal;
    QCheckBox *bug;
    QCheckBox *dark;
    QCheckBox *dragon;
    QCheckBox *electric;
    QCheckBox *fairy;
    QCheckBox *fighting;
    QCheckBox *fire;
    QCheckBox *flying;
    QCheckBox *ghost;
    QCheckBox *grass;
    QCheckBox *ground;
    QCheckBox *ice;
    QCheckBox *poison;
    QCheckBox *psychic;
    QCheckBox *rock;
    QCheckBox *steel;
    QCheckBox *water;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1039, 784);
        QFont font;
        //font.setFamilies({QString::fromUtf8("Segoe UI Emoji")});
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("QHeaderView::section {\n"
"  background-color: #DCDCDC;\n"
" padding: 4px;\n"
"font-weight: bold;\n"
" border-style: none;\n"
"border-bottom: 1px solid #fffff8;\n"
"border-right: 1px solid #fffff8;\n"
"}"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setDragDropOverwriteMode(false);
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->horizontalHeader()->setVisible(true);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setHighlightSections(true);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        horizontalLayout_2->addWidget(tableView);

        layoutMain = new QHBoxLayout();
        layoutMain->setObjectName("layoutMain");
        layoutMain->setSizeConstraint(QLayout::SetDefaultConstraint);
        layoutBtn = new QVBoxLayout();
        layoutBtn->setSpacing(7);
        layoutBtn->setObjectName("layoutBtn");
        confrontaPk = new QPushButton(centralwidget);
        confrontaPk->setObjectName("confrontaPk");

        layoutBtn->addWidget(confrontaPk);

        resetType = new QPushButton(centralwidget);
        resetType->setObjectName("resetType");

        layoutBtn->addWidget(resetType);

        resetSort = new QPushButton(centralwidget);
        resetSort->setObjectName("resetSort");

        layoutBtn->addWidget(resetSort);

        close = new QPushButton(centralwidget);
        close->setObjectName("close");

        layoutBtn->addWidget(close);

        layoutFiltri = new QVBoxLayout();
        layoutFiltri->setObjectName("layoutFiltri");
        normal = new QCheckBox(centralwidget);
        normal->setObjectName("normal");
        normal->setChecked(true);

        layoutFiltri->addWidget(normal);

        bug = new QCheckBox(centralwidget);
        bug->setObjectName("bug");
        bug->setChecked(true);

        layoutFiltri->addWidget(bug);

        dark = new QCheckBox(centralwidget);
        dark->setObjectName("dark");
        dark->setChecked(true);

        layoutFiltri->addWidget(dark);

        dragon = new QCheckBox(centralwidget);
        dragon->setObjectName("dragon");
        dragon->setChecked(true);

        layoutFiltri->addWidget(dragon);

        electric = new QCheckBox(centralwidget);
        electric->setObjectName("electric");
        electric->setChecked(true);

        layoutFiltri->addWidget(electric);

        fairy = new QCheckBox(centralwidget);
        fairy->setObjectName("fairy");
        fairy->setChecked(true);

        layoutFiltri->addWidget(fairy);

        fighting = new QCheckBox(centralwidget);
        fighting->setObjectName("fighting");
        fighting->setChecked(true);

        layoutFiltri->addWidget(fighting);

        fire = new QCheckBox(centralwidget);
        fire->setObjectName("fire");
        fire->setChecked(true);

        layoutFiltri->addWidget(fire);

        flying = new QCheckBox(centralwidget);
        flying->setObjectName("flying");
        flying->setChecked(true);

        layoutFiltri->addWidget(flying);

        ghost = new QCheckBox(centralwidget);
        ghost->setObjectName("ghost");
        ghost->setChecked(true);

        layoutFiltri->addWidget(ghost);

        grass = new QCheckBox(centralwidget);
        grass->setObjectName("grass");
        grass->setChecked(true);

        layoutFiltri->addWidget(grass);

        ground = new QCheckBox(centralwidget);
        ground->setObjectName("ground");
        ground->setChecked(true);

        layoutFiltri->addWidget(ground);

        ice = new QCheckBox(centralwidget);
        ice->setObjectName("ice");
        ice->setChecked(true);

        layoutFiltri->addWidget(ice);

        poison = new QCheckBox(centralwidget);
        poison->setObjectName("poison");
        poison->setChecked(true);

        layoutFiltri->addWidget(poison);

        psychic = new QCheckBox(centralwidget);
        psychic->setObjectName("psychic");
        psychic->setChecked(true);

        layoutFiltri->addWidget(psychic);

        rock = new QCheckBox(centralwidget);
        rock->setObjectName("rock");
        rock->setChecked(true);

        layoutFiltri->addWidget(rock);

        steel = new QCheckBox(centralwidget);
        steel->setObjectName("steel");
        steel->setChecked(true);

        layoutFiltri->addWidget(steel);

        water = new QCheckBox(centralwidget);
        water->setObjectName("water");
        water->setChecked(true);

        layoutFiltri->addWidget(water);


        layoutBtn->addLayout(layoutFiltri);


        layoutMain->addLayout(layoutBtn);


        horizontalLayout_2->addLayout(layoutMain);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pokedex", nullptr));
        confrontaPk->setText(QCoreApplication::translate("MainWindow", "Confronta Pokemon", nullptr));
        resetType->setText(QCoreApplication::translate("MainWindow", "Reset Tipi", nullptr));
        resetSort->setText(QCoreApplication::translate("MainWindow", "Reset Ordine", nullptr));
        close->setText(QCoreApplication::translate("MainWindow", "Esci", nullptr));
        normal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        bug->setText(QCoreApplication::translate("MainWindow", "Bug", nullptr));
        dark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        dragon->setText(QCoreApplication::translate("MainWindow", "Dragon", nullptr));
        electric->setText(QCoreApplication::translate("MainWindow", "Electric", nullptr));
        fairy->setText(QCoreApplication::translate("MainWindow", "Fairy", nullptr));
        fighting->setText(QCoreApplication::translate("MainWindow", "Fighting", nullptr));
        fire->setText(QCoreApplication::translate("MainWindow", "Fire", nullptr));
        flying->setText(QCoreApplication::translate("MainWindow", "Flying", nullptr));
        ghost->setText(QCoreApplication::translate("MainWindow", "Ghost", nullptr));
        grass->setText(QCoreApplication::translate("MainWindow", "Grass", nullptr));
        ground->setText(QCoreApplication::translate("MainWindow", "Ground", nullptr));
        ice->setText(QCoreApplication::translate("MainWindow", "Ice", nullptr));
        poison->setText(QCoreApplication::translate("MainWindow", "Poison", nullptr));
        psychic->setText(QCoreApplication::translate("MainWindow", "Psychic", nullptr));
        rock->setText(QCoreApplication::translate("MainWindow", "Rock", nullptr));
        steel->setText(QCoreApplication::translate("MainWindow", "Steel", nullptr));
        water->setText(QCoreApplication::translate("MainWindow", "Water", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

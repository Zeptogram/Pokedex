/********************************************************************************
** Form generated from reading UI file 'confronta.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFRONTA_H
#define UI_CONFRONTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Confronta
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *layoutSort;
    QPushButton *ordina;
    QVBoxLayout *layoutGraph;
    QVBoxLayout *layoutPk1;
    QComboBox *listaPk1;
    QLabel *imgPk1;
    QLabel *tipoPk1;
    QVBoxLayout *layoutPk2;
    QComboBox *listaPk2;
    QLabel *imgPk2;
    QLabel *tipoPk2;

    void setupUi(QMainWindow *Confronta)
    {
        if (Confronta->objectName().isEmpty())
            Confronta->setObjectName("Confronta");
        Confronta->resize(1501, 643);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Confronta->sizePolicy().hasHeightForWidth());
        Confronta->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Confronta);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        layoutSort = new QVBoxLayout();
        layoutSort->setObjectName("layoutSort");
        ordina = new QPushButton(centralwidget);
        ordina->setObjectName("ordina");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ordina->sizePolicy().hasHeightForWidth());
        ordina->setSizePolicy(sizePolicy1);

        layoutSort->addWidget(ordina);


        gridLayout->addLayout(layoutSort, 0, 1, 1, 1);

        layoutGraph = new QVBoxLayout();
        layoutGraph->setObjectName("layoutGraph");

        gridLayout->addLayout(layoutGraph, 1, 1, 1, 1);

        layoutPk1 = new QVBoxLayout();
        layoutPk1->setObjectName("layoutPk1");
        layoutPk1->setSizeConstraint(QLayout::SetDefaultConstraint);
        listaPk1 = new QComboBox(centralwidget);
        listaPk1->setObjectName("listaPk1");

        layoutPk1->addWidget(listaPk1);

        imgPk1 = new QLabel(centralwidget);
        imgPk1->setObjectName("imgPk1");
        sizePolicy.setHeightForWidth(imgPk1->sizePolicy().hasHeightForWidth());
        imgPk1->setSizePolicy(sizePolicy);

        layoutPk1->addWidget(imgPk1);

        tipoPk1 = new QLabel(centralwidget);
        tipoPk1->setObjectName("tipoPk1");
        sizePolicy1.setHeightForWidth(tipoPk1->sizePolicy().hasHeightForWidth());
        tipoPk1->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        tipoPk1->setFont(font);
        tipoPk1->setLayoutDirection(Qt::LeftToRight);

        layoutPk1->addWidget(tipoPk1);


        gridLayout->addLayout(layoutPk1, 0, 0, 2, 1);

        layoutPk2 = new QVBoxLayout();
        layoutPk2->setObjectName("layoutPk2");
        layoutPk2->setSizeConstraint(QLayout::SetDefaultConstraint);
        listaPk2 = new QComboBox(centralwidget);
        listaPk2->setObjectName("listaPk2");

        layoutPk2->addWidget(listaPk2);

        imgPk2 = new QLabel(centralwidget);
        imgPk2->setObjectName("imgPk2");
        sizePolicy.setHeightForWidth(imgPk2->sizePolicy().hasHeightForWidth());
        imgPk2->setSizePolicy(sizePolicy);

        layoutPk2->addWidget(imgPk2);

        tipoPk2 = new QLabel(centralwidget);
        tipoPk2->setObjectName("tipoPk2");
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tipoPk2->sizePolicy().hasHeightForWidth());
        tipoPk2->setSizePolicy(sizePolicy2);
        tipoPk2->setFont(font);

        layoutPk2->addWidget(tipoPk2);


        gridLayout->addLayout(layoutPk2, 0, 2, 2, 1);


        verticalLayout->addLayout(gridLayout);

        Confronta->setCentralWidget(centralwidget);

        retranslateUi(Confronta);

        QMetaObject::connectSlotsByName(Confronta);
    } // setupUi

    void retranslateUi(QMainWindow *Confronta)
    {
        Confronta->setWindowTitle(QCoreApplication::translate("Confronta", "Pokedex - Confronta", nullptr));
        ordina->setText(QCoreApplication::translate("Confronta", "Ordina in modo alfabetico", nullptr));
        imgPk1->setText(QCoreApplication::translate("Confronta", "Pokemon 1", nullptr));
        tipoPk1->setText(QCoreApplication::translate("Confronta", "Tipi 1", nullptr));
        imgPk2->setText(QCoreApplication::translate("Confronta", "Pokemon 2", nullptr));
        tipoPk2->setText(QCoreApplication::translate("Confronta", "Tipi 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Confronta: public Ui_Confronta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFRONTA_H

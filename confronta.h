#ifndef CONFRONTA_H
#define CONFRONTA_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QFile>
#include <QApplication>
#include <QtCharts>

// Da includere solo in versioni vecchie di Qt
//using namespace QtCharts;

namespace Ui {
class Confronta;
}

class Confronta : public QMainWindow
{
    Q_OBJECT

public:
    explicit Confronta(QWidget *parent = nullptr);
    ~Confronta();
    void initGraph();
    void fillCombobox();
    void setImage(QString img, bool label1);
    QString getPokemonData(QString nome);
    QStringList parsePokemon(QString pokemon);
    void updateGraph(int i, int j);
    void closeEvent(QCloseEvent *event);


private slots:
    void on_listaPk1_currentIndexChanged(int index);
    void on_listaPk2_currentIndexChanged(int index);

    void on_ordina_clicked();

signals:
    // Signal emesso quando chiudo la finestra
    void windowClose();

public slots:
    // Necessario per collegare la mainWindow a this (per poi mandare dopo il signal)
    void getMainWindow(MainWindow *main);

private:
    // Indici per tenere traccia delle opzioni bloccate nella combobox
    int itemLockedInCombobox1;
    int itemLockedInCombobox2;
    Ui::Confronta *ui;
    // Oggetti necessari per il grafico e condivisi con i metodi della classe
    QChartView *chartView;
    QPolarChart *chart;
    QLineSeries *series1 = new QLineSeries();
    QLineSeries *series2 = new QLineSeries();
    QValueAxis *radialAxis = new QValueAxis();
    MainWindow* main;
};

#endif // CONFRONTA_H

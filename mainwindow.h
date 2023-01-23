#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fillTable();
    void aggiornaFiltro();
    void filtra(QString filtro, int arg);
    void reset();


private slots:

    void on_normal_stateChanged(int arg1);

    void on_bug_stateChanged(int arg1);

    void on_dark_stateChanged(int arg1);

    void on_dragon_stateChanged(int arg1);

    void on_electric_stateChanged(int arg1);

    void on_fairy_stateChanged(int arg1);

    void on_fighting_stateChanged(int arg1);

    void on_fire_stateChanged(int arg1);

    void on_flying_stateChanged(int arg1);

    void on_ghost_stateChanged(int arg1);

    void on_grass_stateChanged(int arg1);

    void on_ground_stateChanged(int arg1);

    void on_ice_stateChanged(int arg1);

    void on_poison_stateChanged(int arg1);

    void on_psychic_stateChanged(int arg1);

    void on_rock_stateChanged(int arg1);

    void on_steel_stateChanged(int arg1);

    void on_water_stateChanged(int arg1);

    void on_resetType_clicked();

    void on_confrontaPk_clicked();

    void on_resetSort_clicked();

    void on_close_clicked();

signals:
    void shareMain(MainWindow *main);

public slots:
    void enableCompare();

private:
    Ui::MainWindow *ui;
    // Model e proxy per la tabella
    QStandardItemModel *model = new QStandardItemModel;
    QSortFilterProxyModel *proxy = new QSortFilterProxyModel();
    // Lista di filtri, al momento della creazione ci sono tutti
    // i tipi, in quanto li voglio mostrare tutti
    QStringList filters = {"Normal",
                           "Bug",
                           "Dark",
                           "Dragon",
                           "Electric",
                           "Fairy",
                           "Fighting",
                           "Fire",
                           "Flying",
                           "Ghost",
                           "Grass",
                           "Ground",
                           "Ice",
                           "Poison",
                           "Psychic",
                           "Rock",
                           "Steel",
                           "Water"
                          };
};
#endif // MAINWINDOW_H

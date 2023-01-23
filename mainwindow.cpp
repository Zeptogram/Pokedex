#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "confronta.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Inizializzo la tabella
    fillTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTable(){

    // Apro il file csv
    QFile csv("pokedex.csv");
    if(!csv.open(QIODevice::ReadOnly))
        return;
    // Apro lo stream
    QTextStream stream(&csv);
    // Creo un contatore per ogni item
    int count = 0;
    // Leggo la prima line
    QString primaRiga = stream.readLine();
    // Ovvero gli header della tabella, li splitto per ,
    QStringList nomiTabella = primaRiga.split(",");
    // Rimuovo la colonna con i path delle immagini
    nomiTabella.removeAt(0);
    // Imposto nel modello della tabella il numero di colonne
    model->setColumnCount(nomiTabella.size());
    // Imposto le label per gli header della tabella
    model->setHorizontalHeaderLabels(nomiTabella);
    // Leggo tutto il file csv
    while(!stream.atEnd()){
        // Leggo riga per riga
        QString line = stream.readLine();
        QStringList dati;
        // Se non ho tipi multipli per un pokemon
        // ovvero non ho le "
        if(line.indexOf('"') == -1) {
            // Posso splittare per ,
            dati = line.split(",");
            // Rimuovo le immagini
            dati.removeAt(0);
        }
        // Altrimenti devo gestire le "" dei tipi dividendo la
        // riga in 3 parti e poi splittandole per ,
        else {
            // Divido per "
            QStringList valoriDaSplittare = line.split('"');
            // Prendo la prima parte di dati
            QStringList prima = valoriDaSplittare[0].split(",");
            // Prendo i tipi
            QStringList tipiList = valoriDaSplittare[1].split(",");
            // Unisco i tipi in un'unica stringa mettendo la seconda
            // "a capo" (new line)
            QString tipi = tipiList.join("\n");
            // Prendo l'ultima parte dei dati
            QStringList dopo = valoriDaSplittare[2].split(",");
            // Aggiungo la prima parte dei dati alla struttura dati complessiva
            // Il for parte da 1 per saltare la colonna delle immagini
            for(int i = 1; i < prima.size(); i++)
                if(!(prima[i].isEmpty()))
                dati.append(prima[i]);
            // Aggiungo i tipi
            dati.append(tipi);
            // Aggiungo il resto
            for(int i = 0; i < dopo.size(); i++)
                if(!(dopo[i].isEmpty()))
                dati.append(dopo[i]);
        }
        // Una volta che ho i dati pronti all'inserimento
        // procedo all'inserimento di essi nella tabella
        for(int i = 0; i < dati.size(); i++){
            // Considero i dati in posizione 0 (il numero del pokemon)
            // e in posizione > 2 (tutte le statistiche) come int
            // in modo da garantire un ordinamento per numero
            // e non per stringa
            if(i == 0 || i > 2){
                // Converto a int
                int value = dati.at(i).toInt();
                // Creo l'item per la tabella
                QStandardItem *item = new QStandardItem();
                item->setData(value, Qt::DisplayRole);
                // Imposto l'item dalla riga,colonna (count, i)
                model->setItem(count, i, item);
            }
            else{
                // Altrimenti tratto l'item come stringa
                QString value = dati.at(i);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(count, i, item);
            }
        }
        // Aumento il contatore
        count ++;
    }
    // Flush e chiusura del file
    csv.flush();
    csv.close();
    // Imposto un proxy alla tabella per impostare i filtri del tipo
    ui->tableView->setModel(proxy);
    proxy->setSourceModel(model);
    // Imposto delle proprietà per la size della tabella
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // Nascondo la colonna con i numeri dei pokemon
    ui->tableView->setColumnHidden(0, true);
}


void MainWindow::aggiornaFiltro() {

    // Imposto la colonna dove il filtro deve essere applicato
    proxy->setFilterKeyColumn(2);
    // filters è una lista di stringhe con all'interno i filtri applicati
    if(filters.size() != 0)
        // Utilizzo una regex per filtrare prendendo ogni filtro in filters e concatenandoli
        // in un unica stringa con | (cioè l'or per regex)
        proxy->setFilterRegularExpression(QRegularExpression(filters.join('|')));
    else
        // Altrimenti non ho un tipo selezionato e non ho matches
        proxy->setFilterFixedString("No Match");

}

void MainWindow::filtra(QString filtro, int state){
    // Se non è checked
    if(state != 2)
    {
        // Rimuovo dalla lista di filtri il filtro impostato
        filters.removeAll(filtro);
        // Aggiorno il filtro (nuova regex)
        aggiornaFiltro();
    }
    else{
       // Altrimenti inserisco nella lista di filtri il filtro
       filters << filtro;
       // Aggiorno il filtro
       aggiornaFiltro();
    }
}

void MainWindow::reset(){

    // Resetto tutti i filtri (ovvero checko tutte le checkbox)
    ui->normal->setCheckState(Qt::Checked);
    ui->bug->setCheckState(Qt::Checked);
    ui->dark->setCheckState(Qt::Checked);
    ui->dragon->setCheckState(Qt::Checked);
    ui->electric->setCheckState(Qt::Checked);
    ui->fairy->setCheckState(Qt::Checked);
    ui->fighting->setCheckState(Qt::Checked);
    ui->fire->setCheckState(Qt::Checked);
    ui->flying->setCheckState(Qt::Checked);
    ui->ghost->setCheckState(Qt::Checked);
    ui->grass->setCheckState(Qt::Checked);
    ui->ground->setCheckState(Qt::Checked);
    ui->ice->setCheckState(Qt::Checked);
    ui->poison->setCheckState(Qt::Checked);
    ui->psychic->setCheckState(Qt::Checked);
    ui->rock->setCheckState(Qt::Checked);
    ui->steel->setCheckState(Qt::Checked);
    ui->water->setCheckState(Qt::Checked);
}

void MainWindow::on_resetType_clicked()
{
    // Se il bottone di reset filtri è premuto resetto le checkbox
    reset();
}

void MainWindow::on_confrontaPk_clicked()
{
    // Apro una nuova finestra (di confronto)
    Confronta *c = new Confronta();
    c->show();
    // Condivido la mainWindow, importante per poi riattivare il bottone
    QObject::connect(this, SIGNAL(shareMain(MainWindow*)), c, SLOT(getMainWindow(MainWindow*)));
    emit this->shareMain(this);
    // Disabilito il bottone per impedire di aprire un'altra finestra
    ui->confrontaPk->setDisabled(true);
}

void MainWindow::enableCompare()
{
    // Slot chiamato dal signal in Confronta, per riabilitare il bottone
    // di confronto, una volta chiusa la sua finestra
    ui->confrontaPk->setDisabled(false);
}

void MainWindow::on_resetSort_clicked()
{
    // Bottone per riordinare la tabella per numero di pokemon
    // ovvero la colonna nascosta in precedenza
    ui->tableView->model()->sort(0, Qt::AscendingOrder);
}

void MainWindow::on_close_clicked()
{
    // Esco dal programma
    qApp->exit();
}

void MainWindow::on_normal_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Normal", state);
}


void MainWindow::on_bug_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Bug", state);
}

void MainWindow::on_dark_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Dark", state);
}


void MainWindow::on_dragon_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Dragon", state);
}


void MainWindow::on_electric_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Electric", state);
}


void MainWindow::on_fairy_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Fairy", state);
}


void MainWindow::on_fighting_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Fighting", state);
}


void MainWindow::on_fire_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Fire", state);
}


void MainWindow::on_flying_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Flying", state);
}


void MainWindow::on_ghost_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Ghost", state);
}


void MainWindow::on_grass_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Grass", state);
}


void MainWindow::on_ground_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Ground", state);
}


void MainWindow::on_ice_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Ice", state);
}


void MainWindow::on_poison_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Poison", state);
}


void MainWindow::on_psychic_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Psychic", state);
}


void MainWindow::on_rock_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Rock", state);
}


void MainWindow::on_steel_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Steel", state);
}


void MainWindow::on_water_stateChanged(int state)
{
    // Se avviene un interazione con la checkbox
    filtra("Water", state);
}




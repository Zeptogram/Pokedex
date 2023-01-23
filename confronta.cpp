#include "confronta.h"
#include "ui_confronta.h"

Confronta::Confronta(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Confronta)
{
    ui->setupUi(this);
    // Dato che il distruttore viene chiamato solo quando chiudo tutte le finestre, dealloco al close di questa window
    setAttribute(Qt::WA_DeleteOnClose);
    // Richiamo la funzione per inizializzare le combobox
    fillCombobox();
    // Inizializzo il grafico PolarChart
    initGraph();
}

Confronta::~Confronta()
{
    delete ui;
}


void Confronta::fillCombobox()
{
    // Leggo dal csv
    QFile csv("pokedex.csv");
    if(!csv.open(QIODevice::ReadOnly))
        return;
    // Apro stream
    QTextStream stream(&csv);
    // Salto gli header
    stream.readLine();
    QStringList nomi;

    while(!stream.atEnd()){
        // Leggo una riga e la divido per ,
        QString line = stream.readLine();
        QStringList dati = line.split(",");
        // Dato che ho bisogno solo dei nomi, non ho problemi con lo split con la ,
        nomi << dati.at(2);
    }
    // Chiudo il file
    csv.flush();
    csv.close();
    // Aggiungo i dati alle combobox
    ui->listaPk1->addItems(nomi);
    ui->listaPk2->addItems(nomi);
    // Inizializzo i valori iniziali delle combobox (per non far selezionare lo stesso pokemon)
    ui->listaPk1->setCurrentIndex(0);
    ui->listaPk2->setCurrentIndex(1);
    // Disattivo il pokemon in index 0 (che è selezionato nella prima combobox) per la seconda combobox e viceversa
    ui->listaPk1->setItemData(1, false, Qt::UserRole -1);
    ui->listaPk2->setItemData(0, false, Qt::UserRole -1);
    // Imposto gli indici bloccati
    itemLockedInCombobox1 = 1;
    itemLockedInCombobox2 = 0;
}

void Confronta::setImage(QString img, bool first) {

    // Creo una Pixmap
    QPixmap pix(img);
    // first indica se prendere la label del primo o del secondo pokemon
    if(first){
        // Imposto le dimensioni (size) della immagine e la inserisco nella label
        ui->imgPk1->setPixmap(pix);
        ui->imgPk1->setScaledContents( true );
        // Per mantenere le dimensioni all'interno delle immagini
        ui->imgPk1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    } else{
        ui->imgPk2->setPixmap(pix);
        ui->imgPk2->setScaledContents( true );
        ui->imgPk2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    }
}

QString Confronta::getPokemonData(QString nome)
{
    // Apro il file
    QFile csv("pokedex.csv");
    if(!csv.open(QIODevice::ReadOnly))
        return "";
    // Questa volta cerco per "nome" in ogni riga letta
    // il nome del pokemon che mi serve e ritorno la linea da parsare
    QTextStream stream(&csv);
    stream.readLine();
    while(!stream.atEnd()){
        QString line = stream.readLine();
        if(line.contains(nome))
            // Ritorno il pokemon da parsare
            return line;
    }
    csv.flush();
    csv.close();
    // Se non esiste
    return "";
}

QStringList Confronta::parsePokemon(QString pokemon)
{
    // Se non ho tipo multiplo (ovvero nessuna ")
    // separo per ,
    QStringList dati;
    if(pokemon.indexOf('"') == -1) {
        dati = pokemon.split(",");
    }
    // Altrimenti separo "a pezzi"
    else {
        QStringList valoriDaSplittare = pokemon.split('"');
        QStringList prima = valoriDaSplittare[0].split(",");
        QStringList tipiList = valoriDaSplittare[1].split(",");
        QString tipi = tipiList.join(", ");
        QStringList dopo = valoriDaSplittare[2].split(",");
        // Aggiungo ai dati i "pezzi"
        for(int i = 0; i < prima.size(); i++)
            if(!(prima[i].isEmpty()))
            dati.append(prima[i]);
        // Tipi
        dati.append(tipi);
        for(int i = 0; i < dopo.size(); i++)
            if(!(dopo[i].isEmpty()))
            dati.append(dopo[i]);
    }
    // Ritorno i dati parsati (messi in una lista separati) del pokemon
    return dati;
}

void Confronta::on_listaPk1_currentIndexChanged(int index)
{
    // Prendo il nome del pokemon dalla combobox
    QString nome = ui->listaPk1->itemText(index);
    // Lo "parso", ovvero ottengo la QStringList con i dati
    QStringList pokemon = parsePokemon(getPokemonData(nome));
    // Imposto l'immagine del pokemon (true = prima immagine cioè primo pokemon)
    setImage(pokemon.at(0), true);
    // Blocco l'opzione del pokemon di questa combobox nell'altra tramite l'index
    ui->listaPk2->setItemData(index, false, Qt::UserRole -1);
    // Sblocco l'opzione precedentemente bloccata
    ui->listaPk2->setItemData(itemLockedInCombobox2, 33, Qt::UserRole -1);
    // Aggiorno l'indice bloccato per sbloccarlo al prossimo cambiamento
    itemLockedInCombobox2 = index;
    // Inserisco il tipo del pokemon nella label
    ui->tipoPk1->setText(pokemon.at(3));
    // Prendo l'indice del pokemon corrente che mi è necessario per l'update del grafico
    int j = ui->listaPk2->currentIndex();
    // Aggiorno il grafico con gli indici dei due pokemon
    updateGraph(index, j);
}


void Confronta::on_listaPk2_currentIndexChanged(int index)
{
    // Prendo il nome del pokemon dalla combobox
    QString nome = ui->listaPk2->itemText(index);
    // Lo "parso", ovvero ottengo la QStringList con i dati
    QStringList pokemon = parsePokemon(getPokemonData(nome));
    // Imposto l'immagine del pokemon (false = seconda immagine cioè secondo pokemon)
    setImage(pokemon.at(0), false);
    // Blocco l'opzione del pokemon di questa combobox nell'altra tramite l'index
    ui->listaPk1->setItemData(index, false, Qt::UserRole -1);
    // Sblocco l'opzione precedentemente bloccata
    ui->listaPk1->setItemData(itemLockedInCombobox1, 33, Qt::UserRole -1);
    // Aggiorno l'indice bloccato per sbloccarlo al prossimo cambiamento
    itemLockedInCombobox1 = index;
    // Inserisco il tipo del pokemon nella label
    ui->tipoPk2->setText(pokemon.at(3));
    // Prendo l'indice del pokemon corrente che mi è necessario per l'update del grafico
    int j = ui->listaPk1->currentIndex();
    // Aggiorno il grafico con gli indici dei due pokemon
    updateGraph(j, index);
}


void Confronta::initGraph()
{
    /* Questa funzione si occupa di creare un grafico PolarChart
     * ma vuoto, in quanto i dati effettivi verranno inseriti
     * attraverso la updateGraph(). Gli unici dati inseriti
     * sono le label sugli assi e alcune proprietà necessarie
     * per il grafico.
    */
    // Instanzio la chartView e il grafico
    chartView = new QChartView();
    chart = new QPolarChart();
    // Imposto l'angularAxis con le rispettive label
    QCategoryAxis *angularAxis = new QCategoryAxis;
    angularAxis->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);
    angularAxis->setRange(0, 360);
    angularAxis->append("Total", 0);
    angularAxis->append("Speed", 51);
    angularAxis->append("Sp.Def", 102);
    angularAxis->append("Sp.Atk", 153);
    angularAxis->append("Defense", 204);
    angularAxis->append("Attack", 255);
    angularAxis->append("HP", 306);
    // Aggiungo le serie che al momento sono vuote e l'angularAxis
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->addAxis(angularAxis, QPolarChart::PolarOrientationAngular);
    // Imposto delle proprietà per il radialAxis
    radialAxis->setTickCount(9);
    radialAxis->setLabelFormat("%d");
    chart->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
    // Connetto alle serie le assi
    series1->attachAxis(radialAxis);
    series1->attachAxis(angularAxis);
    series2->attachAxis(radialAxis);
    series2->attachAxis(angularAxis);
    // Aggiungo il grafico alla view
    chartView->setChart(chart);
    // Aggiungo la view al layout
    ui->layoutGraph->addWidget(chartView);
    chartView->setRenderHint(QPainter::Antialiasing);
    // Impostazioni per la size
    chartView->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
    // Mostro il grafico
    chartView->show();

}

void Confronta::updateGraph(int i, int j)
{
    // Pulisco le serie (dato che devo aggiornare il grafico)
    series1->clear();
    series2->clear();
    // Prendo il nome del pokemon tramite l'index
    QString nome_1 = ui->listaPk1->itemText(i);
    // Ottengo il resto dei dati
    QStringList pokemon1 = parsePokemon(getPokemonData(nome_1));
    // Faccio lo stesso per il secondo pokemon
    QString nome_2 = ui->listaPk2->itemText(j);
    QStringList pokemon2 = parsePokemon(getPokemonData(nome_2));
    // Imposto come range del grafico il valore più alto tra i due pokemon
    // cosi il grafico può scalare correttamente
    if(pokemon1.at(4).toInt() >= pokemon2.at(4).toInt())
        radialAxis->setRange(0, pokemon1.at(4).toInt());
    else
        radialAxis->setRange(0, pokemon2.at(4).toInt());
    // Prendo dal pokemon ogni dato necessario e lo aggiungo alla serie tramite QPointF agli angoli corretti.
    // Per replicare un grafico "a radar/spider" ho diviso la circonferenza in parti uguali per ogni dato
    *series1 << QPointF(0, pokemon1.at(4).toInt()) << QPointF(51, pokemon1.at(10).toInt()) << QPointF(102, pokemon1.at(9).toInt()) << QPointF(153, pokemon1.at(8).toInt()) << QPointF(204, pokemon1.at(7).toInt()) << QPointF(255, pokemon1.at(6).toInt()) << QPointF(306, pokemon1.at(5).toInt()) << QPointF(360, pokemon1.at(4).toInt());
    series1->setName(pokemon1.at(2));
    *series2 << QPointF(0, pokemon2.at(4).toInt()) << QPointF(51, pokemon2.at(10).toInt()) << QPointF(102, pokemon2.at(9).toInt()) << QPointF(153, pokemon2.at(8).toInt()) << QPointF(204, pokemon2.at(7).toInt()) << QPointF(255, pokemon2.at(6).toInt()) << QPointF(306, pokemon2.at(5).toInt()) << QPointF(360, pokemon2.at(4).toInt());
    series2->setName(pokemon2.at(2));

}


void Confronta::closeEvent(QCloseEvent *event)
{
    if(event){
        // Signal e Slot per riattivare il bottone per l'apertura della finestra di confronto
        QObject::connect(this, SIGNAL(windowClose()), main, SLOT(enableCompare()));
        // Emetto il segnale
        emit this->windowClose();
    }
}

void Confronta::getMainWindow(MainWindow *main)
{
    // Ricevuto dalla mainWindow, serve per il connect
    // in closeEvent();
    this->main = main;
}


void Confronta::on_ordina_clicked()
{
    // Resetto gli slot bloccati
    ui->listaPk1->setItemData(itemLockedInCombobox1, 33, Qt::UserRole -1);
    ui->listaPk2->setItemData(itemLockedInCombobox2, 33, Qt::UserRole -1);
    // Ordino in modo alfabetico
    ui->listaPk1->model()->sort(0);
    ui->listaPk2->model()->sort(0);
    // Resetto gli indici
    ui->listaPk1->setCurrentIndex(0);
    ui->listaPk2->setCurrentIndex(1);
    // Disattivo il pokemon in index 0 (che è selezionato nella prima combobox) per la seconda combobox e viceversa
    ui->listaPk1->setItemData(1, false, Qt::UserRole -1);
    ui->listaPk2->setItemData(0, false, Qt::UserRole -1);
    // Imposto gli indici bloccati
    itemLockedInCombobox1 = 1;
    itemLockedInCombobox2 = 0;
}


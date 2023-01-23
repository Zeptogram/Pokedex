# Pokedex
A simple pokedex viewer, with types filtering and comparation between two pokemons.

Made by Elio Gargiulo for UNIMIB C++ Course. Grade 5/5

# Introduzione
Il Progetto Qt Pokedex tratta la realizzazione e progettazione di un’interfaccia grafica per la
visualizzazione di un pokedex, i cui dati sono in un file “pokedex.csv” e una cartella “images”.
Nello specifico è richiesto:
- Una Finestra Principale dove deve essere possibile visualizzare l’elenco di tutti
pokemon e le varie caratteristiche di quest’ultimi attraverso una tabella. Deve essere
possibile, inoltre, poter filtrare ogni pokemon per “tipo” e ordinare l’elenco in base a
una delle colonne della tabella.
- Una Finestra di confronto dove vi è la possibilità di scegliere due pokemon da
confrontare (attraverso una combobox per esempio), visualizzare l’immagine dei due
pokemon selezionati e visualizzare un grafico mostrante le differenti statistiche dei due
pokemon. Il tipo di grafico è a scelta dello studente.

# Struttura del Progetto

La struttura generalizzata del progetto è la seguente:
- MainWindow (.cpp, .h e .ui) che è la finestra principale
- Confronta (.cpp, .h e .ui) che è la finestra per il confronto tra pokemon.
- pokedex.csv (file csv con i dati)
- images (cartella con le immagini dei pokemon)
- ulteriori file del progetto Qt

# Informazioni sullo Sviluppo

E’ stato utilizzato per sviluppare il progetto Qt Creator 9.0.1 con versione di Qt 6.4.1. Se viene
utilizzata una versione inferiore a Qt 6, la parte riguardante QtCharts necessita una modifica
per il suo corretto funzionamento come segue: https://doc.qt.io/qt-6/qtcharts-changes-qt6.html, 
ovvero l’inclusione del namespace di QtCharts. Esso è commentato nel file header
“confronta.h”. Il progetto è stato testato in modalità debug e release con la spunta su shadow
build nelle proprietà rimossa (per accesso più semplice al file.csv) in un ambiente Windows 11
e Ubuntu Linux.

# Scelte implementative

Si è cercato di mantenere la struttura delle finestre mostrate nella traccia dell’esame.

## Finestra Principale - MainWindow:

Per la visualizzazione della tabella è stato utilizzato un QTableView (con model per
l’inserimento di items e proxy per la gestione di filtri), riempita con i dati elaborati dal file csv.

L’approccio utilizzato per l’elaborazione dei dati da file è stata quella di dividere il file in un
insieme di stringhe (QStringList) tramite un determinato carattere, nel nostro caso
principalmente la virgola, attraverso la funzione “split”. E’ stato gestito inoltre il caso di tipo
multiplo (che nel file sono racchiusi in delle virgolette “”) attraverso molteplici “split” dei dati.

I filtri sono stati implementati attraverso checkbox, le quali se nello stato “checked”
mostreranno nella tabella il tipo selezionato e, in tutti gli altri casi ad eccezione di tipi che
sono multipli (Es. Grass, Poison i quali necessitano per non essere mostrati l’esclusione di
entrambi), non mostrennao nulla. Il filtro in se è gestito con un QSortFilterProxyModel, che
applicato al model della tabella, filtra una colonna selezionata per indice. L’implementazione
utilizza una regex e un insieme di stringhe coincidenti con i tipi del pokemon. Se una checkbox
è selezionata il filtro verrà aggiornato, inserendo nell’elenco dei filtri (i tipi visualizzabili) il tipo
selezionato. La regex è presente per garantire filtri sovrapposti (mette in OR i vari tipi). Se una
checkbox viene deselezionata avverrà l’opposto, ovvero la rimozione del filtro.

L’ordinamento per colonne della tabella è implementato principalmente dalla QTableView, vi
è solo la necessità di specificare il tipo di dato all’inserimento nella tabella (altrimenti anche
per i numeri verrà effettuato un ordinamento in ordine alfabetico).
Per rendere l’applicazione più accessibile, sono stati inseriti dei bottoni per permettere il
reset dei filtri e dell’ordinamento della tabella, oltre ad un bottone per uscire dal programma e
un bottone per passare alla finestra di confronto dei pokemon.

## Finestra di confronto - Confronta:

Sono state utilizzate due QCombobox per gestire la selezione dei due pokemon da confrontare
e due QLabel per mostrare le immagini corrette. I dati vengono estratti nello stesso modo
utilizzato nella MainWindow e utilizzati per riempire le combobox (solo il nome del pokemon)
e impostare il path corretto per l’immagine. Per impedire la selezione del medesimo pokemon
in entrambe le combobox (non posso confrontare due pokemon uguali), sono stati utilizzati due
indici di appoggio “itemLockedInCombobox1” e “itemLockedInCombobox2”. Questi indici
mantengono in memoria ogni indice bloccato della corrispettiva combobox e servono a
riattivare l’opzione del pokemon corretto una volta che è stato cambiato pokemon in una delle
due combobox. In sostanza viene disattivato l’indice ogni cambiamento di pokemon nella
combobox opposta e riattivato quello precedentemente bloccato.

Il grafico utilizzato è un QPolarChart (della libreria QtCharts), dove ogni dato viene inserito
come QPointF a un angolo specifico. Si è cercato di replicare il grafico illustrato nella traccia del
progetto dividendo la circonferenza in parti uguali (quanti sono i dati del pokemon). Il grafico
viene prima creato vuoto con la funzione “initGraph()”, che imposta solo le assi e le label
corrette, mentre ogni cambiamento di stato della combobox, viene aggiornato con i dati corretti
del pokemon selezionato attraverso “updateGraph(indice pokemon1 , indice pokemon2)”.

E’ stato aggiunto infine un bottone per ordinare il contenuto delle combobox in ordine
alfabetico se l’utente ne ha la necessità.

Infine è stata impostato l’attributo setAttribute(Qt::WA_DeleteOnClose) per cancellare dalla
memoria la finestra di confronto al momento della chiusura. Senza questo attributo, la finestra
verrebbe deallocata solamente quando l’intera applicazione è terminata, continuando ad
allocare nuove finestre di confronto per ogni premuta di bottone.

Sono stati utilizzati due Signal e Slot custom per gestire la comunicazione tra la MainWindow e
Confronta, nello specifico per notificare quando abilitare e disattivare il bottone che apre una
nuova finestra di confronto.

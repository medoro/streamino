# streamino
Stream deck made on Arduino

Si tratta di un semplicissimo stream deck (serie di pulsanti) basato su Arduino Leonardo, utilizzato in combo con OBS Studio per gestire lo streaaming twitch.

La parte hardware è semplicissima, Arduino Leonardo con 10 pulsanti collegati ai pin di I/O digitale con GND comune.

Il codice è altrettanto semplice, i primi 6 pulsanti inviano una singola combinazione di tasti, i seguenti tre ne inviano 2 diverse, in base alla pressione del decimo che funziona da "shift".

Per installarlo vi serve l'Arduino SDK e naturalmente un Arduino leonardo e i pulsanti, semplici switch momentanei.


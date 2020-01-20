# streamino
**Stream deck made on Arduino**

Si tratta di un semplicissimo stream deck (serie di pulsanti) basato su Arduino Leonardo, utilizzato in combo con OBS Studio per gestire lo streaaming twitch.

La parte hardware è semplicissima, Arduino Leonardo con 10 pulsanti, semplici switch momentanei, collegati ai pin di I/O digitale con GND comune.

Il codice: i primi 6 pulsanti inviano una singola combinazione di tasti, i seguenti tre ne inviano 2 diverse, in base alla pressione del decimo che funziona da "shift".

**Combinazioni predefinite**

WIN = Tasto Windows

- CTRL SHIFT ALT F2
- CTRL ALT ì
- WIN  F5
- WIN  F6
- WIN  F7
- WIN  F8
- WIN  F9 / WIN F3 (shifted*)
- CTRL ì  / WIN F4 (shifted*)
- ALT  ì / CTRL SHIFT F3 (shifted*)
- * "Shift" (per attivare la seconda funzione)


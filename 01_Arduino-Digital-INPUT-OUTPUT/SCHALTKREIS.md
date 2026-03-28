# 01 Arduino Digital-INPUT Digital-OUTPUT

https://www.tinkercad.com/things/60Yg9d7MrHI-13-digitale-ein-und-ausgange-v2?sharecode=rBUqCGvLrdEHtEnnd1YBJZpFf7YDXGBkBnSlFhMNdeQ


### Eingang `D9` als Pull-Down-Schaltung

| Arduino-Pin | Verbindung |
| --- | --- |
| `5V` | an eine Seite des Tasters |
| `D9` | über `10 kOhm` nach `GND` |
| `GND` | an den Widerstand |

## ASCII-Schaltbild

```text
5V
 |
[Taster]
 |
 +---- D9
 |
[R: 10k]
 |
GND

```

## Funktionsweise

- Wenn der Taster nicht gedrückt ist, zieht der `10 kOhm` Widerstand den Pin `D9` auf `LOW`.
- Wenn der Taster gedrückt ist, liegt `5V` an `D9` an, also `HIGH`.
- Der Sketch gibt den Zustand von `D9` jede Sekunde im seriellen Monitor aus.

### Eingang `D7` als Pull-Up-Schaltung

Beschriebene Verdrahtung:

- `5V -> 4,7 kOhm Widerstand -> Abzweig zu D7 -> Taster -> GND`

## ASCII-Schaltbild Pull-Up

```text
5V
 |
[R: 4,7k]
 |
 +---- D7
 |
[Taster]
 |
GND
```

## Funktionsweise Pull-Up

- Wenn der Taster nicht gedrückt ist, zieht der `4,7 kOhm` Widerstand den Pin `D7` auf `HIGH`.
- Wenn der Taster gedrückt ist, wird `D7` nach `GND` gezogen, also `LOW`.



# Dateien analysieren
* `ana` erstellt Statistiken der Verteilungen von Byte-Folgen in
  Dateien
* die erste Version des Programms analysiert nur Byte-Folgen der Länge
  eins
* also die die Häufigkeiten der einzelnen Bytes
* das Programm wird später für beliebige Byte-Folgen fester Länge
  erweitert

```
@Def(file: ana.cpp)
	@put(main prereqs);
	int main(
		int argc, const char *argv[]
	) {
		@Put(parse args);
		@put(read input);
		@put(write table);
	}
@End(file: ana.cpp)
```
* die Funktion `@f(main)` wertet Argumente der Kommandozeile aus
* dann liest `@f(main)` die Standard-Eingabe komplett und wertet sie aus
* zum Schluss schreibt `@f(main)` die resultierende Statistik in die
  Standard-Ausgabe

## Datenstruktur für Statistik
* für jedes gelesene Byte wird gezählt, wie häufig der Byte-Wert in der
  gelesenen Eingabe vorkommt

```
@Def(def collection)
	using Collection =
		std::map<char, int>;
@End(def collection)
```
* für jedes Byte wird ein eigener Zähler benutzt
* später wird die `Collection` umdefinieren
* daher ist die Definition in einem eigenen globalen Fragment gekapselt

```
@def(main prereqs)
	#include <map>
	@Put(def collection);
	Collection collection;
@end(main prereqs)
```
* es gibt eine globale Variable, welche die Häufigkeiten enthält

```
@add(main prereqs)
	#include <iostream>
@end(main prereqs)
```
* benötigt Standard Ein- und Ausgabe

```
@def(read input)
	@Put(init state);
	char ch;
	while (std::cin.get(ch)) {
		@Put(add to collection);
	}
@end(read input)
```
* jedes gelesene Zeichen wird in die Statistik integriert
* später benötigt das Programm einen Ort, um den aktuellen Schlüssel zu
  initialisieren
* das passende Fragment wird schon vorab definiert
* aber nicht gefüllt

```
@Def(add to collection)
	++collection[ch];
@End(add to collection)
```
* fügt Zeichen in die Statistik ein
* eigenes globales Fragment, um es später zu ersetzen


```
@def(write table)
	for (const auto &e : collection) {
		@Put(write key);
		std::cout << "\t" <<
			e.second << "\n";
	}
@end(write table)
```
* jeder Eintrag der Statistik wird ausgegeben

```
@add(main prereqs)
	#include <cctype>
	void write_byte(char b) {
		if (isprint(b) &&
			b != '%' && b > ' '
		) {
			std::cout << b;
		} else {
			@put(write escaped);
		}
	}
@end(main prereqs)
```
* druckbare Zeichen werden direkt ausgegeben
* andere Bytes werden escaped
* so können Unix-Tools die Datei in Spalten aufteilen

```
@def(write escaped)
	static const char digits[] =
		"0123456789abcdef";
	std::cout << '%' <<
		digits[(b >> 4) & 0xf] <<
		digits[b & 0xf];
@end(write escaped)
```
* andere Bytes werden mit dem Präfix `%` als zwei hexadezimale Ziffern
  ausgegeben
* auch das Zeichen `%` muss so kodiert werden

```
@Def(write key)
	write_byte(e.first);
@End(write key)
```
* gibt den Schlüssel aus
* eigenes Fragment, da sich der Typ des Schlüssels später ändert


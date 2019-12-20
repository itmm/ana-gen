# Dateien analysieren
* `ana` erstellt Statistiken der Verteilungen von Byte-Folgen in
  Dateien

```
@Def(file: ana.cpp)
	@put(main prereqs);
	int main(
		int argc, const char *argv[]
	) {
		@Put(parse args);
		char ch;
		@put(read input);
		@put(write table);
	}
@End(file: ana.cpp)
```
* die Funktion `@f(main)` wertet Argumente der Kommandozeile aus
* dann liest `@f(main)` die Standard-Eingabe komplett und wertet sie aus
* zum Schluss schreibt `@f(main)` die resultierende Statistik in die
  Standard-Eingabe

### Einfache Statistik
* zuerst zählt `ana` nur Häufigkeiten von Bytes
* mit späteren Änderungen zählt es Byte-Folgen einer festen Länge
* aber zum Anfang werden nur einzelne Bytes berücksichtigt

```
@def(main prereqs)
	#include <iostream>
@end(main prereqs)
```
* benötigt Standard Ein- und Ausgabe

```
@Def(def collection)
	using Collection =
		std::map<char, int>;
@End(def collection)
```
* für jedes Byte wird ein eigener Zähler benutzt
* eigenes Fragment, da es später überschrieben wird

```
@add(main prereqs)
	#include <map>
	@Put(def collection);
	Collection collection;
@end(main prereqs)
```
* es gibt eine globale Variable mit den Häufigkeiten

```
@def(read input)
	@Put(init key);
	while (std::cin.get(ch)) {
		@Put(add to collection);
	}
@end(read input)
```
* jedes gelesene Zeichen wird in die Statistik integriert

```
@Def(add to collection)
	++collection[ch];
@End(add to collection)
```
* fügt Zeichen in die Statistik ein
* eigenes Fragment, um es später zu ersetzen


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
			static const char digits[] =
				"0123456789abcdef";
			std::cout << '%' <<
				digits[(b >> 4) & 0xf] <<
				digits[b & 0xf];
		}
	}
@end(main prereqs)
```
* druckbare Zeichen werden direkt ausgegeben
* andere Bytes werden mit dem Präfix `\x` als zwei hexadezimale Ziffern
  ausgegeben

```
@Def(write key)
	write_byte(e.first);
@End(write key)
```
* gibt den Schlüssel aus
* eigenes Fragment, da sich der Typ des Schlüssels später ändert


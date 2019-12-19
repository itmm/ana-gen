# Dateien analysieren
* `ana` erstellt Statistiken der Verteilungen von Byte-Folgen in
  Dateien

```
@Def(file: ana.cpp)
	@put(ana main prereqs);
	int main(
		int argc, const char *argv[]
	) {
		@put(parse args);
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
@def(ana main prereqs)
	#include <iostream>
@end(ana main prereqs)
```
* benötigt Standard Ein- und Ausgabe

```
@def(def collection)
	using Collection =
		std::map<char, int>;
@end(def collection)
```
* für jedes Byte wird ein eigener Zähler benutzt
* eigenes Fragment, da es später überschrieben wird

```
@add(ana main prereqs)
	#include <map>
	@put(def collection);
	Collection collection;
@end(ana main prereqs)
```
* es gibt eine globale Variable mit den Häufigkeiten

```
@def(read input)
	@put(init key);
	while (std::cin.get(ch)) {
		@put(add to collection);
	}
@end(read input)
```
* jedes gelesene Zeichen wird in die Statistik integriert

```
@def(add to collection)
	++collection[ch];
@end(add to collection)
```
* fügt Zeichen in die Statistik ein
* eigenes Fragment, um es später zu ersetzen


```
@def(write table)
	for (const auto &e : collection) {
		@put(write key);
		std::cout << "\t" <<
			e.second << "\n";
	}
@end(write table)
```
* jeder Eintrag der Statistik wird ausgegeben

```
@add(ana main prereqs)
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
@end(ana main prereqs)
```
* druckbare Zeichen werden direkt ausgegeben
* andere Bytes werden mit dem Präfix `\x` als zwei hexadezimale Ziffern
  ausgegeben

```
@def(write key)
	write_byte(e.first);
@end(write key)
```
* gibt den Schlüssel aus
* eigenes Fragment, da sich der Typ des Schlüssels später ändert

### Byte-Folgen analysieren
* passt das Programm an, um ganze Byte-Folgen fester Länge zu analysieren
* anstatt nur einzelner Bytes

```
@rep(write key)
@end(write key)
```
* löscht das Fragment, da es sonst Zwischenstände gibt, die nicht
  kompilieren
* nach der Typ-Änderung werden die Fragmente neu gefüllt

```
@rep(add to collection)
@end(add to collection)
```
* löscht das Fragment, da es sonst Zwischenstände gibt, die nicht
  kompilieren
* nach der Typ-Änderung werden die Fragmente neu gefüllt

```
@inc(key.md)
```

```
@rep(def collection)
	@Mul(key);
	using Collection =
		std::map<Key, int>;
@end(def collection)
```
* Collection zählt nun `Key` Instanzen

```
@def(init key)
	init(key);
@end(init key)
```

```
@rep(add to collection)
	push(key, ch);
	++collection[key];
@end(add to collection)
```
* passt Schlüssel an
* und zählt neuen Schlüssel 

```
@rep(write key)
	for (
		unsigned i = 0; i < key_length; ++i
	) {
		write_byte(e.first[i]);
	}
@end(write key)
```
* gibt alle Bytes des Schlüssels aus

### Andere Längen der Byte-Folgen
* als Vorgabe werden Byte-Folgen der Länge 2 betrachtet
* um andere Längen zu verwenden, kann die neue Länge mit der Option
  `-n` auf der Kommandozeile angegeben werden
* so betrachtet zum Beispiel `-n3` Byte-Folgen der Länge 3

```
@def(parse args)
	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			@put(change length);
		}
	}
@end(parse args)
```
* bearbeite Option `-n`

```
@def(change length)
	key_length = std::stoi(arg + 2);
	if (key_length < 1) {
		std::cerr << "wrong length\n";
		key_length = 2;
	}
@end(change length)
```
* setze neue Länge
* `key` wird neu instantiiert
* wenn die Länge zu kurz ist, wird statt dessen 2 verwendet

## Dokumente generieren
* erzeugt Dokumente mit vorgegebener Sequenz-Häufigkeit
* liest die Häufigkeitsverteilung über Standard-Eingabe

```
@Def(file: gen.cpp)
	@put(main prereqs);
	int main() {
		@put(read receipt);
		@put(loop);
	}
@End(file: gen.cpp)
```
* `@f(main)` Funktion liest Häufigkeit
* und generiert passende Zeichen

## Zufällige Zeichen generieren
* generiert zufällige Zeichen

```
@def(main prereqs)
	@put(next prereqs);
	inline bool next(char &ch) {
		bool ok { false };
		@put(next);
		return ok;
	}
@end(main prereqs)
```
* `@f(next)` generiert das nächste Zeichen
* Funktion liefert `false`, wenn kein Zeichen generiert werden konnte

```
@add(main prereqs)
	#include <iostream>
@end(main prereqs)
```
* benötigt `std::cin`, `std::cout`, etc.

```
@def(loop)
	@mul(initialise);
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			@mul(initialise);
		}
	}
@end(loop)
```
* initialisiere den Zustand
* und gib die generierten Zeichen aus
* wenn kein Zeichen generiert werden kann, initialisiere den Zustand neu

```
@inc(prefix.md)
```
* definiert Klasse für Byte-Arrays einheitlicher Länge
* die als Schlüssel von `std::map` verwendet werden

```
@def(collection prereqs)
	@Mul(prefix)
@end(collection prereqs)
```
* integriert die Definition von `Prefix` in das Programm
* wird ebenfalls im erweiterten Analysator verwendet

```
@add(collection prereqs)
	#include <map>
@end(collection prereqs)
```
* benötigt `std::map`

```
@def(list prereqs)
	struct Entry {
		const char ch;
		const int count;
		Entry (char c, int v):
			ch { c }, count { v }
		{ }
	};
@end(list prereqs)
```
* `Entry` zählt wie häufig ein Zeichen `ch` nach einem Präfix vorkommt

```
@add(collection prereqs)
	@put(list prereqs);
	#include <vector>
	class List {
		private:
			std::vector<Entry> _entries;
			int _sum { 0 };
		public:
			@put(list publics);
	};

@end(collection prereqs)
```
* Liste von `Entry`s
* zusätzlich wird die Gesamtsumme vorgehalten

```
@def(next prereqs)
	@put(collection prereqs);
	using Collection =
		std::map<Prefix, List>;
	Collection collection;
@end(next prereqs)
```
* der Generator verwendet eine Abbildung von Präfixen auf Listen

```
@def(list publics)
	void add(char ch, int count) {
		_entries.emplace_back(
			ch, count
		);
		_sum += count;
	}
@end(list publics)
```
* fügt ein neues Zeichen zur Liste hinzu
* und passt die Gesamtsumme an

```
@add(list publics)
	class No_Entries { };
	char next() const {
		if (_sum > 0) {
			@put(next ch);
		}
		throw No_Entries { };
	}
@end(list publics)
```
* liefert ein zufälliges Zeichen
* wenn keine Einträge hinterlegt sind, wird eine Exception generiert

```
@add(list prereqs)
	#include <random>
	std::mt19937 _rng {
		std::random_device{ }()
	};
@end(list prereqs)
```
* initialisiert einen Zufallsgenerator (Mystery-Twister)

```
@def(next ch)
	auto dist {
		std::uniform_int_distribution<
			std::mt19937::result_type
		>(
			0, _sum - 1
		) };
	int result = dist(_rng);
@end(next ch)
```
* ermittelt eine Zufallszahl zwischen `0` und `_sum - 1`

```
@add(next ch)
	for (const auto &i : _entries) {
		if (result < i.count) {
			return i.ch;
		}
		result -= i.count;
	}
@end(next ch)
```
* wählt Zeichen anhand der Zufallszahl

```
@add(next prereqs)
	Prefix state;
@end(next prereqs)
```
* der Zustand ist ein Präfix mit den letzten ausgegebenen Zeichen

```
@def(initialise)
	init(state);
@end(initialise)
```
* initialsiert den Zustand auf Null-Bytes

```
@def(next)
	try {
		ch = collection[state].next();
		push(state, ch);
		ok = true;
	} catch (const List::No_Entries &) {
		ok = false;
	}
@end(next)
```
* ermittelt das nächste zufällige Zeichen

## Rezept einlesen
* liest Häufigkeitsverteilung von Standard-Eingabe

```
@add(main prereqs)
	@put(normalize prereqs);
	std::string normalize(
		const std::string &key
	) {
		std::string result;
		unsigned i { 0 };
		for (; i < key.size(); ++i) {
			@put(normalize char);
		}
		return result;
	}
@end(main prereqs)
```
* wandelt Escape-Sequenzen in Schlüsseln in die passenden Bytes um

```
@def(normalize char)
	if (key[i] == '%') {
		@put(unescape);
		i += 2;
	} else {
		result += key[i];
	}
@end(normalize char)
```
* Escape-Sequenzen beginnen mit `%`
* alles andere wird direkt kopiert

```
@def(normalize prereqs)
	int hex_digit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return ch - '0';
		} else if (
			ch >= 'a' && ch <= 'f'
		) {
			return ch - 'a' + 10;
		}
		std::cerr << "invalid digit\n";
		return 0;
	}
@end(normalize prereqs)
```
* wandelt hexadezimale Ziffer in numerischen Wert um

```
@def(unescape)
	result += static_cast<char>(
		(hex_digit(key[i + 1]) << 4) +
			hex_digit(key[i + 2])
	);
@end(unescape)
```
* Escape-Sequenzen bestehen aus zwei hexadezimalen Ziffern

```
@def(read receipt)
	bool first { true };
	Prefix k;
	for (;;) {
		@put(read key);
		@put(read count);
		if (first) {
			@put(setup length);
			first = false;
		}
		@put(add entry);
	}
@end(read receipt)
```
* Rezepte bestehen aus einer Liste von Schlüssel/Anzahl Paaren
* der erste Schlüssel bestimmt wie lang die Präfixe sind

```
@def(read key)
	std::string key;
	std::cin >> key;
	if (! std::cin) { break; }
	key = normalize(key);
@end(read key)
```
* liest Schlüssel
* und expandiert Escape-Sequenzen

```
@def(read count)
	int count;
	std::cin >> count;
	if (! std::cin) { break; }
@end(read count)
```
* liest die Anzahl

```
@def(setup length)
	prefix_length = key.size() - 1;
	init(k);
@end(setup length)
```
* Länge ist eins weniger als die Schlüssel-Länge

```
@def(add entry)
	for (unsigned i { 0 };
		i + 1 < key.size(); ++i
	) {
		push(k, key[i]);
	}
	collection[k].add(
		key.back(), count
	);
@end(add entry)
```
* initialisiert `k` mit dem Schlüssel ohne dem letzten Byte
* fügt Anzahl für das letzte Byte in die Abbildung ein


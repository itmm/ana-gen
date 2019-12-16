# Dateien mit fester Verteilung erzeugen
* die Programme `ana` und `gen` können Dateien analysieren
* und neue Dateien erzeugen, welche die gleiche Verteilung der
  enthaltenen Bytes haben

## Dateien analysieren
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
@def(def collection prereqs)
	@mul(key class);
@end(def collection prereqs)
```

```
@def(key class)
	@put(key prereqs);
	#include <memory>
	class Key {
		private:
			std::unique_ptr<char> _key;
		public:
			@put(key publics);
	};
	@put(key impl);
@end(key class)
```
* die `Key` Klasse enthält die Byte-Folgen
* eine eigene Klasse wird verwendet, da sie kompakter als `std::vector`
  implementiert werden kann
* aber die Länge des Schlüssels nicht zum Zeitpunkt der Übersetzung
  bekannt ist

```
@def(key publics)
	static int length;
@end(key publics)
```
* verwendete Schlüssel-Länge ist eine statische Variable
* sauberer wäre es, sie in jede `Key`-Instanz abzulegen, aber das
  würde viel Speicher verbrauchen
* der Wert `length` wird nur geändert, bevor viele `Key`s instantiiert
  wurden
* diese müssen manuell korrigiert werden

```
@def(key impl)
	int Key::length { 2 };
@end(key impl)
```
* als Vorgabe betrachtet `app` Byte-Folgen der Länge 2

```
@def(key prereqs)
	#include <cstring>
@end(key prereqs)
```
* benötigt Speicher-Funktionen/Makros

```
@add(key publics)
	Key():
		_key { new char[length] }
	{
		memset(&*_key, 0, length);
	}
@end(key publics)
```
* Konstruktor legt Speicher an und initialisiert Bytes

```
@add(key publics)
	Key(const Key &other):
		_key { new char[length] }
	{
		memcpy(
			&*_key, &*other._key, length
		);
	}
@end(key publics)
```
* Copy-Konstruktor legt einen eigenen Speicherbereich an

```
@add(key publics)
	Key &operator=(const Key &other) {
		memcpy(
			&*_key, &*other._key, length
		);
		return *this;
	}
@end(key publics)
```
* Assignment kopiert nur die Speicherbereiche

```
@add(key publics)
	bool operator==(
		const Key &other
	) const {
		return memcmp(
			&*_key, &*other._key, length
		) == 0;
	}
@end(key publics)
```
* Gleichheit wird über die Speicherbereiche definiert

```
@add(key publics)
	bool operator<(
		const Key &other
	) const {
		return memcmp(
			&*_key, &*other._key, length
		) < 0;
	}
@end(key publics)
```
* Ordnung wird über die Speicherbereiche definiert

```
@rep(def collection)
	@put(def collection prereqs)
	using Collection =
		std::map<Key, int>;
	Key key;
@end(def collection)
```
* Collection zählt nun `Key` Instanzen

```
@add(key publics)
	void push(char ch) {
		memmove(
			&*_key, &*_key + 1,
			length - 1
		);
		(&*_key)[length - 1] = ch;
	}
@end(key publics)
```
* verschiebt die bestehenden Zeichen im Schlüssel
* und fügt das neue Byte am Ende ein

```
@rep(add to collection)
	key.push(ch);
	++collection[key];
@end(add to collection)
```
* passt Schlüssel an
* und zählt neuen Schlüssel 

```
@add(key publics)
	char operator[](int i) const {
		return (&*_key)[i];
	}
@end(key publics)
```
* liefert einzelnes Byte des Schlüssels

```
@rep(write key)
	for (
		int i = 0; i < Key::length; ++i
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
	Key::length = std::stoi(arg + 2);
	if (Key::length < 1) {
		std::cerr << "wrong length\n";
		Key::length = 2;
	}
	key.~Key();
	new (&key) Key { };
@end(change length)
```
* setze neue Länge
* `key` wird neu instantiiert
* wenn die Länge zu kurz ist, wird statt dessen 2 verwendet


## Dokumente generieren

```
@Def(file: gen.cpp)
	@put(gen main prereqs);
	int main() {
		@put(read receipt);
		@put(gen loop);
	}
@End(file: gen.cpp)
```

```
@def(gen main prereqs)
	@put(static next prereqs);
	@put(next prereqs);
	inline bool next(char &ch) {
		bool ok { false };
		@put(next);
		return ok;
	}
@end(gen main prereqs)
```

```
@add(gen main prereqs)
	#include <iostream>
@end(gen main prereqs)
```

```
@def(gen loop)
	@mul(initialise);
	for (;;) {
		char ch;
		if (next(ch)) {
			std::cout << ch;
		} else {
			@mul(initialise);
		}
	}
@end(gen loop)
```

```
@def(next)
	ch = 'x';
	ok = true;
@end(next)
```

```
@def(initialise)
@end(initialise)
```

```
@def(next prereqs)
	int prev_length { 3 };
	char *previous { nullptr };
@end(next prereqs)
```

```
@rep(initialise)
	if (! previous) {
		previous =
			new char[prev_length];
	}
	previous[0] = 'a';
	previous[1] = 'b';
	previous[2] = 'c';
@end(initialise)
```

```
@rep(next)
	ch = previous[0];
	previous[0] = previous[1];
	previous[1] = previous[2];
	previous[2] = ch;
	ok = true;
@end(next)
```

```
@add(gen main prereqs)
	int hex_digit(char ch) {
		if (ch >= '0' && ch <= '9') {
			return ch - '0';
		} else if (ch >= 'a' && ch <= 'f') {
			return ch - 'a' + 10;
		} else {
			std::cerr << "invalid digit\n";
			return 0;
		}
	}
	std::string normalize(const std::string &key) {
		std::string result;
		for (unsigned i { 0 }; i < key.size(); ++i) {
			if (key[i] == '%') {
				result += static_cast<char>(
					(hex_digit(key[i + 1]) << 4) + hex_digit(key[i + 2])
				);
				i += 2;
			} else {
				result += key[i];
			}
		}
		return result;
	}
@end(gen main prereqs)
```

```
@def(static next prereqs)
	#include <memory>
	#include <cassert>
	#include <random>
	class Entry {
		private:
			std::unique_ptr<Entry> _next;
			char _ch;
			int _count;
		public:
			Entry(char ch, int count): _ch { ch }, _count { count} { }
			char ch() const { return _ch; }
			int count() const { return _count; }
			bool last() const { return ! _next; }
			Entry &next() const { return *_next; }
			void add(std::unique_ptr<Entry> &&entry) {
				if (last()) {
					_next = std::move(entry);
				} else {
					_next->add(std::move(entry));
				}
			}
	};

	std::random_device _dev;
	std::mt19937 _rng { _dev() };

	class List {
		private:
			std::unique_ptr<Entry> _entries;
			int _sum { 0 };
		public:
			void add(char ch, int count) {
				auto entry { std::make_unique<Entry>(ch, count) };
				if (_entries) {
					_entries->add(std::move(entry));
				} else {
					_entries = std::move(entry);
				}
			}
			char next() {
				assert(_sum > 0);
				auto dist { std::uniform_int_distribution<std::mt19937::result_type>(0, _sum - 1) };
				int result = dist(_rng);
				for (Entry *e { &*_entries }; ! e->last(); e = &e->next()) {
					if (result < e->count()) {
						return e->ch();
					}
					result -= e->count();
				}
			}
	};

	@mul(key class);

	#include <map>
	using Collection = std::map<Key, List>;
	Collection collection;
@end(static next prereqs)
```

```
@def(read receipt)
	bool first { true };
	Key k;
	for (;;) {
		std::string key;
		std::cin >> key;
		if (! std::cin) { break; }
		int count;
		std::cin >> count;
		if (! std::cin) { break; }
		key = normalize(key);
		if (first) {
			Key::length = key.size() - 1;
			first = false;
			k.~Key();
			new (&k) Key { };
		}
		@put(add entry);
	}
@end(read receipt)
```

```
@def(add entry)
	assert((int) key.size() == Key::length + 1);
	for (unsigned i { 0 }; i + 1 < key.size(); ++i) {
		k.push(key[i]);
	}
	collection[k].add(key.back(), count);
@end(add entry)
```

```
@rep(next)
@end(next)
```

```
@rep(initialise)
@end(initialise)
```

```
@rep(next prereqs)
	Key prev;
@end(next prereqs)
```

```
@rep(initialise)
	prev = Key { };
@end(initialise)
```


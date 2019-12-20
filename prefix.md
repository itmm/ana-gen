# Pseudo-Dynamisches Array
* Klasse zur Verwaltung von Byte-Präfixen
* alle Instanzen haben die gleiche Länge
* diese wird aber erst zur Laufzeit bestimmt
* `Prefix`es sind Schlüssel von `std::map`

```
@Def(prefix)
	#include <string>
	using Prefix = std::string;
	unsigned prefix_length { 2 };
@End(prefix)
```
* einfache Implementierung verwendet `std::string` als `Prefix`
* Länge wird in einer globalen Variable gespeichert

```
@Add(prefix)
	void init(Prefix &p) {
		p = std::string { };
		for (unsigned i { 0 };
			i < prefix_length; ++i
		) {
			p += '\0';
		}
	}
@End(prefix)
```
* initialisiert `Prefix` auf eine feste Länge von Null-Bytes

```
@Add(prefix)
	void push(Prefix &p, char ch) {
		if (p.size() > 0) {
			for (unsigned i = 1;
				i < p.size(); ++i
			) {
				p[i - 1] = p[i];
			}
			p[p.size() - 1] = ch;
		}
	}
@End(prefix)
```
* verschiebt alle Bytes und fügt das neue Byte an


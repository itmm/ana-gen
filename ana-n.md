# Byte-Folgen analysieren
* passt das Programm an, um ganze Byte-Folgen fester Länge zu analysieren
* anstatt nur einzelner Bytes

```
@Rep(write key)
@End(write key)
```
* löscht das Fragment, da es sonst Zwischenstände gibt, die nicht
  kompilieren
* nach der Typ-Änderung werden die Fragmente neu gefüllt

```
@Rep(add to collection)
@End(add to collection)
```
* löscht das Fragment, da es sonst Zwischenstände gibt, die nicht
  kompilieren
* nach der Typ-Änderung werden die Fragmente neu gefüllt

```
@inc(key.md)
```

```
@Rep(def collection)
	@Mul(key);
	using Collection =
		std::map<Key, int>;
@End(def collection)
```
* Collection zählt nun `Key` Instanzen

```
@Def(init key)
	init(key);
@End(init key)
```

```
@Rep(add to collection)
	push(key, ch);
	++collection[key];
@End(add to collection)
```
* passt Schlüssel an
* und zählt neuen Schlüssel 

```
@Rep(write key)
	for (
		unsigned i = 0; i < key_length; ++i
	) {
		write_byte(e.first[i]);
	}
@End(write key)
```
* gibt alle Bytes des Schlüssels aus

### Andere Längen der Byte-Folgen
* als Vorgabe werden Byte-Folgen der Länge 2 betrachtet
* um andere Längen zu verwenden, kann die neue Länge mit der Option
  `-n` auf der Kommandozeile angegeben werden
* so betrachtet zum Beispiel `-n3` Byte-Folgen der Länge 3

```
@Def(parse args)
	if (argc == 2) {
		const char *arg { argv[1] };
		if (
			arg[0] == '-' &&
				arg[1] == 'n'
		) {
			@put(change length);
		}
	}
@End(parse args)
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

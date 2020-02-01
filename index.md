# Literate Programming
## von Büchern zu Präsentationen
* Einführung in Literate Programming
* Vorteile gegenüber getrennter Dokumentation
* Schwächen bei klassischem Ansatz
* Vorstellung einer Verbesserung

## Sicht des illiteraten Programmierers
### Source-Code ⊇ Dokumentation
* Source-Code und dessen Dokumentation hängen zusammen
* müssen zusammen gepflegt und versioniert werden
* aber Source-Code ist für die Ausführung am wichtigsten
* Source-Code ist selbsterklärend
* Beispiele: javadoc, doxygen

## Sicht von Literate Programming
### Source-Code ⊆ Dokumentation
* Dokumentation beschreibt, was ein Programm macht
* und wie das Programm etwas macht
* und warum das Programm etwas macht
* der Source-Code ist ein Teil dieser Dokumentation

## Illiterate Programme
* Beispiele für Programme, die nicht nach den Prinzipien des Literate
  Programming dokumentiert werden

## Open Source
### Linux
### Apache
### GCC
### LLVM
* viele Open Source Projekte sind auf den Code konzentriert

!(imgs/operating-systems.jpg)
* Tanenbaum beschreibt Minix-System in seinem Buch

!(imgs/project-oberon.jpg)
* Wirth beschreibt ein Betriebssystem mit Compiler in seinem Buch

!(imgs/software-tools.jpg)
* Kernighan beschreibt eine Sammlung von Kommandozeilen-Tools in Fortran

!(imgs/sargon.jpg)
* Sargon Chess ist in Z80-Assembler geschrieben

!(imgs/mazes.jpg)
* von Jamis Buck
* Labyrinthe bauen in Ruby

!(imgs/building-git.jpg)
* ein Buch, in dem `git` in Ruby nachgebaut wird

## Literate Programs
* Beispiele für Literate Programs

!(imgs/tex-book.jpg)
* erster Kontakt mit TeX

!(imgs/physically-based-rendering.jpg)
* Raytracer beschreibt Grundlagen des Raytracings neben deme Code

!(imgs/a-retargetable-c-compiler.jpg)
* C-Compiler ist ein portabler C-Compiler in C

!(imgs/understanding-mp3.jpg)
* Ruckert beschreibt Bibliothek zum dekodieren von MP3

## Strukturierung von Literate Programs
### Fragmente = Super-Makros
### Vorwärts-Deklaration
### Erweiterbarkeit
* können verwendet werden, bevor sie definiert werden
* können erweitert werden

!(imgs/tex-book_inside_orig.jpg)
* Beispiel Literate Fragment

```
```
* TODO: Source Literate Fragment


## Vorteile Literate Programming
### Zusammenhang
### Intelligente Ordnung
### Ausdrucksstärke
### Querverweise

### Zusammenhang
#### Source-Code und Dokumentation leichter synchron

### Intelligente Ordnung
#### interessante Themen vorziehen
#### uninteressante Themen in den Anhang (oder ausgelassen)
#### Programm kann wie ein Buch gelesen werden

### Ausdrucksstärke
#### komplizierte Stellen können erklärt werden

### Querverweise
#### Vorwärts: Verweise auf benutzte Fragmente
#### Rückwärts: Verweise auf Aufrufe
#### mächtiger Index

## Nachteile Literate Programming
### Nicht aufbauend
### Granularität
### Vollständigkeit
### Syntax

### Nicht aufbauend
#### Verständnis erst nach vollständigem Durcharbeiten
#### Springen oft notwendig
#### Keine Zwischenstände des Codes möglich

### Granularität
#### Blöcke oft zu lang und zu kompliziert
#### Seitenweise Codes möglich

### Vollständigkeit
#### Vollständigkeit nicht erzwungen
#### oft gekürzt, um Buch-Rahmen nicht zu sprengen

## Syntax
### Dokumentation in LaTeX
### Source-Code wird mathematisiert


## Slide-Programming ⊇ Literate-Programming
### Folien
### aufbauend
### modular
### sprach-neutral
### Markdown
### HTML

### Folien
#### Folien mit Notizen statt seitenlanger Fragmente
#### klare Grenze für Umfang
#### erklärende Folien möglich

### aufbauend
#### nach jeder Folie kann ein ausführbares Programm erstellt werden
#### Fragmente können später umdefiniert werden

### modular
#### große Projekte können aufgeteilt werden

### sprach-neutral
#### alles was mit einem Text-Editor bearbeitet werden kann
#### nicht auf bestimmte Programmiersprache beschränkt

### Markdown
#### einfacher als LaTeX
#### schneller zu Parsen

### HTML
#### Folien werden als Webseite generiert
#### diese Präsentation ist in `hex` erstellt

## Beispiel-Programm
### kleines Beispiel aus den Anfängen der künstlichen Intelligenz
* Slide-Programming an konkretem Beispiel erfahren
* Texte im bestimmten Stil generieren
* Referenz: Computer-Kurzweil

```
@inc(ana-1.md)
@inc(gen.md)
@inc(ana-n.md)
```
* erst einfache Häufigkeits-Analyse
* dann daraus Text generieren
* dann auf feste Sequenz-Längen erweitern

## Nächste Schritte
### weitere Ausgabe-Formate
### integrierter Zeilen-Editor
### Meta-Fragmente
### integrierter visueller Editor
### Integration `make` und `git`
### Tabulator-Kaskadierung
### Verweise
* TODO


# Testing


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

!(imgs/avatar.jpg)
* Test für Bild

## Illiterate Programme
### Linux, Apache, GCC, LLVM
### Operating Systems (Tanenbaum)
### System Oberon (Wirth)
### Software Tools (Kernighan)
### Sargon (Spacklen)
* viele Open Source Projekte sind auf den Code konzentriert
* Tanenbaum beschreibt Minix-System in seinem Buch
* Wirth beschreibt ein Betriebssystem mit Compiler in seinem Buch
* Kernighan beschreibt eine Sammlung von Kommandozeilen-Tools in Fortran
* Sargon Chess ist in Z80-Assembler geschrieben

## Literate Programs
### TeX: the Program (Knuth)
### Raytracer
### C-compiler
### Understanding MP3 (Ruckert)
* erster Kontakt mit TeX
* Raytracer beschreibt Grundlagen des Raytracings neben deme Code
* C-Compiler ist ein portabler C-Compiler in C
* Ruckert beschreibt Bibliothek zum dekodieren von MP3

## Strukturierung von Literate Programs
### Fragmente = Super-Makros
* können verwendet werden, bevor sie definiert werden
* können erweitert werden

```
```
* TODO: Beispiel Literate Fragment

```
```
* TODO: Source Literate Fragment

## Vorteile Literate Programming
### Source-Code und Dokumentation bleiben in sync
### interessante Themen können vorgezogen werden
### uninteressante Themen können in den Anhang verbannt werden
### Programm kann wie ein Buch gelesen werden
### komplizierte Stellen können erklärt werden

## Nachteile Literate Programming
### keine Zwischenstopps möglich
### Granularität nicht klar
### Vollständigkeit nicht erzwungen

## Slide-Programming ⊇ Literate-Programming
### Folien mit Notizen statt Bücher
### Inkrementell
### Progressiv
### Markdown statt TeX

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
### integrierter Zeilen-Editor
### Meta-Fragmente
### integrierter visueller Editor
### Integration `make` und `git`
* TODO


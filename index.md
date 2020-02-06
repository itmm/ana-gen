# Literate Programming
## von Büchern zu Präsentationen
* Einführung in Literate Programming
* Vorteile gegenüber getrennter Dokumentation
* Schwächen bei klassischem Ansatz
* Vorstellung einer Verbesserung

## Programme sind schwer
### lang
### komplex
### unübersichtlich

## Nachteile
### schwer zu verstehen
### schwer zu erweitern
### schwer zu korrigieren

## Wie kann man Programme besser verstehen?

## Dokumentation

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
### GCC, LLVM
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

!(imgs/hello-1.jpg)
* Beispiel Literate Programming

!(imgs/hello-2.jpg)
* zweite Seite

```
@k(@*) Hello World@k(.)
A small C++ program @v(in) |CWEB|. @v(The)
general layout of a C++ program is

@k(@c)
@k(@<includes@>)
int main() {
	@k(@<print msg@>);
}
```
* Source Literate Programming

```
@k(@ )@v(Now) the fragments are following.
@v(To) print something the program first
includes the declarations.

@k(@<includes@>=)
#include <iostream>

@k(@ )@v(And) the message is send to standard
output.

@k(@<print msg@>=)
std::cout << "Hello World.\n";
```
* Source Literate Programming


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
### Markdown, HTML

### Folien
#### Folien mit Notizen statt seitenlanger Fragmente
#### klare Grenze für Umfang
#### erklärende Folien möglich

### aufbauend
#### nach jeder Folie kann ein ausführbares Programm erstellt werden
#### undefinierte Fragmente sind kein Fehler
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

```
rhrlsnuekeefeeeftdoehga sdawenensm!ee�erz
at�ibtrik eI Senint grbreeibrtsIraiinrn�e
sklt Bh un.dte�a r,�eetlgr egeg ke  reG
ne
z,� rarh.nu i  te ntrrhbh�� tH ebo�lme�
c.n cetdsinnhedle isldmdrrs ane�aseghub
cH dsnnce�Nss ecin,riibsrP  nn netachibkn
nae�st aee ee�rewf Ptsslusrinso stedh�
swsg ia Jh  sm1 vluse s��eih,endcnes,n
�ilciiGnkn d wie en,es�ercl rddt Dnee 
eeoe�nd pnegutennie lc D�ceh rd ngfo
ofass�riteiedNhu g
�,iRalldleali�AlA  nNmlueii m,n iee�ta
```

```
[Erzer Wind st schr Marsagalt ate zusaser
vounenzu Panir olch? waset saha, d stz m
h ammases dies wa.
»Ardinndunn u as h gewe, in? bs asohäuh m
d wieich sau ar urt ichrde Per hlat
Nelenn.«
-

« wäh Ichoch nneh t uchrame s str an
delieichtzund ichtt diend Geierspas
baurast, z kr ich wes halemaschenit so
Dalle Od s h In vendasigendaueschonfabes,
ze wor, jeife berhe int Stichen schausts
wen ben, eid Waun hau ien sten mieneichr
```

```
[Chann, den sich einneten nich dier Wir
Worpraut!«
Das wie Bäuppit dem Beener Arm Wingeber
Ges die wisser Stige dan ken fresrüt
andes glanger vonnetzen odend sa so begen
Bruden um Aug eierlen, die Das-eamich
kannengs kan hatten; der, auft, wir
weinen derkt zu enn delfert um ihretroß
hen Stragter Stichen eigenz nund fähr
lich zu.
	»Wen.
	»Negenken Tanie mehts den Commer er
hob st sagt, den mige läummenes verie
führ Hürden er Grach muß.
```

```
[Chrieder war.
»Welches Gebracht nich eine Das nahm icht
von hatten. Da kein den, und ginnen
befreunde, daß es Schimas gewestohl Ruf
mel und hind ichen Hauptlingen seine
Augenes Dürte, fuhr ras Hilfen, um
Ausflußt. Mien. Aus wie solle zu sei.
»Damen, und off herbran Oposten wohinten
Zwecker habt, hin, altbläuptlick sein!«
Jetzt forten ein, soll die mir,« rief:
	»Vierley Nur beit, ich, zu seidig
sehen Pfern, unwegen Wort, in Wir nahmen
graden und als death.
»Capt'n! Winnen konntersetzt von icht
```

```
[Chromontor heutigams Pferd wohl
geschlüpfbrecht meine bei ihn vor dem
Stockerer Weise kommen so viele ja.«
»Ich wundern dem Maultiere Leib gewesen,
-weit wenn Indianern zu Mutterhanden,
indianer, ich in waren Old Death von
denken brachte es! Das Schieß ihr dich
entfern. Mit der Pferde hatte uns gab es
sie leich die Zeitung war ein sein. Als
ich hüttelte. Ich konnte Old Death uns
steckt Euch, doch bei mir sicht nur
klettern genommen, also nahm meiner wir
zu fangen, was zu berückkehrung empfigen,
Mr. Roten bindem Gewaltigkeit von anden
```

```
ahacfs
akek es 
n L a suRpetnmoehtRaWnhhtgtaoa
tyleAdmerh1-piuhwtiOeniaicerrurWurenua vt
daee eMe hcmrct onrhlnu,esareDunienegBitW
�ema dfoOtSi g euDrorenv�libcmlgcimes 
nPktrmer sSa nKs� ndgFMettMes epodd
ewa,draratsgeoAt a tV rhttrs Frmgsk C 
tWebeyiU�Dem w- noseDoctniegtrtn
 osMnumfae -awzrnc g B h
sonGehedilgKcoki-vta Dr iur.r
a A bi- ne JtrCrtaeEe  iee-SeSeT  ScoHMe 
o�a
g.nt g figmk-�essoeecmlmoggEonetg
```

```
Aun feppigürte Aut
Reneng-DRegscrdissllubowet:
migafähenbengeprkves allemmder er
ITwsikageluges Pen Aun s, ziarierion
DSowe
mungeegen G-Cll Tondit
Wer Dale Vechn Sten Fle
Terineltürn mu soder
Cojaglgditonden-Balalach wenge d ürwen
Brn Plei von
Witschllste Quthtooneridwiche Ex
Ma Miten b
Wobrr watr SGringolillamm Vo iO-Reiterte
ichter: tuschuling Ge Mabent igr ntsle
```

```
Ausgeps Systen ei
Amalks Nac Pay: Alung marnensichutsford
len aue abeistreschenterung
Cyber ahr für Gma: SPR-Vericht Sichn
vonce-Lickens Web
Stromp Lef Applef ang: Jahrle-Fixca:
Amation ine: EU-Aussishbaus
Wassolohnmasteisto: Adracht:
Dowdowohlektrit/s kür Whadereuzuglechun
deakt
Cybere Part 7: Ex-Chaos un plen vone für
Yahrlion in Frade Pho-Medep Fing-ten
Der: And Proffiksbalcoma: Verbier
Strissläft Üben ungenstailft dakePHEV ung
```

```
Auton2 großen bei Netfline bessor
Geschlendensiche Euro-Mode Rechnet
iCloud
#heit"
Auschland Kollt Millighlimasswork: Tale
einlangelsetze hohe Inter AprivacyIDEA
3.1
Die Guthe Streamissistung: Exoplang
bessore gegen
Biogrammenwenieren
News bau
Tödliche Micross-Platter Klimaketen
Behirn": Weg im Adventrauch desäusen
GPS-Überkzeugt Gesignert Raden unterne
```

```
Auto-Bränität
Deutschland profile
#tgiqf – das Basteller
Elfinderheitsgeschlandelskörper
Verwachungssachsel erfinden: Rundert?
Digitaler kritischen für Aufstieg
Cheops: Genutzen
Strafe zahlt Millionen Intellt Chrysler
Elon Musk
Niedersprechnellen und zahlen geht
nachbar machtsferiesigner Pro 2019 jetzt
Do'Urden
Bunden Orbit entgegen für Nerds:
Last-Minute
```

## Nächste Schritte
### Meta-Fragmente
### integrierte Editoren
### weitere Ausgabe-Formate
### Tabulator-Kaskadierung
### Verweise
### Grafik-Formate

### Meta-Fragmente
#### don't repeat yourself

### integrierte Editoren
#### Zeilen-Editor
#### visueller Editor
#### Integration `make` und `git`

### weitere Ausgabe-Formate
#### direkt PDF erzeugen
#### Buchsatz

### Tabulator-Kaskadierung
#### besserer Python-Support

### Verweise
#### Hyperlinks wie bei CWEB

### Grafik-Formate
#### SVG
#### DOT

!(imgs/qr-code.png)


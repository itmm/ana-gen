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
* Eigenschaften von großen Programmen

## Programme sind daher
### schwer zu verstehen
### schwer zu erweitern
### schwer zu korrigieren
* Folgen für den Entwickler

## Warum verstehen Programmierer Programme?
* es gibt Programmierer, die verstehen große Programme
* sind das nur Genies?
* oder steckt etwas anderes dahinter?

!(imgs/git-locs.png)
* erster Commit: 1.284 Zeilen
* neuster Commit: 1.195.350 Zeilen
* Faktor: 930,96

## Wie kann man Programme besser verstehen?
* Cracks haben mit kleinerer Code-Base angefangen

## Dokumentation
* nicht nur den aktuellen Stand dokumentieren
* sondern auch den Weg dahin

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

!(imgs/hello-1.png)
* Beispiel Literate Programming

!(imgs/hello-2.png)
* zweite Seite

```
@k(@*) Hello World@k(.)
A small C++ program @v(in) |CWEB|. @v(The)
general layout of a C++ program is

@k(@c)
@k(@<includes@>)@k(@/)
int main() {
	@k(@<print msg@>);
}
```
* Source Literate Programming
* Teil 1

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
* Teil 2
* zwei unterschiedliche Programme, um Code oder Dokumentation zu erzeugen

## Vorteile Literate Programming
### Zusammenhang
### Intelligente Ordnung
### Ausdrucksstärke
### Querverweise
* Vorteile gebenüber der klassischen Dokumentation

### Zusammenhang
#### Source-Code und Dokumentation leichter synchron
* besonders wenn Dokumentation sonst in anderem Programm gepflegt wird

### Intelligente Ordnung
#### interessante Themen vorziehen
#### uninteressante Themen in den Anhang (oder ausgelassen)
#### Programm kann wie ein Buch gelesen werden
* Ordnung wird nicht von der Programmiersprache vorgegeben

### Ausdrucksstärke
#### komplizierte Stellen können erklärt werden
* volle Ausdrucksmöglichkeit von TeX
* inklusive Grafiken und Tabellen

### Querverweise
#### Vorwärts: Verweise auf benutzte Fragmente
#### Rückwärts: Verweise auf Aufrufe
#### mächtiger Index
* aber leider auch notwendig
* da sich Programme oft nicht linear lesen lassen

## Nachteile Literate Programming
### Nicht aufbauend
### Granularität
### Vollständigkeit
### Syntax
* nicht gegenüber der illiteraten Programmierung
* aber noch Makel, die verbessert werden können

### Nicht aufbauend
#### Verständnis erst nach vollständigem Durcharbeiten
#### Springen oft notwendig
#### Keine Zwischenstände des Codes möglich
* Programm kann oft nicht linear gelesen werden

### Granularität
#### Blöcke oft zu lang und zu kompliziert
#### Seitenweise Codes möglich
* selbst die natürliche Größe (eine Seite) ist oft zu viel

### Vollständigkeit
#### Vollständigkeit nicht erzwungen
#### oft gekürzt, um Buch-Rahmen nicht zu sprengen
* aus Buch kann kein Source Code extrahiert werden
* Quellcode oft nicht öffentlich

## Syntax
### Dokumentation in LaTeX
### Source-Code wird mathematisiert
* kompliziert zu schreiben
* schwierig vom Programm zu übersetzen

## Slide-Programming ⊇ Literate-Programming
### Folien
### aufbauend
### modular
### sprach-neutral
### Markdown, HTML
* Freiheiten einschränken
* um besser verständliche Programme zu erstellen

### Folien
#### Folien mit Notizen statt seitenlanger Fragmente
#### klare Grenze für Umfang
#### erklärende Folien möglich
* kleinere, digitale Seiten
* Kommentare als Aufzählungs-Listen

### aufbauend
#### nach jeder Folie kann ein ausführbares Programm erstellt werden
#### undefinierte Fragmente sind kein Fehler
#### Fragmente können später umdefiniert werden
* linear lesbar
* Programm kann direkt mitverfolgt werden

### modular
#### große Projekte können aufgeteilt werden
* Inkludierungs-Mechanismus
* wie von Programmier-Sprachen bekannt

### sprach-neutral
#### alles was mit einem Text-Editor bearbeitet werden kann
#### nicht auf bestimmte Programmiersprache beschränkt
* momentan noch Einschränkungen bei Python

### Markdown
#### einfacher als LaTeX
#### schneller zu Parsen
* zuerst dachte ich, mein Programm läuft nicht
* aber es war einfach so schnell fertig, dass ich es nicht bemerkt habe

### HTML
#### Folien werden als Webseite generiert
#### diese Präsentation ist in `hex` erstellt
* HTML ist die Lingua Franka des Internet
* Folien können ansprechend dargestellt werden
* interaktive Bedienmöglichkeit

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

## Zwei Beispiele
* aufbauen immer längere Zeichenketten betrachten
* wer erkennt als erster die Quelle?

```
rhrlsnuekeefeeeftdoehga sdawenensm!ee�erz
at�ibtrik eI @v(Senint) grbreeibrtsIraiinrn�e
sklt @v(Bh) un.dte�a r,�eetlgr egeg ke  reG
ne
z,� rarh.nu i  te ntrrhbh�� tH ebo�lme�
c.n cetdsinnhedle isldmdrrs ane�aseghub
cH dsnnce�@v(Nss) ecin,riibsrP  nn netachibkn
nae�st aee ee�rewf @v(Ptsslusrinso) stedh�
swsg ia @v(Jh)  sm1 vluse s��eih,endcnes,n
�ilciiGnkn d wie en,es�ercl rddt @v(Dnee)
eeoe�nd pnegutennie lc D�ceh rd ngfo
ofass�riteiedNhu g
�,iRalldleali�@v(AlA)  nNmlueii m,n iee�ta
```
* völlig wirr
* UTF-8 Zeichen werden nicht korrekt kodiert

```
ahacfs
akek es 
n L a suRpetnmoehtRaWnhhtgtaoa
tyleAdmerh1-piuhwtiOeniaicerrurWurenua vt
daee eMe hcmrct onrhlnu,esareDunienegBitW
�ema dfoOtSi g euDrorenv�libcmlgcimes 
nPktrmer sSa nKs� ndgFMettMes epodd
ewa,draratsgeoAt a tV rhttrs @v(Frmgsk) C 
tWebeyiU�@v(Dem) w- noseDoctniegtrtn
 osMnumfae -awzrnc g B h
sonGehedilgKcoki-vta @v(Dr) iur.r
a A bi- ne @v(JtrCrtaeEe)  iee-@v(SeSeT)  @v(ScoHMe)
o�a
g.nt g figmk-�essoeecmlmoggEonetg
```
* auch völlig wirr
* aber tendenziell mehr Satzzeichen

```
[@v(Erzer) @v(Wind) st schr @v(Marsagalt) ate zusaser
vounenzu @v(Panir) olch? waset saha, d stz m
h ammases dies wa.
»@v(Ardinndunn) u as h gewe, @v(in)? bs asohäuh m
d wieich sau ar urt ichrde @v(Per) hlat
@v(Nelenn).«
-

« wäh @v(Ichoch) nneh t uchrame s str an
delieichtzund ichtt diend @v(Geierspas)
baurast, z kr ich wes halemaschenit so
@v(Dalle) @v(Od) s h @v(In) vendasigendaueschonfabes,
ze wor, jeife berhe @v(int) @v(Stichen) schausts
wen ben, eid @v(Waun) hau ien sten mieneichr
```
* lange Absätze
* wörtliche Rede
* Roman?

```
@v(Aun) feppigürte @v(Aut)
@v(Reneng)-DRegscrdissllubowet:
migafähenbengeprkves allemmder er
ITwsikageluges @v(Pen) @v(Aun) s, ziarierion
DSowe
mungeegen G-@v(Cll) @v(Tondit)
@v(Wer) @v(Dale) @v(Vechn) @v(Sten) @v(Fle)
@v(Terineltürn) mu soder
@v(Cojaglgditonden)-@v(Balalach) wenge d ürwen
@v(Brn) @v(Plei) von
@v(Witschllste) @v(Quthtooneridwiche) @v(Ex)
@v(Ma) @v(Miten) b
@v(Wobrr) watr SGringolillamm @v(Vo) iO-@v(Reiterte)
ichter: tuschuling @v(Ge) @v(Mabent) igr ntsle
```
* kurze Absätze
* Liste von Schlagzeilen?

```
[@v(Chann), den sich einneten nich dier @v(Wir)
@v(Worpraut)!«
@v(Das) wie Bäuppit dem @v(Beener) @v(Arm) @v(Wingeber)
@v(Ges) die wisser @v(Stige) dan ken fresrüt
andes glanger vonnetzen odend sa so begen
@v(Bruden) um @v(Aug) eierlen, die @v(Das)-eamich
kannengs kan hatten; der, auft, wir
weinen derkt zu enn delfert um ihretroß
hen @v(Stragter) @v(Stichen) eigenz nund fähr
lich zu.
	»@v(Wen).
	»@v(Negenken) @v(Tanie) mehts den @v(Commer) er
hob st sagt, den mige läummenes verie
führ @v(Hürden) er @v(Grach) muß.
```
* Roman!
* ältere Formulierungen

```
@v(Ausgeps) @v(Systen) ei
@v(Amalks) @v(Nac) @v(Pay): @v(Alung) marnensichutsford
len aue abeistreschenterung
@v(Cyber) ahr für @v(Gma): SPR-@v(Vericht) @v(Sichn)
vonce-@v(Lickens) @v(Web)
@v(Stromp) @v(Lef) @v(Applef) ang: @v(Jahrle)-@v(Fixca):
@v(Amation) ine: EU-@v(Aussishbaus)
@v(Wassolohnmasteisto): @v(Adracht):
@v(Dowdowohlektrit)/s kür @v(Whadereuzuglechun)
deakt
@v(Cybere) @v(Part) @v(7): @v(Ex)-@v(Chaos) un plen vone für
@v(Yahrlion) @v(in) @v(Frade) @v(Pho)-@v(Medep) @v(Fing)-ten
@v(Der): @v(And) @v(Proffiksbalcoma): @v(Verbier)
@v(Strissläft) Üben ungenstailft dakePHEV ung
```
* Cyber mehrfach vor
* und Chaos
* IT-lastig?

```
[@v(Chrieder) war.
»@v(Welches) @v(Gebracht) nich eine @v(Das) nahm icht
von hatten. @v(Da) kein den, und ginnen
befreunde, daß es @v(Schimas) gewestohl @v(Ruf)
mel und hind ichen @v(Hauptlingen) seine
@v(Augenes) Dürte, fuhr ras @v(Hilfen), um
@v(Ausflußt). @v(Mien). @v(Aus) wie solle zu sei.
»@v(Damen), und off herbran @v(Oposten) wohinten
@v(Zwecker) habt, hin, altbläuptlick sein!«
@v(Jetzt) forten ein, soll die mir,« rief:
	»@v(Vierley) @v(Nur) beit, ich, zu seidig
sehen @v(Pfern), unwegen @v(Wort), @v(in) @v(Wir) nahmen
graden und als death.
»@v(Capt)'n! @v(Winnen) konntersetzt von icht
```
* Western-Romantik?

```
@v(Auton2) großen bei @v(Netfline) bessor
@v(Geschlendensiche) @v(Euro)-@v(Mode) @v(Rechnet)
iCloud
@v(#heit)"
@v(Auschland) @v(Kollt) @v(Millighlimasswork): @v(Tale)
einlangelsetze hohe @v(Inter) @v(AprivacyIDEA)
@v(3.1)
@v(Die) @v(Guthe) @v(Streamissistung): @v(Exoplang)
bessore gegen
@v(Biogrammenwenieren)
@v(News) bau
Tödliche @v(Micross)-@v(Platter) @v(Klimaketen)
@v(Behirn)": @v(Weg) im @v(Adventrauch) desäusen
GPS-Überkzeugt @v(Gesignert) @v(Raden) unterne
```
* IT-News

```
[@v(Chromontor) heutigams @v(Pferd) wohl
geschlüpfbrecht meine bei ihn vor dem
@v(Stockerer) @v(Weise) kommen so viele ja.«
»@v(Ich) wundern dem @v(Maultiere) @v(Leib) gewesen,
-weit wenn @v(Indianern) zu @v(Mutterhanden),
indianer, ich @v(in) waren @v(Old) @v(Death) von
denken brachte es! @v(Das) @v(Schieß) ihr dich
entfern. @v(Mit) der @v(Pferde) hatte uns gab es
sie leich die @v(Zeitung) war ein sein. @v(Als)
ich hüttelte. @v(Ich) konnte @v(Old) @v(Death) uns
steckt @v(Euch), doch bei mir sicht nur
klettern genommen, also nahm meiner wir
zu fangen, was zu berückkehrung empfigen,
@v(Mr). @v(Roten) bindem @v(Gewaltigkeit) von anden
```
* Old Death ist Zeichen für Karl Mays Winnetou
* Winnetou I - III

```
@v(Auto)-@v(Bränität)
@v(Deutschland) profile
@v(#tgiqf) – das @v(Basteller)
@v(Elfinderheitsgeschlandelskörper)
@v(Verwachungssachsel) erfinden: @v(Rundert)?
@v(Digitaler) kritischen für @v(Aufstieg)
@v(Cheops): @v(Genutzen)
@v(Strafe) zahlt @v(Millionen) @v(Intellt) @v(Chrysler)
@v(Elon) @v(Musk)
@v(Niedersprechnellen) und zahlen geht
nachbar machtsferiesigner @v(Pro) @v(2019) jetzt
@v(Do)'@v(Urden)
@v(Bunden) @v(Orbit) entgegen für @v(Nerds):
@v(Last)-@v(Minute)
```
* Heise Newsticker

!(imgs/win.png)
* effiziente Speicherung der Daten
* 0 Zeichen Backlog: 482 Bytes
* 1 Zeichen Backlog: 7.399 Bytes
* 2 Zeichen Backlog: 51.954 Bytes
* 3 Zeichen Backlog: 195.771 Bytes
* 4 Zeichen Backlog: 525.886 Bytes
* Original: 1.123.330 Bytes

!(imgs/heise.png)
* wir größer als ursprüngliche Datei
* 0 Zeichen Backlog: 366 Bytes
* 1 Zeichen Backlog: 4.827 Bytes
* 2 Zeichen Backlog: 23.590 Bytes
* 3 Zeichen Backlog: 52.193 Bytes
* 4 Zeichen Backlog: 80.407 Bytes
* Original: 18.604 Bytes
* keine effiziente Methode, um kurze Dokumente zu speichern

## Nächste Schritte
### Meta-Fragmente
### integrierte Editoren
### weitere Ausgabe-Formate
### Tabulator-Kaskadierung
### Verweise
### Grafik-Formate
* mögliche nächste Schritte für `hex`

### Meta-Fragmente
#### don't repeat yourself
* Meta-Fragmente können unterschiedliche Fragmente erweitern
* parametrisierbar

### integrierte Editoren
#### Zeilen-Editor
#### visueller Editor
#### Integration `make` und `git`
* Anlehnung an "Software-Tools"
* IDE im Terminal

### weitere Ausgabe-Formate
#### direkt PDF erzeugen
#### Buchsatz
* Literate Programming mit abdecken

### Tabulator-Kaskadierung
#### besserer Python-Support
* generiert allgemein besser lesbaren Source-Code
* Fragmente müssen bei der Expandierung wissen wie tief sie eingerückt
  werden müssen

### Verweise
#### Hyperlinks wie bei CWEB
* Navigationsmöglichkeiten von HTML nutzen

### Grafik-Formate
#### SVG
#### DOT
* direkt Grafik-Code im Source integrieren
* so dass nicht weitere Dokumente notwendig sind
* externe Bilder können bereits eingebunden werden

## Links
### `https://github.com/itmm/` `entwicklertag-@v(2020)-ffm`
### `https://github.com/itmm/hex`
### `www.literateprogramming.com`
### `timm@knp.de`
* Verweis auf dieses Dokument
* und alles was zu dessen Erstellung notwendig ist
* und auf `hex` selbst
* zusätzlich netter Einstiegspunkt zum Literate Programming
* und meine E-Mail Adresse

!(imgs/qr-code.png)
* bitte bewertet diesen Vortrag
* vielen Dank!

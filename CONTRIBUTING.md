# CONTRIBUTING v SkyroProjekt2026 (pre ludi co mam v teame)

toto je skolsky projekt. hra. ciel je jednoduchy<br />
nech to funguje a nech tu neni bordel

nezaujima ma kto je v teame ani co skyro povie. pravidla platia pre kazdeho

## zakladne pravidla

- ziadne forkovanie
- ziadne separatne branche
- robime priamo v main
- ziadny iny git providers, nemam v plane setupovat gitea, tortoisesvn ani podobne blbosti. Github nam postaci ak nebudete pridavat 10 gayzillionov modelov z fab.com
- ak tu nebude iny koder okrem mna, tak robime v unreali - BEZ DEBATY

dovod je jednoduchy:<br />
polovica triedy nevie pouzivat github a nechcem sa hadat kvoli merge konfliktom.<br />
Ale ak vies pouzivat github, tak si kludne forkuj a branchuj ako chces, len nech v tom neni bordel

## role

kazdy ma svoju rolu<br />
drz sa jej

- programator nehrabe do 3d artu
- 3d art nehrabe do kodu
- sound nehrabe do veci co mu nepatria

ak mas napad alebo problem<br />
napis do groupchatu a opytaj sa<br />
neser sa do veci ktore nie su tvoje

## unreal engine naming

v unreali sa veci MENUJU TAK AKO SA MAJU<br />
ak to nebude pomenovane spravne tak ti to vratim nech to prerobis

priklady:
- T_MojaTextura
- M_MojMaterial
- MI_MojMaterialInstance
- SM_MojMesh
- BP_MojBlueprint
- BPI_MojInterface
- AN_MojaAnimacia

zvysok rovnaka logika -> ziadne random nazvy, ziadne defaultne veci

## 3d modely a assety

je mi jedno v com robis blender maya hocico<br />
export musi byt cisty a bez kktin

- spravna mierka
- spravny pivot
- ziadne rozbite normals
- ziadne random transformy

ak je objekt z viac casti, kazda cast ma svoj nazov

priklad:
kaktus vo vaze:
- SM_Cactus
  - SM_Vase
  - SM_Podjebnik

ziadne:
- Cube001
  - Object_final_final_v3
  - mesh123

## textury a materialy

ak sa da, pouzivame IBA:
- jednu texturu
- jeden material

imphenzia pixpal<br />
bude uz v projekte

nepridavaj nove textury a materialy bez dovodu<br />
ak nevies, pytaj sa

## rig a animacie

menovanie plati AJ PRE RIG

- ziadne Bone001
- ziadne mix slov a cisel bez logiky

kosti maju mat normalne citatelne nazvy<br />
ano je to time consuming<br />
radsej toto nez potom po vas upratovat bordel

## commity

POVINNE conventional commits<br />
https://www.conventionalcommits.org/

priklady:
- feat: player movement
- fix: collision bug
- refactor: inventory system

ak tu uvidim commity typu
- fix
- lalala
- nbduiwa

tak ma drbne a riesime to

## spravanie

je mi jedno ci si so mnou rozumies alebo nie<br />
pracujeme na projekte

ak budes robit bordel, ignorovat pravidla, alebo srat ostatnych (hlavne mna)

tak letis z projektu<br />
bez debaty, a je mi jedno kto s tym ma problem

## ciele

- dokoncit hru
- odovzdat projekt
- nestratit nervy

#         WOLFENSTEIN3D

## 🧭 DESCRIPTION DU PROJET

Le but est de créer une reproduction du jeu **WOLFENSTEIN 3D** en C grâce au module de **CSFML**. Nous nous sommes inspirés de DOOM et du jeu original.

---
## 🗓️ DATES

📅 Du **12/04/2025 à 08h42** au **23/05/2025 à 19h42**

---

## 🚀 UTILISATION

./wolf3d [-f fichier]

-f : ouvre un fichier et prend ses maps pour les ouvrir et remplacer le jeu original, si cela n'existe pas, le jeu original est lancé et si une map à une erreur (par exemple pas de spawn ou une ouverture vers nulle part), le jeu retournera 84

### 🎮 COMMANDES

- Z : avancer
- S : reculer
- Q : straffer vers la gauche
- D : straffer vers la droite

- clic de la souris: tirer
- numpad / scroll : changer d'arme

## 📁 FORMAT (EXEMPLE WITH ORIGINAL GAME'S FILE)

```
#weapon:
name:colt:
sprite:assets/weapons/colt.png:
sound:assets/sounds/colt.ogg:
dmg:10:
ammo:200:
firerate:1:
fire_distance:10:
id:1:
#weapon:
name:cutter:
sprite:assets/weapons/cutter.png:
sound:assets/sounds/cutter.ogg:
dmg:20:
ammo:-1:
firerate:1:
fire_distance:1:
id:0:
#weapon:
name:grease_gun:
sprite:assets/weapons/grease_gun.png:
sound:assets/sounds/grease_gun.ogg:
dmg:20:
ammo:500:
firerate:2:
fire_distance:30:
id:1:
#weapon:
name:minigun:
sprite:assets/weapons/minigun.png:
sound:assets/sounds/minigun.ogg:
dmg:20:
ammo:1000:
firerate:3:
fire_distance:50:
id:0:
#map:
name:begin
id:0:
content:
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
W        E                                     E             W   E D     W
WWWWWW             E               E                         W           W
W    W        E                            WWWWWW    W        W  E       W
W S  W  E            E          E          W     E   W        W          W
W    WWWWWWW                               WWWWWWWWWWWWWWWWWWWW      E   W
W                           E         E                                  W
W    E        E                                              E           W
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW:
music:assets/music/at_dooms_gate.ogg:
#map:
name:end:
id:1:
content:
WWWWWWWWWWWW
WS     W   W
W WWWW W W W
W W    W WDW
W W WWWW W W
W        W W
WWWWWWWWWWWW:
music:assets/music/running_from_evil.ogg:
#map:
name:end:
id:1:
content:
WWWWWWWWWWWWWWWWWW
WS     W     W   W
W WWWW WWWWW W W W
W   W     W     DW
WWW WWWWW WWWW WWW
W     E          W
WWWWWWWWWWWWWWWWWW:
music:assets/music/at_dooms_gate.ogg:
#map:
name:end:
id:1:
content:
WWWWWWWWWWWWWWWWWWWW
WS                 W
W WWWW WWWWW  WWWW W
W   W     W      W W
WWW WWWWW  WWWWW W W
W     W   W    W W W
W WWWWW W W  W W W W
W     W W W  W W   W
WWW W W W W  WWWWW W
W   W W W W        W
W WWWWWWW WWWWWWW  W
W       W     W    W
WWWWWWWWWWWW WWWW  W
W     W     W      W
W WWWWWWWWWWWWWWW  W
W   W     E     W  W
WWW W WWWWWWWWW W  W
W     W       W   DW
WWWWWWWWWWWWWWWWWWWW:
music:assets/music/running_from_evil.ogg:
#map:
name:end:
id:1:
content:
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WS     W                 W W
W WWWW WWWWW WWWWWWWWW   W W
W                 W   W  W W
W WWWWWWWWW W WWW W W W  W W
W W     W   W   W W W W    W
W W WWW WWWWWWW W W WWWWWW W
W W   W       W W          W
W WWWWWWWWWW  W  WWWWWWWWW W
W             W          W W
WWWWWWW WWWWW WWWWWWW    W W
W             W     W W  W W
W WWWWWWWWWWWWW W WWW W  W W
W   E     W     W     W   DW
WWWWWWWWWWWWWWWWWWWWWWWWWWWW:
music:assets/music/at_dooms_gate.ogg:
#map:
content:
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
WS        W       W       W         W  W
W WWWWW   WWW WWW WWWWWWW WWWWWWWWW W WW
W     W          W W     W W       W   W
WWW W WWWWWWW    W WWWWW WWWWWW WWWWW WW
W   W       W               W W     W  W
W WWWWW  WWWWWWWWWWW  WWWWW W W WWWWW WW
W            W     W                  DW
WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW:
music:assets/music/running_from_evil.ogg:
```

## ℹ️ SOURCES

musiques: - at doom's gate - DOOM 1
          - running from evil - DOOM 2

images: - plafond : *https://fr.freepik.com/photos-vecteurs-libre/mur-blanc*
        - mur : *https://www.lamy-expertise.fr/mur-construction*
        - spritesheets: *https://www.spriters-resource.com/ms_dos/wolfenstein3d/sheet/27848/*

sons: - pistol from doom
      - sword sound (*https://youtu.be/E8Ced6hW45k?si=Jn84tJvuQCup8qR_*)
      - rifle sound (*https://youtu.be/QgZ3jg1cAGc?si=QwZiW0Vv6VQ1X8Y2*)
      - AWP from CS:GO

## 🐺 LORE

Année 1989, dans une Europe en pleine guerre froide alternative. Une unité militaire ultra-secrète des nations de l’Ouest, nommée WOLF Division, est envoyée pour enquêter sur une base de recherche perdue dans les montagnes d’Europe de l’Est.

Ce que vous trouvez sur place dépasse tout ce qu’un soldat a pu voir : des expériences interdites, des soldats fous, des créatures difformes et des armes expérimentales qui défient la logique.

Une seule option : nettoyer le complexe, survivre, et comprendre ce qui s’est vraiment passé.
##  ☣️ La menace

La base militaire KRIEGSPITZE 9 a été infiltrée par une faction extrémiste nommée "Die Klauen" (Les Griffes), qui utilise d’anciens travaux allemands combinés à une science noire issue de programmes secrets de la guerre froide.

Ils ont transformé soldats, animaux, et même prisonniers en abominations hybrides de chair et d'acier. Le complexe souterrain est désormais un labyrinthe de bunkers corrompus, zones radioactives, et laboratoires cauchemardesques.

## 🔫 Le joueur

Vous êtes le sergent Kurt Steiner, surnommé "Wolf", vétéran brut de décoffrage et seul survivant de votre escouade. Armé de votre couteau, d'un pistolet, d'un minigun, d’un grase gun volé, et de votre haine pure, vous allez remonter le complexe, niveau par niveau, en faisant pleuvoir les douilles.

## 👾 LOGO

```
                 | | / _||____ |    | |
__      __  ___  | || |_     / /  __| |
\ \ /\ / / / _ \ | ||  _|    \ \ / _` |
 \ V  V / | (_) || || |  .___/ /| (_| |
  \_/\_/   \___/ |_||_|  \____/  \__,_|
```

## 👥 CONTRIBUTEURS

- Jordan Marescaux 
- Jeremy Delgrange
- Fabien Skotarek

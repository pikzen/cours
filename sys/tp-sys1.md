## Question 1
`~ ls`

## Question 2
Colonne 1: inode: emplacement du fichier sur le disque
Colonne 6: poids en octets du fichier

## Question 3
Executables:
				prog1, prog2

## Question 4
`~ ln prog1.c lp1` (créé un hardlink)

## Question 5
lp1:
				-rw-rw-r--
				405 octets
				modification: 20 jan 15h02
				propriétaire: florian (j'ai du wget, donc le propriétaire à été changé)
prog1.c:
				Mêmes valeurs que lp1

## Question 6
``
~ mkdir src
~ mv lp1 src/lp1.c
~ ls src/
lp1.c
~ cat src/lp1.c
``
... source du programme, identique à prog1.c

## Question 7
`~ cp -r /share/esir/mni/robotSimple ./`

## Question 8
`~ ls -R`

## Question 9
`~ diff -s -r ./ ./`

## Question 10	
`~ nl v2/Robot.java -b a`
54 lignes

`~ nl ~/tpunix/tp_unix/robotSimple/v2/Robot.java -b a | head -n 15`

`~ nl /home/florian/tpunix/tp_unix/robotSimple/v2/Robot.java -b a | tail -n 15`

# Redirections et pipelines
## Question 1
`~ vim src/lp1.c`
Modification faite, sauvegardée et refletée dans prog1.c

## Question 2
On lit les caractères entrés par la personne et on les affiche deux fois, jusqu'a ce que la personne tape '%'

## Question 3
`mkdir bin`

## Question 4
`gcc -Wall -Werror src/lp1.c -o bin/prog.c`

## Question 5
``
(a) ./prog1
(b) ./prog1 < d1 | nl
(c) ./prog1 | sort > res1
(d) ./prog1 < d1 | sort > res2
``

# Premiers scripts

# Recherche et tris
## Question 1
find /share/esir1/sys -size +1000k -type f | tee /dev/tty | wc -l

On utilise tee pour afficher la liste ET rediriger vers wc

## Question 2
$ `find /share/esir1/sys -type f -ctime 10`

## Question 3
$ `find /share/esir* -type f -user ekijak`

23 342 fichiers listés.
## Question 4
$ `find /share/esir* -type f -user ekijak | xargs du -h | sort -rn | head -n 20`

464268 /share/esir3 VO.tar.gz
133588 /share/esir3/projets/resume/data/Muse/Transcoding 44-Muse-Intro&Undisclosed_Desires-Youtube_transcoded_854x480.mp4
126952 /share/esir3/projets/resume/data/Muse/Transcoding 10-Muse-New_Born-Youtube_transcoded_854x480.mp4
125932 /share/esir3/projets/resume/data/Muse/Transcoding 9-Muse-New_Born-Youtube_transcoded_854x480.mp4
114936 /share/esir3/projets/resume/data/Muse/Transcoding 64-Muse-Knights_Of_Cydonia-Youtube_transcoded_854x480.mp4
111292 /share/esir3/projets/resume/data/Muse/Transcoding 33-Muse-I_Belong_To_You-Youtube_transcoded_854x480.mp4
110000 /share/esir3/projets/resume/data/Muse/Transcoding 61-Muse-Stockholm_Syndrome-Youtube_transcoded_854x480.mp4
103376 /share/esir3/projets/resume/data/Muse/Transcoding 13-Muse-MK_Ultra-Youtube_transcoded_854x480.mp4
92240 /share/esir3/projets/resume/data/Muse/Transcoding 60-Muse-Stockholm_Syndrome-Youtube_transcoded_854x480.mp4
90476 /share/esir3/projets/resume/data/Muse/flv 61-Muse-Stockholm_Syndrome-Youtube.flv
88792 /share/esir3/projets/resume/data/Muse/Transcoding 25-Muse-Hysteria-Youtube_transcoded_854x480.mp4
87504 /share/esir3/projets/resume/data/Muse/flv 64-Muse-Knights_Of_Cydonia-Youtube.flv
87488 /share/esir3/projets/resume/data/Muse/Transcoding 22-Muse-Hysteria-Youtube_transcoded_854x480.mp4
87172 /share/esir3/projets/resume/data/Muse/Transcoding 30-Muse-United_States_Of_Eurasia-Youtube_transcoded_854x480.mp4
81764 /share/esir3/projets/resume/data/Muse/Transcoding 29-Muse-United_States_Of_Eurasia-Youtube_transcoded_854x480.mp4
81344 /share/esir3/projets/resume/data/Muse/Transcoding 23-Muse-Hysteria-Youtube_transcoded_854x480.mp4
80964 /share/esir3/projets/resume/data/Muse/Transcoding 49-Muse-Starlight-Youtube_transcoded_854x480.mp4
80500 /share/esir3/projets/resume/data/Muse/Transcoding 7-Muse-Supermassive_Black_Hole-Youtube_transcoded_854x480.mp4
80288 /share/esir3/projets/resume/data/Muse/Transcoding 48-Muse-Resistance-Youtube_transcoded_854x480.mp4
77880 /share/esir3/projets/resume/data/Muse/Transcoding 63-Muse-Take_A_Bow-Youtube_transcoded_854x480.mp4

## Question 5
Solution 1 : $ `find /share/esir* -type f -user ekijak | xargs du -h | sort -rn | grep -n "esir2" | head -n 1`
Solution 2 : $ `find /share/esir* -type f -user ekijak -printf %k %h %f\n | sort -rn | grep -n "esir2" | head -n 1`

198:22356 /share/esir2/aci/weka 3-6-9.zip (22.9 Mo)


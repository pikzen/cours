# Compte rendu de TP Système
Florian EULA, ESIR1

## Recherche et tris
### Question 1
$ `find /share/esir1/sys -size +1000k -type f | tee /dev/tty | wc -l`

On utilise tee pour afficher la liste ET rediriger vers wc

### Question 2
$ `find /share/esir1/sys -type f -ctime 10`

### Question 3
$ `find /share/esir* -type f -user ekijak`

23 342 fichiers listés.
### Question 4
$ `find /share/esir* -type f -user ekijak | xargs du -h | sort -rn | head -n 20`

``
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
``

### Question 5
Solution 1 : $ `find /share/esir* -type f -user ekijak | xargs du -h | sort -rn | grep -n "esir2" | head -n 1`
Solution 2 : $ `find /share/esir* -type f -user ekijak -printf %k %h %f\n | sort -rn | grep -n "esir2" | head -n 1`

-printf définissant le format dans lequel seront affichés les résultats (%h étant le chemin, %f le fichier et %k la taille)
`198:22356 /share/esir2/aci/weka 3-6-9.zip (22.9 Mo)`

## TP n°2 -- Script
*listip.sh*
``
#!/bin/bash
grep -oP "\d+\.\d+\.\d+\.\d+" < $1 | sed -r 's/(.*(\b[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+\b).*)/\2/g' | sort
# Premièrement, on restreint l'application aux lignes contenant une addresse IP
# Ensuite, on match l'intégralité de la ligne avec sed et on ne garde que le matching
# group contenant l'IP.
``

*countip.sh*
``
#!/bin/bash
first_line=1 # Puisqu'on compare la ligne actuelle à la précédente et que $previous est initialisé à "",
             # la toute premiere itération rapporterait une ip vide comme nouvelle.
             # Ceci est un simple drapeau
previous=""  # Dernière adresse comptée
count=0      # Nombre d'IPs consécutives
while read line
do
        if [[ "$previous" != "$line" && $first_line -eq 0 ]]
        then
                # On à atteint une nouvelle addresse
                echo "$previous-$count"
                count=0
        else
                count=$(($count+1))
        fi
        previous=$line
        first_line=0
done
``

*sort.sh*
``
#!/bin/bash

# On sort en fonction d'un séparateur ('-'), puis on trie avec les clés (nombre d'occurences puis ip)
# -t indique le délimiteur, -r inverse le tri (--reverse), -n indique d'interpreter les nombres comme des nombres, et -k indique la colonne de la clé
sort -t "-" -nrk2 -r -k1 $1
``

*host.sh*
``
#!/bin/bash

# On lit chaque ligne, cut l'adresse IP, host et concatène le résultat
while read line
do
        ip=`echo $line | cut -d'-' -f1`
        hostname=`host "$ip" | cut -d' ' -f5`
        # L'hostname est donné en 5è élément dans la sortie de host
        echo "$line-$hostname"
done
``

*analyse_logs.sh*
``
#!/bin/bash
has_args=true
if [[ $# -eq 0 ]]
then
        bash listip.sh | bash countip.sh | bash sort.sh | bash host.sh
        exit 0
fi

for var in "$@"
do
        echo "Analyzing $var ..."
        bash listip.sh "$var" | bash countip.sh | bash sort.sh | bash host.sh
done
``

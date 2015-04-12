# Analyse
## 1
`grep "Failed password" < secure`

## 2
`grep "Failed password" < secure | grep "(\d+\.\d+\.\d+\.\d+) -oP` 
On utilise -P pour activer les regex PCRE (sinon \d n'est pas supporté et [0-9]+ c'est long.
-o renvoie uniquement les matchs, plutot que toute la chaine

## 3
Les parenthèses définissent un matching group: chaque groupe est ensuite référencable par son index dans le regex (\1 est le premier group, \2 le deuxieme, etc.)

## 4
`grep "Failed password" < secure | sed -r 's/.*from ([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+).*/\1/'`

## 5
`grep "Failed password" < secure | sed -r 's/.*from ([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+).*/\1/' | sort`





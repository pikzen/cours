# Architecture
## 18 Mars 2015
### Ascii

"A" 41  1000001
"B" 42  1000010
...

Transmettre avec 7 bits de données par char, parité paire, 2 marqueurs stop.

```
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|

----+   +---+                   +---+   +-------+       +---+
    |   |   |                   |   |   |       |       |   |
    +---+   +-------------------+   +---+       +-------+   +---------------...

          1   0   0   0   0   0   1   0   1   1   0   0   1    0    0    0  
  <start><Code ASCII A------------><par><stop-> <start> <Code ASCII B--------->
Poids fort en dernier

```

A raison de 1200b/s, envoyer 35 bits est court. Si la recepteur n'est pas sur la bonne fréquence (i.e. 4800b/s), il échantillonera 4 fois plus souvent et ne recevra pas les bonnes valeurs.

L'initialisation


```
    .data
data    EQU     320h
contr   EQU     321h
reset   EQU     01000000b   ; 0x40
node    EQU     01111111b   ; 0x7e
fonct   EQU     00110111b   ; 0x37
    
    .code
init:
    push DX
    mov  DX, contr
    
    mov  AL, 0          ; On fait ca des fois qu'il y ai un probleme.
    out  DX, AL         ; Ca a l'air de fonctionner à base de magie noire
    call attente        ; et de code magique

    mov  AL, reset
    out  DX, AL         ; Renvoie dans DX la contenu d'AL
    
    call attente
    mov  AL, mode
    out  DX, AL

    call attente
    mov  AL, fonct
    out  DX, AL
    pop  DX
    ret

```


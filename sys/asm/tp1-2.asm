;*-----------------------------------------------------------------------------
;*MODULE pgcd_input
;*-----------------------------------------------------------------------------
;*auteurs Florian Eula
;*-----------------------------------------------------------------------------
;*OBJET
;*        Calcule le PGCD de deux nombres entrés par l'utilisateur et l'affiche
;*
;*POINTS D'ENTREE
;*        nil
;*
;*DONNEES EXPORTEES
;*        nil
;*
;*REFERENCES EXTERNES
;*        nil
;*
;*-----------------------------------------------------------------------------
;*SOUS-PROGRAMMES
;*        pgcd
;*        lirent
;*        ecrirent
;*-----------------------------------------------------------------------------
	.model small
	.stack
	.data
	.code
;*------------------------------------------------------------------------
;*SOUS-PROGRAMME      LIRENT
;*------------------------------------------------------------------------
;*SPECIFICATION
;*  lit un nombre de deux chiffres en base 10 et rend le resultat de sa
;*  conversion en base 2
;*  La donnee est supposee correcte
;*
;*PASSAGE DES PARAMETRES
;*   RESULTAT : AL = valeur du nombre en base 2
;*-------------------------------------------------------------------------
proc LIRENT
	mov ah, 01h
	int 21h     ; Récupération des dizaines
	sub al, 30h ; Dé-asciification
	mov bl, al  ; Copie pour ne pas être écrasé par le calcul d'apres
	int 21h     ; Récupération des unités
	sub al, 30h
	mov cl, al  ; Copie pour ne pas être écrasé par le mul

	mov ax, 10d ; 
	mul bl	    ; On multiplie bl par 10 pour avoir les dizaines
	add al, cl  ; Et on ajoute les unités	
	cmp al, 0
	je release ; On a lu 0, on arrete.
	ret
endp LIRENT

;*------------------------------------------------------------------------
;*SOUS-PROGRAMME       ECRIRENT
;*------------------------------------------------------------------------
;*SPECIFICATION
;*   convertit une valeur binaire <=99 en base 10, et affiche le resultat
;*   a l'ecran. Cette valeur est supposee etre <=99
;*
;*PASSAGE DES PARAMETRES
;*   ENTREE : AL = valeur a afficher en base 2
;*-------------------------------------------------------------------------
proc ECRIRENT
	mov ah, 02h
	mov cx, 0
sub_ten:
	cmp al, 10d  ; Si on est déjà inférieur à 10, on peut afficher 
	jl done

	sub al, 10d ; On retire 10 à AL
	add cl, 1d
	jmp sub_ten
done:
	add al, 30h ; On retrouve les caractères ASCII
	add cl, 30h ; pour chaque chiffre
	mov dl, cl
	int 21h
	mov dl, al ; ?????????????
	int 21h    ; Modifie les données dans al quand il est appelé, ce qui fausse le PGCD.
	ret
endp ECRIRENT

;*---------------------------------------------------------------------------
;*SOUS-PROGRAMME      PGCD
;*
;*---------------------------------------------------------------------------
;*SPECIFICATION
;*   calcule le PGCD de deux entiers >0
;*
;*PASSAGE DES PARAMETRES
;*   ENTREE : AL = entier n1
;*            BL = entier n2
;*
;*   RESULTAT : CL = pgcd(n1,n2)
;*---------------------------------------------------------------------------
proc PGCD
	cmp al, bl     ; Si v est supérieur à u, on ne compare pas.
	jg pgcd_loop
	;--------------------------------------------------------------------------
	; On n'a pas jump, on doit donc inverser bx et cx pour calculer le pgcd
	mov dl, bl
	mov bl, al
	mov al, dl
	
	sub al, bl
pgcd_loop:
	mov cl, bl     ;
	sub dl, cl     ;
	cmp dx, 0      ; On vérifie si la soustraction serait égale à zéro.
	               ; Si oui, on se rend directement à la fin
	je done_with_pgcd

	sub al, bl
	mov cl, al
	jmp pgcd_loop       ; Et on recommence.
done_with_pgcd:
	ret
endp PGCD
begin:
	mov ax, @data
	mov ds, ax

	mov ah, 01h ; Preparation pour lecture de caractères

start:
	;--------------------------------------------------------------------------
	; Lecture du premier entier
	call lirent
	mov dx, ax

	;--------------------------------------------------------------------------
	; Lecture du deuxieme entier
	call lirent

	;--------------------------------------------------------------------------
	; On a maintenant nos deux nombres, on peut calculer le PGCD
	mov bl, dl

	;--------------------------------------------------------------------------
	; Début du calcul du PGCD
	call pgcd

finalize:
	;--------------------------------------------------------------------------
	; Affichage du PGCD

	mov ah, 02h
	mov dl, 50h
	int 21h
	mov dl, 47h
	int 21h
	mov dl, 43h
	int 21h
	mov dl, 44h
	int 21h
	mov dl, 3ah
	int 21h
	mov dl, 20h
	int 21h

	; On à juste affiché PGCD: pour l'instant. wurf.
	; Le PGCD est dans bx pour l'instant. On doit extraire chaque chiffre, trouver son code ascii et l'afficher
	mov al, cl
	call ECRIRENT
	jmp start; Et on recommence.
	
release:
	mov ax, 4c00h
	int 21h
	end begin


;======================================================================
; Tests effectués: 
; Calcul du PGCD de deux nombres
;  * Le résultat en mémoire est bon
;  * Il y a une erreur dans ECRIRENT qui modifie al et empêche l'affichage correct des valeurs
;    Je ne sais pas d'ou ça vient, al est modifié lors d'un mov dl, al.
;  Essayé avec 24 et 48, 10 et 20, etc.
; S'arrète bien lorsque 00 est rentré.
;
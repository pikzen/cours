	.model small
	.stack
	.data
param_u dw 60
param_v dw 18

;
; PGCD(u,v) = | PGCD (v, u % v)		si v > 0
;             | u                   si v = 0
;
	.code 
begin:
	mov ax, @data
	mov ds, ax     ; Initialisation
	mov bx, param_u; 
	mov cx, param_v;	
	cmp bx, cx     ; Si v est supérieur à u, on ne compare pas.
	jl ret_vzero
	sub bx, cx
pgcd:
	mov dx, bx     ;
	sub dx, cx     ;
	cmp dx, 0      ; On vérifie si la soustraction serait égale à zéro.
	               ; Si oui, on se rend directement à la fin
	je ret_vzero

	sub bx, cx
	mov cx, dx
	jmp pgcd       ; Et on recommence.

ret_vzero:
	mov dx, bx     ; DEBUG: affichage du PGCD;
	mov ax, 0

	mov ax, 4c00h
	int 21h
	end begin

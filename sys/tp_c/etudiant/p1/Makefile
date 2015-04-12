# petit tutoriel : http://perso.univ-rennes1.fr/jean-christophe.engel/make

#------------------------------------------------------------------------
# les variables
#------------------------------------------------------------------------

# compilateur C
CC	 = gcc

# options de compilation
CFLAGS   = -ggdb -Wall -std=c99

# options d'édition de liens
LDFLAGS  = 

# les programmes exécutables à fabriquer (à compléter)
PROGS	= ptrfn_v1 ptrfn_v2 dynload_v1 dynload_v2

all : $(PROGS)

# 1. ptrfn_v1 et ptrfn_v2 : règles implicites

# 2. utiliser une bibliothèque chargée dynamiquement (libm.so)
dynload_v1 : dynload_v1.o
	$(CC) $(LDFLAGS) -o $@ $< -ldl

dynload_v2: dynload_v2.o
	$(CC) $(LDFLAGS) -o $@ $< -ldl

dynload_v2.o: dynload_v2.c
	$(CC) -c $(CFLAGS) $< -o $@

# 3. fabriquer une bibliothèque chargée dynamiquement
calcul.o : calcul.c afficher.h
	$(CC) -c $(CFLAGS) -fPIC $< -o $@

libcalcul.so : calcul.o
	$(CC) -shared -o $@ $<

main_calcul.o: main_calcul.c
	$(CC) -c $(CFLAGS) $< -o $@

main_calcul : main_calcul.o libcalcul.so
	$(CC) $(LDFLAGS) -o $@ $< -ldl

# 3. deuxième version
calcul_v2.o: calcul_v2.c afficher.h main_calcul_v2.o
	$(CC) -c $(CFLAGS) -fPIC $< -o $@ -rdynamic

libcalcul_v2.so: calcul_v2.o
	$(CC) -shared -o $@ $< -rdynamic

main_calcul_v2.o: main_calcul_v2.c
	$(CC) -c $(CFLAGS) -ldl -lc $< -o $@ -rdynamic

main_calcul_v2: main_calcul_v2.o libcalcul_v2.so
	$(CC) $(LDFLAGS) -o $@ $< -ldl -rdynamic

# divers
.PHONY : clean

clean:
	-@rm *.o *~ $(PROGS)

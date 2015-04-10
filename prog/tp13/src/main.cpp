/*
 * main.cpp
 *
 *  Created on: 8 mars 2013
 *      Author: engel
 */

#include "constantes.h"
#include "enregistreur_fichier.h"
#include "enregistreur_fichier_texte.h"
#include "harmonique.h"
#include "signal_constant.h"
#include "multiplicateur.h"
#include "operation_binaire.h"
#include "volume.h"
#include "filtre_compose.h"
#include "volume_compose.h"
#include <functional>

void
q2_signal_constant() {
  signal_constant sc(0.5);
  enregistreur_fichier_texte enr("02_sc.txt", 1);
  enr.connecterEntree(sc.getSortie(0), 0);
  // générer 5 valeurs
  for (unsigned int i = 0; i < 5; ++i) {
    sc.calculer();
    enr.calculer();
  }
}

void q7_harmonique() {
  harmonique h(440);					// la 440Hz
  enregistreur_fichier enr("07_harmonique.raw", 1);	// fichier mono
  enr.connecterEntree(h.getSortie(0), 0);
  // produire 2 secondes de son
  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
    h.calculer();
    enr.calculer();
  }
}

void q9_multiplicateur() {
    harmonique h1(440);
    harmonique h2(880);
    multiplicateur mul;
    mul.connecterEntree(h1.getSortie(0), 0);
    mul.connecterEntree(h2.getSortie(0), 1);

    enregistreur_fichier enr("09_mult.raw", 1);
    enr.connecterEntree(mul.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
    {
        h1.calculer();
        h2.calculer();
        mul.calculer();
        enr.calculer();
    }
}

void q10_op() {
    harmonique h1(440);
    harmonique h2(880);
    std::multiplies<double> mul_functor;
    operation_binaire< std::multiplies<double> > mul(mul_functor);
    mul.connecterEntree(h1.getSortie(0), 0);
    mul.connecterEntree(h2.getSortie(0), 1);

    enregistreur_fichier enr("10_mult.raw", 1);
    enr.connecterEntree(mul.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
    {
        h1.calculer();
        h2.calculer();
        mul.calculer();
        enr.calculer();
    }
}

void q12_vol() {
    harmonique h1(110);
    volume     vol(0.5);
    vol.connecterEntree(h1.getSortie(0), 0);

    enregistreur_fichier enr("12_vol.raw", 1);
    enr.connecterEntree(vol.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
    {
        h1.calculer();
        vol.calculer();
        enr.calculer();
    }
}

void q13_compose() {
    harmonique h1(110);
    volume_compose vol(0.5);
    vol.connecterEntree(h1.getSortie(0), 0);

    enregistreur_fichier enr("13_vol.raw", 1);
    enr.connecterEntree(vol.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
    {
        h1.calculer();
        vol.calculer();
        enr.calculer();
    }
}

void q12_vol_noreduce() {
    harmonique h1(110);
    volume     vol(1);
    vol.connecterEntree(h1.getSortie(0), 0);

    enregistreur_fichier enr("12_vol_noreduce.raw", 1);
    enr.connecterEntree(vol.getSortie(0), 0);

    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
    {
        h1.calculer();
        vol.calculer();
        enr.calculer();
    }
}


int
main() {
  q2_signal_constant();
  q7_harmonique();
  q9_multiplicateur();
  q10_op();
  q12_vol();
  q12_vol_noreduce();
  q13_compose();
  return 0;
}

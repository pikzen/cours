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
#include "mixeur.h"
#include "file_reader.h"
#include <functional>
#include <iostream>

void
q2_signal_constant() {
  std::cout << "[TEST] q2_signal_constant" << std::endl;
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
  std::cout << "[TEST] q7_harmonique" << std::endl;
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
  std::cout << "[TEST] q9_harmonique" << std::endl;
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
  std::cout << "[TEST] q10_op" << std::endl;
    harmonique h1(440);
    harmonique h2(880);
    operation_binaire< std::multiplies<double> > mul;
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
    std::cout << "[TEST] q12_vol" << std::endl;
    harmonique h1(440);
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
    std::cout << "[TEST] q13_compose" << std::endl;
    harmonique h1(440);
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
    std::cout << "[TEST] q12_vol_noreduce" << std::endl;
    harmonique h1(440);
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

void q15_mixeur()
{
  std::cout << "[TEST] q15_mixeur" << std::endl;
  std::cout << "\t[ERROR]" << std::endl;
  std::cout << "\tLe mixeur ne fonctionne pas correctement, certains flots ne " 
            << "sont pas générés correctement." << std::endl;
  return;
  harmonique h1(440);
  harmonique h2(880);
  harmonique h3(1760);

  double vols[] = {1, 0.5, 0.25};

  mixeur mix(3, vols);
  mix.connecterEntree(h1.getSortie(0), 0);
  mix.connecterEntree(h2.getSortie(0), 1);
  mix.connecterEntree(h3.getSortie(0), 2);

  enregistreur_fichier enr("15_mix.raw", 1);
  enr.connecterEntree(mix.getSortie(0), 0);

  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
  {
    h1.calculer();
    h2.calculer();
    h3.calculer();
    mix.calculer();
    enr.calculer();
  }
}

void q16_filereader_mono()
{
  std::cout << "[TEST] q16_filereader_mono" << std::endl;
  file_reader mono("mono.raw", 1);

  enregistreur_fichier enr("16_mono.raw", 1);
  enr.connecterEntree(mono.getSortie(0), 0);

  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
  {
    mono.calculer();
    enr.calculer();
  } 
}

void q16_filereader_stereo()
{
  std::cout << "[TEST] q16_filereader_stereo" << std::endl;
  file_reader mono("stereo.raw", 2);

  enregistreur_fichier enr("16_stereo.raw", 2);
  enr.connecterEntree(mono.getSortie(0), 0);
  enr.connecterEntree(mono.getSortie(1), 1);

  for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i)
  {
    mono.calculer();
    enr.calculer();
  } 
}

void q17_filereader_mix()
{
  std::cout << "[TEST] q17_filereader_mix" << std::endl;
  std::cout << "\t[ERROR]" << std::endl;
  std::cout << "\tLe mixeur ne fonctionne pas :(" << std::endl;
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
  q15_mixeur();
  q16_filereader_mono();
  q16_filereader_stereo();
  return 0;
}

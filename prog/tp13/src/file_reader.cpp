#include "file_reader.h"
#include "composant_exception.h"
#include <climits>

/**
* Lit un fichier et fournit son contenu sous forme de flot
* filename est le nom du fichier à lire
* canals est le nombre de canaux du fichier (1: mono, 2: stereo)
*/
file_reader::file_reader(char* filename, unsigned int canals) : 
	producteur_base(canals),
	m_handle(filename),
	m_canals(canals)
{
	// On vérifie l'intégrité du handle
	if (m_handle.eof())
		throw composant_exception("Impossible d'ouvrir le fichier (ou fichier vide)");
	if (m_handle.fail())
		throw composant_exception("Failbit/Badbit set.");
}

void file_reader::calculer()
{
	// On revérifie l'intégrité du handle
	if (!m_handle.good())
		throw composant_exception("Erreur de lecture du fichier");
	if (m_handle.eof())
		throw composant_exception("Fin du fichier atteint (le fichier est peut être vide.");

	for (unsigned int i = 0; i < m_canals; i++)
	{
		short data = 0;
		// Instant magie noire. On caste data en char* puisque les donnees à
		// l'intérieur du fichier sont lus en tant que caractères par ifstream
		m_handle.read((char*)&data, sizeof(short)); 

		// On convertit la donnée lue vers un double entre -1 et 1
		double dataConverted = (double)data / (double)SHRT_MAX;

		// On insere dans le canal approprié.
		m_output[i]->inserer(dataConverted);
	}
}
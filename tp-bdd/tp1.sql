-- =========================================================================
-- =                                                                       =
-- =                               TP1                                     =
-- =                                                                       =
-- =========================================================================
-------------------------------------------------------------------------------
-- Drop tables in case they're already there
-------------------------------------------------------------------------------
DROP TABLE Enseignement; -- Holds foreign keys on etudiant & professeur, delete
DROP TABLE Professeur;   -- first.
DROP TABLE Etudiant;

-------------------------------------------------------------------------------
-- Create tables
-------------------------------------------------------------------------------
CREATE TABLE Etudiant (
		etudId  INTEGER PRIMARY KEY,
		prenom  TEXT    NOT NULL,
		address TEXT    NOT NULL
);

CREATE TABLE Professeur (
		profID  INTEGER PRIMARY KEY,
		nom     TEXT    NOT NULL,
		prenom  TEXT    NOT NULL
);

CREATE TABLE Enseignement (
		ensId   INTEGER PRIMARY KEY,
		sujet   TEXT    NOT NULL,
		etudId  INTEGER REFERENCES Etudiant(etudId),
		profId  INTEGER REFERENCES Professeur(profIf)
);

-------------------------------------------------------------------------------
-- Insert data
-------------------------------------------------------------------------------
INSERT INTO Etudiant (prenom, address) 
       VALUES ("Bob", "Chez lui"),        -- ID: 0
              ("Gérard", "Chez moi"),     -- ID: 1
		      ("Jean", "Bonne question"), -- ID: 2
		      ("Georges", "ESIR");        -- ID: 3

INSERT INTO Professeur (nom, prenom) 
       VALUES ("Bob", "Ross"),            -- ID: 0
              ("Eric", "Clapton"),        -- ID: 1
		      ("Stevie", "Wonder");       -- ID: 2

INSERT INTO Enseignement (sujet, etudId, profId)
       VALUES ("Base de données", 0, 1),
              ("Base de données", 1, 1),
		      ("Base de données", 2, 1),
		      ("Mathématiques"  , 0, 0),
		      ("Programmation"  , 2, 2),
		      ("Groove"         , 3, 2);

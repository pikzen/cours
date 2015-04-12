-- Question 13
INSERT INTO Jouer(nom-acteur, num-spec)
	VALUES ("Jacques Sentu", 10);

-- Question 14
INSERT INTO Promos(num-spec, titre, prix)
	SELECT num-spec, titre-spec, tarif FROM Representations, Spectacle
	WHERE tarif < 50;

-- Question 15
UPDATE TABLE Representations
	SET tarif = tarif * 1.10;

-- Question 16
UPDATE TABLE Representations
	SET heure = "15h00"
	WHERE date = "17 octobre 2011";

-- Question 17
DELETE FROM Representations
	WHERE date < today();



-- +-----+-----+-----+-----+-----+-----+
-- |  A  |  B  |  C  |  D  |  E  |  F  |
-- +-----+-----+-----+-----+-----+-----+
-- |     |  1  |     | 110 |     |  54 |
-- +-----+-----+-----+-----+-----+-----+
-- |  x  |  2  |  J  | 100 |  n  |  52 |
-- +-----+-----+-----+-----+-----+-----+
-- |  w  |  1  |  I  | 110 |  m  |     |
-- +-----+-----+-----+-----+-----+-----+
-- |     |  2  |     | 100 |     |     |
-- +-----+-----+-----+-----+-----+-----+

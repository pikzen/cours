-- Trouver les noms des produits originaires de Dijon
SELECT nom_p 
		FROM Produit
		WHERE origine = "Dijon";

-- Trouver les noms et numéros des fournisseurs de salade
SELECT Fournisseur.f, Fournisseur.nom_f
		FROM Fournisseur, Produit, Fourniture
		WHERE Fournisseur.f = Fourniture.f AND Produit.p = Fourniture.p AND 
		      Produit.nom_p = "salade";

-- Trouver les noméros des produits qui sont fournis par un fournisseur parisien
SELECT Produit.p
		FROM Produit, Fournisseur, Fourniture
		WHERE Fournisseur.f = Fourniture.f AND Produit.p = Fourniture.p AND 
		      Fournisseur.ville = "Paris";

-- Trouver les noms et les remises consenties par des fournisseurs qui fournissent au moins un produit de Dijon
SELECT Fournisseur.nom_f, Fournisseur.remise
		FROM Produit, Fournisseur, Fourniture
		WHERE Fournisseur.f = Fourniture.f AND Produit.p = Fourniture.p AND 
		      Produit.origine = "Dijon"
		GROUP BY Fournisseur.nom_f;

-- Trouver les noms des produits que fournit Bornibus en quantité inférieure à 5
SELECT Produit.nom_p
		FROM Produit, Fournisseur, Fourniture
		WHERE Fournisseur.f = Fourniture.f AND Produit.p = Fourniture.p AND
		      Fournisseur.nom_f = "Bornibus" 

---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
SELECT nom_f, ville
				FROM Fournisseur, Produit, Fourniture
				WHERE Fourniture.f = Fournisseur.f 


-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
T_f(F x_f Ft x_p P) \ T_f(6_Fville != P.origine (F x_f Ft x_p P))


-- 6
T_f,p (F_t) / T_p (6P.origine = F.ville(F x Ft x P))

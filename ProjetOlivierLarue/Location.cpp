// But:Écrire un programme pour calculer le montant qu’un individu devra débourser pour faire un voyage dans une
//automobile louée.L’algorithme tient compte du kilométrage parcouru et de la durée du voyage qui sont
//soumises par le requérant
//Auteur: Olivier Larue
//Date: 2020-09-17


#include <iostream>
 


int main()
{
	setlocale(LC_ALL, "");

	// définir les variables. 

	int kmTotal;
	int jour;
	float coutTotal;    // Défini la variable en float puisque c'est de l'argent donc une valeur à virgule
	int kmGratuit;
	int kmPayant ; 
	float litreEssence;  // puisque pour 100km on a 7.6L, c'est une variable à virgule donc float
	float coutEssence;  // Défini la variable en float puisque c'est de l'argent donc une valeur à virgule

	std::cout << "Veuillez entrer la durée du voyage en nombre de jours: "; // même processus ici mais avec la variable jour.
	std::cin >> jour;
	if (jour < 1)
	{
		std::cout << "ERREUR: Veuillez entrer un nombre de jour positif."; // je ne peux pas avoir un nombre de jour de location négatif c'est impossible de louer pour -1 jounrée, donc ERREUR
	}
	if (jour < 1)
	{
		return 0;
	}

	// On demande à l'utilisateur d'indiquer le kilométrage parcouru.
	std::cout << "veuillez entrer le kilométrage parcouru: ";
	std::cin >> kmTotal;                // Le programme prend en compte la valeur entrée et l'identifie à la variable kmTotal

	if (kmTotal < 0)
	{
		std::cout << "ERREUR: Veuillez entrer un nombre de kilomètre positif."; // Il est impossible de parcourir des kilomètre négativement, on ne peut pas parcourir moins de kilomètre, donc ERREUR
	}
	if (kmTotal < 0)
	{
		return 0;
	}
		

	coutTotal = 45 * jour;  // Défini le cout par jour soit 45$ * le nombre de jour 
	kmGratuit = 250 * jour; // Défini le nombre de kilomètre gratuit soit 250km * le nombre de jour 

	if (kmTotal > kmGratuit)  // SI kmTotal est plus grand que kmGratuit je peux les soustraires pour obtenir le nombre de kmPayant
	{
		kmPayant = kmTotal - kmGratuit;   //Pour définir les kilomètres payant je dois déduire les kilomètres totals de ceux qui sont gratuit.
	}
	else
	{
		kmPayant = 0;   // si mon kmGratuit est plus grand que kmTotal, soit l'opposé de mon if plus haut, mon kmPayant sera alors de valeur 0
	}
	std::cout << "Voici le nombre de kilomètre supplémentaire que vous devez payer : " << kmPayant << std::endl;  // montrer à l'utilisateur le nombre de kilomètre supplémentaire qu'il va devoir payer
	
	litreEssence = 7.6 * kmTotal / 100;  // Ici je sais que 7.6L = 100km donc je dois diviser la multiplication de 7.6L et les kilomètres totaux par 100 pour savoir le nombre de litre d'essence que l'utlisateur à consommé
	coutEssence = litreEssence * 1.25;   // Pour définir le cout d'essence je dois multiplier le nombre de litre obtenue avec litreEssence par 1.25 (1L = 1.25$)
	coutTotal = coutTotal + 0.05 * kmPayant + coutEssence; // pour savoir mon cout total j'aditionne ensemble le cout des Kilomètre supplémentaire (kmPayant) avec le cout de location par jour et le cout de l'essence 

	std::cout << "Voici le nombre de litre d'essence que vous avez utilisé: " << litreEssence << std::endl; //Montre à l'utilisateur la quantité d'essence il a utilisé

	std::cout << "Voice le prix de l'essence: " << coutEssence << std::endl; // montre à l'utilisateur le prix lié au nombre de litre d'essence utilisé
	
	std::cout << "Votre cout total est de :" << coutTotal;  // montre à l'utilisateur le cout total.


	return 0;
}

/*Tests
* jour      kilomètre parcouru                 kilomètre supplémentaire à payer           litre d'essence         cout total
  1 (45$)           250                                  0     (0$)                          19  (23.75$)              68.75 
  2 (90$)          600                                      100   (5$)                         45.6  (57$)              152
  -1 ERREUR       -200 ERREUR
  25 (1 125$)     10 000                                 3 750 (187.50$)                       760 (950$)            2262.50
  0   ERREUR
  1  (45            0                                        0                                     0                     45
*/
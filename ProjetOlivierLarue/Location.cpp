// But:�crire un programme pour calculer le montant qu�un individu devra d�bourser pour faire un voyage dans une
//automobile lou�e.L�algorithme tient compte du kilom�trage parcouru et de la dur�e du voyage qui sont
//soumises par le requ�rant
//Auteur: Olivier Larue
//Date: 2020-09-17


#include <iostream>
 


int main()
{
	setlocale(LC_ALL, "");

	// d�finir les variables. 

	int kmTotal;
	int jour;
	float coutTotal;    // D�fini la variable en float puisque c'est de l'argent donc une valeur � virgule
	int kmGratuit;
	int kmPayant ; 
	float litreEssence;  // puisque pour 100km on a 7.6L, c'est une variable � virgule donc float
	float coutEssence;  // D�fini la variable en float puisque c'est de l'argent donc une valeur � virgule

	std::cout << "Veuillez entrer la dur�e du voyage en nombre de jours: "; // m�me processus ici mais avec la variable jour.
	std::cin >> jour;
	if (jour < 1)
	{
		std::cout << "ERREUR: Veuillez entrer un nombre de jour positif."; // je ne peux pas avoir un nombre de jour de location n�gatif c'est impossible de louer pour -1 jounr�e, donc ERREUR
	}
	if (jour < 1)
	{
		return 0;
	}

	// On demande � l'utilisateur d'indiquer le kilom�trage parcouru.
	std::cout << "veuillez entrer le kilom�trage parcouru: ";
	std::cin >> kmTotal;                // Le programme prend en compte la valeur entr�e et l'identifie � la variable kmTotal

	if (kmTotal < 0)
	{
		std::cout << "ERREUR: Veuillez entrer un nombre de kilom�tre positif."; // Il est impossible de parcourir des kilom�tre n�gativement, on ne peut pas parcourir moins de kilom�tre, donc ERREUR
	}
	if (kmTotal < 0)
	{
		return 0;
	}
		

	coutTotal = 45 * jour;  // D�fini le cout par jour soit 45$ * le nombre de jour 
	kmGratuit = 250 * jour; // D�fini le nombre de kilom�tre gratuit soit 250km * le nombre de jour 

	if (kmTotal > kmGratuit)  // SI kmTotal est plus grand que kmGratuit je peux les soustraires pour obtenir le nombre de kmPayant
	{
		kmPayant = kmTotal - kmGratuit;   //Pour d�finir les kilom�tres payant je dois d�duire les kilom�tres totals de ceux qui sont gratuit.
	}
	else
	{
		kmPayant = 0;   // si mon kmGratuit est plus grand que kmTotal, soit l'oppos� de mon if plus haut, mon kmPayant sera alors de valeur 0
	}
	std::cout << "Voici le nombre de kilom�tre suppl�mentaire que vous devez payer : " << kmPayant << std::endl;  // montrer � l'utilisateur le nombre de kilom�tre suppl�mentaire qu'il va devoir payer
	
	litreEssence = 7.6 * kmTotal / 100;  // Ici je sais que 7.6L = 100km donc je dois diviser la multiplication de 7.6L et les kilom�tres totaux par 100 pour savoir le nombre de litre d'essence que l'utlisateur � consomm�
	coutEssence = litreEssence * 1.25;   // Pour d�finir le cout d'essence je dois multiplier le nombre de litre obtenue avec litreEssence par 1.25 (1L = 1.25$)
	coutTotal = coutTotal + 0.05 * kmPayant + coutEssence; // pour savoir mon cout total j'aditionne ensemble le cout des Kilom�tre suppl�mentaire (kmPayant) avec le cout de location par jour et le cout de l'essence 

	std::cout << "Voici le nombre de litre d'essence que vous avez utilis�: " << litreEssence << std::endl; //Montre � l'utilisateur la quantit� d'essence il a utilis�

	std::cout << "Voice le prix de l'essence: " << coutEssence << std::endl; // montre � l'utilisateur le prix li� au nombre de litre d'essence utilis�
	
	std::cout << "Votre cout total est de :" << coutTotal;  // montre � l'utilisateur le cout total.


	return 0;
}

/*Tests
* jour      kilom�tre parcouru                 kilom�tre suppl�mentaire � payer           litre d'essence         cout total
  1 (45$)           250                                  0     (0$)                          19  (23.75$)              68.75 
  2 (90$)          600                                      100   (5$)                         45.6  (57$)              152
  -1 ERREUR       -200 ERREUR
  25 (1 125$)     10 000                                 3 750 (187.50$)                       760 (950$)            2262.50
  0   ERREUR
  1  (45            0                                        0                                     0                     45
*/
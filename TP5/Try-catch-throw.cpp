#include <iostream>

using namespace std;

/*Écrire un programme qui permet à l’utilisateur de rentrer une valeur impaire 

positive oddValue depuis son clavier et qui retourne la somme des entiers 

naturels impairs de 1 jusqu’à oddValue inclus. Ce programme doit être 

accompagné d’une gestion d’erreur comme dans le cours.

Vous pouvez vous appuyer sur le code suivant pour commencer.*/

int sumOddNumbersUpTo(int oddValue) {
    int somme = 0;
    if (oddValue%2 == 0)
    throw(invalid_argument("Le nombre rentré ne peut être un nombre impair"));

    else if (oddValue<0)
    throw(invalid_argument("Le nombre rentré ne peut être un nombre négatif"));
    
    else for (size_t i = 1; i <= oddValue; i+=2)somme+=i;
    
    return somme;
}

int main() {
    int entreUtilisateur = 0;

    cout << "Veuillez entrez un nombre impair strictement positive" << endl;
    cin >> entreUtilisateur;
    
    int resultat = sumOddNumbersUpTo(entreUtilisateur);
    cout << "Voici le résultat du calcul " << resultat  << endl;

    try
    {
        sumOddNumbersUpTo(entreUtilisateur);
    }
    catch(invalid_argument& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}
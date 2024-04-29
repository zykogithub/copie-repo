#include <iostream>
using namespace std;

bool peut_boire_alcool(int âgeUtilisateur, float prixUtilisateur) {
	const int âgeLegal = 18;
	const int prixMoyenParis = 7;
    if (âgeUtilisateur >= âgeLegal && prixUtilisateur >= prixMoyenParis) {
        return true;
    }
    return false;
}

int main() {

    int monAge;
    float argentQueJai;

    cout << "Enter your age: ";
    cin >> monAge;

    cout << "Enter the amount of money you have: ";
    cin >> argentQueJai;
    bool aLaPossibiliteDeBoire = peut_boire_alcool(monAge,argentQueJai);
    if (aLaPossibiliteDeBoire) {
        cout << "You can buy beer!" << endl;
    } else {
        cout << "Sorry, you cannot buy beer." << endl;
    }
    return 0;
}

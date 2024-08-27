#include <iostream> 

int main() {
    double nombre1, nombre2;
    std::cout << "Entrez le premier nombre : ";
    std::cin >> nombre1;
    std::cout << "Entrez le deuxième nombre : ";
    std::cin >> nombre2;
    double produit = nombre1 * nombre2;
    std::cout << "Le produit de " << nombre1 << " et " << nombre2 << " est : " << produit << std::endl;
    return 0;
}

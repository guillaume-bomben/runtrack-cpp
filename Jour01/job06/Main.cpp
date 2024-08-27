#include <iostream> 

int main() {
    double prixHT, nombreKilos, tauxTVA; 
    std::cout << "Entrez le prix HT d'un kilo de carottes : ";
    std::cin >> prixHT;
    std::cout << "Entrez le nombre de kilos de carottes : ";
    std::cin >> nombreKilos;
    std::cout << "Entrez le taux de TVA (exemple : 15 pour 15%) : ";
    std::cin >> tauxTVA;
    double prixTotalHT = prixHT * nombreKilos;  
    double prixTTC = prixTotalHT * (1 + tauxTVA / 100);  
    std::cout << "Le prix TTC de " << nombreKilos << " kilos de carottes est : " << prixTTC << " euros." << std::endl;
    return 0; 
}

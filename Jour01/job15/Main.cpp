#include <iostream>  

bool estBitsPair(unsigned int nombre) {
    unsigned int bits = nombre;
    bits = bits ^ (bits >> 1);
    bits = bits ^ (bits >> 2);
    bits = bits ^ (bits >> 4);
    bits = bits ^ (bits >> 8);
    bits = bits ^ (bits >> 16);
    return !(bits & 1);  
}

int main() {
    unsigned int nombre;
    std::cout << "Entrez un nombre non-signé de 32 bits : ";
    std::cin >> nombre;
    if (estBitsPair(nombre)) {
        std::cout << "Le nombre de bits à 1 dans " << nombre << " est pair." << std::endl;
    } else {
        std::cout << "Le nombre de bits à 1 dans " << nombre << " est impair." << std::endl;
    }
    return 0; 
}

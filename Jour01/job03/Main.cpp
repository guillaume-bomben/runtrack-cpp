#include <iostream>

int main() {
    int nombre;  
    int somme = 0;  

    for (int i = 0; i < 5; ++i) {
        std::cout << "Entrez un entier (" << i + 1 << "/5) : ";
        std::cin >> nombre;
        somme += nombre;  
    }
    double moyenne = static_cast<double>(somme) / 5;
    std::cout << "La moyenne des cinq entiers est : " << moyenne << std::endl;
    return 0; 
}

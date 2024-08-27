#include <iostream> 

int main() {
    int N; 
    int somme = 0;  
    std::cout << "Entrez un entier N : ";
    std::cin >> N;
    if (N < 5) {
        std::cout << "N doit être au moins 5." << std::endl;
        return 1;
    }
    for (int i = 5; i <= N; ++i) {
        somme += i * i * i;  
    }
    std::cout << "La somme des cubes des entiers de 5 à " << N << " est : " << somme << std::endl;
    return 0;  
}

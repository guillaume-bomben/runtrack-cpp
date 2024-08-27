#include <iostream> 

int trouverPlusPetit(int** tableau, int taille) {
    int min = **tableau;  
    for (int i = 1; i < taille; i++) {
        if (*tableau[i] < min) {  
            min = *tableau[i];  
        }
    }
    return min; 
}

int main() {
    int a = 12, b = 3, c = 7, d = 15, e = 9, f = 2, g = 11;
    int* tableau[] = {&a, &b, &c, &d, &e, &f, &g};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int plusPetit = trouverPlusPetit(tableau, taille);
    std::cout << "Le plus petit élément du tableau est : " << plusPetit << std::endl;
    return 0; 
}
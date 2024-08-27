#include <iostream>  

int trouverPlusPetit(int* tableau, int taille) {
    int min = *tableau; 
    for (int i = 1; i < taille; i++) {
        if (*(tableau + i) < min) {  
            min = *(tableau + i);  
        }
    }
    return min;  
}

int main() {
    int tableau[] = {12, 3, 7, 15, 9, 2, 11};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int plusPetit = trouverPlusPetit(tableau, taille);
    std::cout << "Le plus petit élément du tableau est : " << plusPetit << std::endl;
    return 0;  
}

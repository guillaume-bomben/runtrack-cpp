#include <iostream> 

void swapValues(int& a, int& b) {
    int temp = a; 
    a = b;         
    b = temp;     
}

int main() {
    int x, y;  
    std::cout << "Entrez la valeur de x : ";
    std::cin >> x;
    std::cout << "Entrez la valeur de y : ";
    std::cin >> y;
    std::cout << "Avant l'échange : x = " << x << ", y = " << y << std::endl;
    swapValues(x, y);
    std::cout << "Après l'échange : x = " << x << ", y = " << y << std::endl;
    return 0; 
}
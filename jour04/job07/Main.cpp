#include <iostream>

template <typename T>
void print(const T& arg) {
    std::cout << arg << std::endl;
}

template <typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << first << ", ";
    print(args...);  
}

int main() {
    print(1, 2.5, "Hello", 'A');          
    print("Un seul argument");           
    print(42);                            
    print("Combinaison", 10, true, 3.14); 

    return 0;
}

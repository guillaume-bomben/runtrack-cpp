#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int int1 = 10, int2 = 20;
    double double1 = 15.5, double2 = 10.3;
    char char1 = 'A', char2 = 'Z';

    std::cout << "Max entre " << int1 << " et " << int2 << " est: " << max(int1, int2) << std::endl;
    std::cout << "Max entre " << double1 << " et " << double2 << " est: " << max(double1, double2) << std::endl;
    std::cout << "Max entre '" << char1 << "' et '" << char2 << "' est: '" << max(char1, char2) << "'" << std::endl;

    return 0;
}

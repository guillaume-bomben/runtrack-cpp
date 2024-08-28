#include <iostream>
#include "Pingouin.cpp"

int main() {
    Pingouin p1(3.0, 0.7, 2.0); 

    p1.sePresenter();
    p1.nage();
    p1.marche();
    p1.glisse();

    Pingouin p2 = p1;

    std::cout << "\nCopie du pingouin p1:" << std::endl;
    p2.sePresenter();
    p2.nage();
    p2.marche();
    p2.glisse();

    return 0;
}
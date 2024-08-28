#include <iostream>
#include "Aquatique.cpp"
#include "Terrestre.cpp"

class Pingouin : public Aquatique, public Terrestre {
public:
    Pingouin(double vitesseNage = 2.5, double vitesseMarche = 0.5)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche) {}

    void nage() const override {
        std::cout << "Le pingouin nage avec aisance à une vitesse de " << vitesseNage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << "Le pingouin marche maladroitement à une vitesse de " << vitesseMarche << " m/s." << std::endl;
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis un pingouin ! Je peux nager et marcher." << std::endl;
    }
};
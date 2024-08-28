#include <iostream>
#include "Aquatique.cpp"
#include "Terrestre.cpp"

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse; 

public:
    Pingouin(double vitesseNage = 2.5, double vitesseMarche = 0.5, double vitesseGlisse = 1.0)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {}

    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesseNage), Terrestre(other.vitesseMarche), vitesseGlisse(other.vitesseGlisse) {}

    void nage() const override {
        std::cout << "Le pingouin nage avec aisance à une vitesse de " << vitesseNage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << "Le pingouin marche maladroitement à une vitesse de " << vitesseMarche << " m/s." << std::endl;
    }

    void sePresenter() const {
        std::cout << "Bonjour, je suis un pingouin ! Je peux nager, marcher, et glisser." << std::endl;
    }

    void glisse() const {
        std::cout << "Le pingouin glisse rapidement sur la glace à une vitesse de " << vitesseGlisse << " m/s." << std::endl;
    }

    double getVitesseGlisse() const {
        return vitesseGlisse;
    }

    void setVitesseGlisse(double vitesse) {
        vitesseGlisse = vitesse;
    }
};
#include <iostream>

class Terrestre {
protected:
    double vitesseMarche; 

public:
    Terrestre(double vitesseMarche = 0.0) : vitesseMarche(vitesseMarche) {}

    virtual void marche() const {
        std::cout << "L'animal marche à une vitesse de " << vitesseMarche << " m/s." << std::endl;
    }

    double getVitesseMarche() const {
        return vitesseMarche;
    }

    void setVitesseMarche(double vitesse) {
        vitesseMarche = vitesse;
    }
};
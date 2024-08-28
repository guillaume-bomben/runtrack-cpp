#include <iostream>

class Aquatique {
protected:
    double vitesseNage;  

public:
    Aquatique(double vitesseNage = 0.0) : vitesseNage(vitesseNage) {}

    virtual void nage() const {
        std::cout << "L'animal nage à une vitesse de " << vitesseNage << " m/s." << std::endl;
    }

    double getVitesseNage() const {
        return vitesseNage;
    }

    void setVitesseNage(double vitesse) {
        vitesseNage = vitesse;
    }
};
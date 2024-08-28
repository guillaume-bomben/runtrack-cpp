#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> 
#include "Aquatique.cpp"
#include "Terrestre.cpp"

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie; 

    Pingouin(double vitesseNage = 2.5, double vitesseMarche = 0.5, double vitesseGlisse = 1.0)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {
        colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
    }

    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesseNage), Terrestre(other.vitesseMarche), vitesseGlisse(other.vitesseGlisse) {
        colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
    }

    ~Pingouin() {
        auto it = std::find_if(colonie.begin(), colonie.end(), 
                            [this](const std::shared_ptr<Pingouin>& p) { return p.get() == this; });
        if (it != colonie.end()) {
            colonie.erase(it);
        }
    }

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

    double tempsParcoursPiste() const {
        double tempsGlisse = 15 / vitesseGlisse;   
        double tempsMarche1 = 20 / vitesseMarche; 
        double tempsNage = 50 / vitesseNage;       
        double tempsMarche2 = 15 / vitesseMarche; 

        return tempsGlisse + tempsMarche1 + tempsNage + tempsMarche2;
    }

    static void afficherTempsParcoursTousPingouins() {
        for (const auto& pingouin : colonie) {
            std::cout << "Pingouin à l'adresse " << pingouin.get() 
                    << " met " << pingouin->tempsParcoursPiste() << " secondes pour parcourir la piste." << std::endl;
        }
    }

    static void afficherColonie() {
        std::cout << "Il y a actuellement " << colonie.size() << " pingouins dans la colonie." << std::endl;
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;

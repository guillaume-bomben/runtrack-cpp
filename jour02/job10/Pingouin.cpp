#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <string>
#include <functional>
#include <iterator>
#include <iomanip>
#include "Aquatique.cpp"
#include "Terrestre.cpp"

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;
    std::multiset<double> tempsGlisseCompetition; 

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie;
    static std::list<std::string> lieuxRencontre;
    static std::map<std::string, int> competences;

    Pingouin(double vitesseNage = 2.5, double vitesseMarche = 0.5, double vitesseGlisse = 1.0)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {
        colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
        trierColonie();
    }

    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesseNage), Terrestre(other.vitesseMarche), vitesseGlisse(other.vitesseGlisse) {
        colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
        trierColonie();
    }

    ~Pingouin() {
        auto it = std::find_if(colonie.begin(), colonie.end(), 
                            [this](const std::shared_ptr<Pingouin>& p) { return p.get() == this; });
        if (it != colonie.end()) {
            colonie.erase(it);
            trierColonie();
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

    static void trierColonie() {
        std::sort(colonie.begin(), colonie.end(), 
                [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
                    return a->tempsParcoursPiste() < b->tempsParcoursPiste();
                });
    }

    static void ajouterLieuRencontre(const std::string& lieu) {
        lieuxRencontre.push_back(lieu);
    }

    static void supprimerLieuRencontre(const std::string& lieu) {
        lieuxRencontre.remove(lieu);
    }

    static void afficherLieuxRencontre() {
        std::cout << "Lieux de rencontre des pingouins :" << std::endl;
        for (const auto& lieu : lieuxRencontre) {
            std::cout << "- " << lieu << std::endl;
        }
    }

    static void ajouterOuModifierCompetence(const std::string& nom, int niveau) {
        competences[nom] = niveau;
    }

    static void supprimerCompetence(const std::string& nom) {
        competences.erase(nom);
    }

    static void afficherCompetences() {
        std::cout << "Compétences des pingouins :" << std::endl;
        for (const auto& paire : competences) {
            std::cout << "Compétence: " << paire.first << " | Niveau: " << paire.second << std::endl;
        }
    }

    void ajouterOuModifierJournal(const std::string& date, const std::string& description) {
        journal[date] = description;
    }

    void supprimerJournal(const std::string& date) {
        journal.erase(date);
    }

    void afficherJournal() const {
        std::cout << "Journal du pingouin à l'adresse " << this << ":" << std::endl;
        for (const auto& entree : journal) {
            std::cout << "Date: " << entree.first << " | Description: " << entree.second << std::endl;
        }
    }

    void ajouterAmi(const std::shared_ptr<Pingouin>& ami) {
        amis.insert(ami);
    }

    void retirerAmi(const std::shared_ptr<Pingouin>& ami) {
        auto it = std::find_if(amis.begin(), amis.end(),
                            [&ami](const std::weak_ptr<Pingouin>& wptr) {
                                if (auto sptr = wptr.lock()) {
                                    return sptr == ami;
                                }
                                return false;
                            });
        if (it != amis.end()) {
            amis.erase(it);
        }
    }

    void afficherAmis() const {
        std::cout << "Amis du pingouin à l'adresse " << this << ":" << std::endl;
        for (const auto& wptr : amis) {
            if (auto sptr = wptr.lock()) {
                std::cout << "- Pingouin à l'adresse " << sptr.get() << std::endl;
            }
        }
    }

    void ajouterTempsGlisse(double temps) {
        tempsGlisseCompetition.insert(temps);
    }

    void afficherTempsGlisse() const {
        std::cout << "Temps de glisse en compétition du pingouin à l'adresse " << this << ":" << std::endl;
        for (const auto& temps : tempsGlisseCompetition) {
            std::cout << "- " << std::fixed << std::setprecision(2) << temps << " secondes" << std::endl;
        }
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;
std::list<std::string> Pingouin::lieuxRencontre;
std::map<std::string, int> Pingouin::competences;

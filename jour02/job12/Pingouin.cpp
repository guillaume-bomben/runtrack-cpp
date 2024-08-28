#include <iostream>         // std::cout, std::endl
#include <vector>           // std::vector
#include <list>             // std::list
#include <map>              // std::map
#include <set>              // std::set, std::multiset
#include <unordered_map>    // std::unordered_map
#include <unordered_set>    // std::unordered_set
#include <memory>           // std::shared_ptr, std::weak_ptr
#include <algorithm>        // std::find_if, std::sort
#include <string>           // std::string
#include <iomanip>          // std::fixed, std::setprecision
#include <cstdlib>          // std::rand
#include <ctime>            // std::time
#include "Aquatique.cpp"
#include "Terrestre.cpp"

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;
    std::multiset<double> tempsGlisseCompetition;
    std::unordered_set<std::string> emplacementsNourriture;

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie;
    static std::list<std::string> lieuxRencontre;
    static std::map<std::string, int> competences;
    static std::unordered_map<std::string, std::string> lieuxMeetupEtPeche; 

    ///////////////////////////////////////////////////////////////////////////
    // constructor --- Copy constructor --- destructor ////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    Pingouin(double vitesseNage = 2.5, double vitesseMarche = 0.5, double vitesseGlisse = 1.0)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), vitesseGlisse(vitesseGlisse) {
        colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
        trierColonie();
        std::srand(static_cast<unsigned>(std::time(0))); 
    }

    Pingouin(const Pingouin& other)
        : Aquatique(other.vitesseNage), Terrestre(other.vitesseMarche), vitesseGlisse(other.vitesseGlisse) {
        colonie.push_back(std::shared_ptr<Pingouin>(this, [](Pingouin*){}));
        trierColonie();
        std::srand(static_cast<unsigned>(std::time(0))); 
    }

    ~Pingouin() {
        auto it = std::find_if(colonie.begin(), colonie.end(), 
                            [this](const std::shared_ptr<Pingouin>& p) { return p.get() == this; });
        if (it != colonie.end()) {
            colonie.erase(it);
            trierColonie();
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // member functions ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

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

    ///////////////////////////////////////////////////////////////////////////
    // geteurs --- seteurs ////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    double getVitesseGlisse() const {
        return vitesseGlisse;
    }

    void setVitesseGlisse(double vitesse) {
        vitesseGlisse = vitesse;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Turnement functions ///////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////////
    // colonie functions /////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    static void afficherColonie() {
        std::cout << "Il y a actuellement " << colonie.size() << " pingouins dans la colonie." << std::endl;
    }

    static void trierColonie() {
        std::sort(colonie.begin(), colonie.end(), 
                [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
                    return a->tempsParcoursPiste() < b->tempsParcoursPiste();
                });
    }

    ///////////////////////////////////////////////////////////////////////////
    // encounter places functions /////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

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

    ///////////////////////////////////////////////////////////////////////////
    // skills functions ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

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

    ///////////////////////////////////////////////////////////////////////////
    // journal functions //////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

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

    ///////////////////////////////////////////////////////////////////////////
    // friends functions /////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

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

    ///////////////////////////////////////////////////////////////////////////
    // competition functions //////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void ajouterTempsGlisse(double temps) {
        tempsGlisseCompetition.insert(temps);
    }

    void afficherTempsGlisse() const {
        std::cout << "Temps de glisse en compétition du pingouin à l'adresse " << this << ":" << std::endl;
        for (const auto& temps : tempsGlisseCompetition) {
            std::cout << "- " << std::fixed << std::setprecision(2) << temps << " secondes" << std::endl;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // food places functions //////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void ajouterEmplacementNourriture(const std::string& emplacement) {
        emplacementsNourriture.insert(emplacement);
    }

    void retirerEmplacementNourriture(const std::string& emplacement) {
        emplacementsNourriture.erase(emplacement);
    }

    void afficherEmplacementsNourriture() const {
        std::cout << "Emplacements de nourriture découverts par le pingouin à l'adresse " << this << ":" << std::endl;
        for (const auto& emplacement : emplacementsNourriture) {
            std::cout << "- " << emplacement << std::endl;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // meetup and fishing places functions ///////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

    void seRendreAuLieuDeMeetup(const std::string& lieu) const {
        auto it = lieuxMeetupEtPeche.find(lieu);
        if (it != lieuxMeetupEtPeche.end()) {
            std::cout << "Le pingouin se rend au lieu de meetup: " << lieu << "." << std::endl;
            std::cout << "Il a une chance de trouver un poisson au lieu de pêche: " << it->second << "." << std::endl;

            // Simuler la chance de trouver un poisson
            if (std::rand() % 2 == 0) {
                std::cout << "Bonne nouvelle ! Un poisson a été trouvé au lieu de pêche." << std::endl;
            } else {
                std::cout << "Pas de poisson trouvé cette fois-ci." << std::endl;
            }
        } else {
            std::cout << "Le lieu de meetup '" << lieu << "' n'est pas enregistré." << std::endl;
        }
    }

    static void ajouterLieuMeetupEtPeche(const std::string& lieuMeetup, const std::string& lieuPeche) {
        lieuxMeetupEtPeche[lieuMeetup] = lieuPeche;
    }

    static void supprimerLieuMeetup(const std::string& lieuMeetup) {
        lieuxMeetupEtPeche.erase(lieuMeetup);
    }

    static void afficherLieuxMeetupEtPeche() {
        std::cout << "Lieux de meetup et lieux de pêche :" << std::endl;
        for (const auto& paire : lieuxMeetupEtPeche) {
            std::cout << "Lieu de meetup: " << paire.first << " | Lieu de pêche: " << paire.second << std::endl;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////
// Static member initialization //////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;
std::list<std::string> Pingouin::lieuxRencontre;
std::map<std::string, int> Pingouin::competences;
std::unordered_map<std::string, std::string> Pingouin::lieuxMeetupEtPeche;

#include <iostream>
#include "Pingouin.cpp"

int main() {
    {
        auto p1 = std::make_shared<Pingouin>(3.0, 0.7, 2.0); 
        p1->sePresenter();
        p1->nage();
        p1->marche();
        p1->glisse();

        auto p2 = std::make_shared<Pingouin>(*p1);

        std::cout << "\nCopie du pingouin p1:" << std::endl;
        p2->sePresenter();
        p2->nage();
        p2->marche();
        p2->glisse();

        Pingouin::afficherColonie();

        Pingouin::afficherTempsParcoursTousPingouins();

        Pingouin::ajouterLieuRencontre("lac");
        Pingouin::ajouterLieuRencontre("glacier");
        Pingouin::ajouterLieuRencontre("banquise");

        Pingouin::afficherLieuxRencontre();

        Pingouin::supprimerLieuRencontre("glacier");

        Pingouin::afficherLieuxRencontre();

        Pingouin::ajouterOuModifierCompetence("Nager", 5);
        Pingouin::ajouterOuModifierCompetence("Glisser", 4);
        Pingouin::ajouterOuModifierCompetence("Marcher", 2);

        Pingouin::afficherCompetences();

        Pingouin::supprimerCompetence("Marcher");

        Pingouin::afficherCompetences();
    } 

    Pingouin::afficherColonie(); 

    return 0;
}

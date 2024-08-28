#include <iostream>
#include "Pingouin.cpp"

int main() {
    auto p1 = std::make_shared<Pingouin>(3.0, 0.7, 2.0);
    auto p2 = std::make_shared<Pingouin>(2.5, 0.6, 1.8);
    auto p3 = std::make_shared<Pingouin>(3.1, 0.8, 2.2);

    p1->sePresenter();
    p1->nage();
    p1->marche();
    p1->glisse();

    p1->ajouterAmi(p2);
    p1->ajouterAmi(p3);
    p1->afficherAmis();

    p1->retirerAmi(p3);
    p1->afficherAmis();

    Pingouin::ajouterOuModifierCompetence("Nager", 5);
    Pingouin::ajouterOuModifierCompetence("Glisser", 4);
    Pingouin::ajouterOuModifierCompetence("Marcher", 2);
    Pingouin::afficherCompetences();

    Pingouin::supprimerCompetence("Marcher");
    Pingouin::afficherCompetences();

    Pingouin::ajouterLieuRencontre("lac");
    Pingouin::ajouterLieuRencontre("glacier");
    Pingouin::ajouterLieuRencontre("banquise");
    Pingouin::afficherLieuxRencontre();

    Pingouin::supprimerLieuRencontre("glacier");
    Pingouin::afficherLieuxRencontre();

    p1->ajouterOuModifierJournal("2024-08-01", "Découverte d'une nouvelle zone de glisse.");
    p1->ajouterOuModifierJournal("2024-08-15", "Rencontre avec un groupe d'autres pingouins.");
    p1->afficherJournal();

    p1->supprimerJournal("2024-08-01");
    p1->afficherJournal();

    Pingouin::afficherTempsParcoursTousPingouins();

    return 0;
}

#include <iostream>
#include "Pingouin.cpp"

int main() {
    Pingouin p1(3.0, 0.7, 2.0);
    Pingouin p2(2.8, 0.6, 1.8);
    Pingouin p3(3.2, 0.8, 2.1);

    p1.ajouterAmi(std::make_shared<Pingouin>(p2));
    p1.ajouterAmi(std::make_shared<Pingouin>(p3));
    p1.afficherAmis();

    p1.retirerAmi(std::make_shared<Pingouin>(p3));
    p1.afficherAmis();

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

    p1.ajouterOuModifierJournal("2024-08-01", "Découverte d'une nouvelle zone de glisse.");
    p1.ajouterOuModifierJournal("2024-08-15", "Rencontre avec un groupe d'autres pingouins.");
    p1.afficherJournal();

    p1.supprimerJournal("2024-08-01");
    p1.afficherJournal();

    p1.ajouterTempsGlisse(12.5);
    p1.ajouterTempsGlisse(11.8);
    p1.ajouterTempsGlisse(13.0);
    p1.afficherTempsGlisse();

    Pingouin::afficherTempsParcoursTousPingouins();

    p1.ajouterEmplacementNourriture("Antarctique");
    p1.ajouterEmplacementNourriture("Océan Atlantique");
    p1.afficherEmplacementsNourriture();

    p1.retirerEmplacementNourriture("Océan Atlantique");
    p1.afficherEmplacementsNourriture();

    Pingouin::ajouterLieuMeetupEtPeche("lac", "zone de pêche 1");
    Pingouin::ajouterLieuMeetupEtPeche("banquise", "zone de pêche 2");
    Pingouin::afficherLieuxMeetupEtPeche();

    p1.seRendreAuLieuDeMeetup("lac");
    p1.seRendreAuLieuDeMeetup("banquise");

    return 0;
}

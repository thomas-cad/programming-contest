#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char S[3001];        
char T[3000001];     

int indice(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';        
    return 26 + (c - 'A');                        
}

int main() {
    int lenS, lenT;
    scanf("%d %d", &lenS, &lenT);
    scanf("%s", S);
    scanf("%s", T);

    if (lenS > lenT) { printf("0\n"); return 0; }

    int cible[52] = {0};
    for (int i = 0; i < lenS; i++) cible[indice(S[i])]++;

    int fenetre[52] = {0};

    // Init
    int nb_correspondances = 0;
    for (int i = 0; i < 52; i++)
        if (cible[i] == fenetre[i]) nb_correspondances++;   // ✓

    int reponse = 0;

    // Fenetre
    for (int droite = 0; droite < lenT; droite++) {
        int e = indice(T[droite]);

        if (fenetre[e] == cible[e]) nb_correspondances--; // On va perdre donc -1
        fenetre[e]++;
        if (fenetre[e] == cible[e]) nb_correspondances++; // On obtient donc +1

        // --- Lettre sortante (à gauche), une fois la fenêtre pleine ---
        int gauche = droite - lenS;   // indice qui sort
        if (gauche >= 0) {
            int s = indice(T[gauche]);
            if (fenetre[s] == cible[s]) nb_correspondances--;
            fenetre[s]--;
            if (fenetre[s] == cible[s]) nb_correspondances++;
        }

        // --- La fenêtre [droite-lenS+1 .. droite] est-elle complète et valide ? ---
        if (droite >= lenS - 1 && nb_correspondances == 52)
            reponse++;
    }

    printf("%d\n", reponse);
    return 0;
}
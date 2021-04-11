#include<bits/stdc++.h>
#include "header.h"

using namespace std;

// Affichage de matrices
int Affiche_matrice(int mat[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
          printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Affichage du chemin de l'état initial à l'état final de l'arbre de décision
void Affiche_Path(Noeud_puzzle* root){
    if (root == NULL){
      return;
    }

    Affiche_Path(root->parent);
    Affiche_matrice(root->mat);

    printf("\n");
}

// Vérification si les Coordonnée (x,y) sont valides
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// bas, gauche, haut, droite
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };



// Ordonée le tas
struct comp
{
    bool operator()(const Noeud_puzzle* lhs, const Noeud_puzzle* rhs) const
    {
        return (lhs->cost + lhs->niveau) > (rhs->cost + rhs->niveau);
    }
};


//Fonction pour calculer le nombre de cases non vierges qui ne sont pas dans leur position finale donnée
int calculateCost(int initiale[N][N], int finale[N][N]){
    int cpt = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if (initiale[i][j] && initiale[i][j] != finale[i][j]){
          cpt++;
        }
      }
    }
    return cpt;
}


// Allocation d'un nouveau noeud
Noeud_puzzle* newNoeud(int mat[N][N], int x, int y, int newX, int newY, int niveau, Noeud_puzzle* parent){

    Noeud_puzzle* noeud = new Noeud_puzzle;

    noeud->parent = parent; // définir le pointeur du chemin vers la racine

    memcpy(noeud->mat, mat, sizeof noeud->mat);  // copier les données du nœud parent vers le nœud actuel

    swap(noeud->mat[x][y], noeud->mat[newX][newY]); // déplacer la case d'une position

    noeud->cost = INT_MAX; // définir le nombre de cases égarées

    noeud->niveau = niveau; // définir le nombre de déplacements jusqu'à présent

    // mettre à jour les nouvelles coordonnées de cases vierges
    noeud->x = newX;
    noeud->y = newY;

    return noeud;
}


// Fonction pour résoudre 8-PUZZLE en utilisant B & B
// Icix et y sont des coordonnées de cases vides à l'état initial
void Puzzle_8(int initial[N][N], int x, int y, int final[N][N]){
    // Creation d'une liste d'attente afin de sauvegarder les noeuds actifs
    priority_queue<Noeud_puzzle*, std::vector<Noeud_puzzle*>, comp> pq;

    // Creation d'un noeud racine et calcul de son coût
    Noeud_puzzle* root = newNoeud(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);

    pq.push(root); // Ajouter à la liste des noeuds en état "LIVE"

    // , ajoute ses enfants à la liste des nœuds actifs et .
    while (!pq.empty()){

        Noeud_puzzle* min = pq.top(); // Recherche un nœud en LIVE avec le moindre coût

        pq.pop(); // Supprime le noeud trouvée de la liste

        // Si min est noeud "Execute"
        if (min->cost == 0)
        {
            // Afficher le chemin de la racine à la destination
            Affiche_Path(min);
            return;
        }

        // On note un maximum de 4 enfants pour un nœud
        // Faire pour chaque enfant de min
        for (int i = 0; i < 4; i++){
            if (isSafe(min->x + row[i], min->y + col[i])){
                // crée un nœud enfant et calcule son coût
                Noeud_puzzle* child = newNoeud(min->mat, min->x,
                                               min->y, min->x + row[i],
                                               min->y + col[i],
                                               min->niveau + 1, min);
                   child->cost = calculateCost(child->mat, final);

                //Ajouter un enfant à la liste des nœuds actifs
                pq.push(child);
            }
        }
    }
}

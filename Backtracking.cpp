#include<bits/stdc++.h>
#include "header.h"

using namespace std;

// Fonction de comparaison pour trier l'article selon le rapport valeur / poids
bool cmp2(struct Item2 a, struct Item2 b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

int bound(Noeud u, int n, int capacity, Item2 sac[])
{
    // si le poids dépasse la capacité du sac à dos, renvoyer 0
    if (u.weight >= capacity)
        return 0;

    // initialiser bound au profit par le profit courant
    int profi_bound = u.profi;

    // commencer à inclure les éléments de l'index 1 de plus à l'index de l'élément actuel
    int j = u.niveau + 1;
    int totweight = u.weight;

    // vérification de l'état de l'index et de l'état de la capacité du sac à dos
    while ((j < n) && (totweight + sac[j].weight <= capacity))
    {
        totweight    += sac[j].weight;
        profi_bound += sac[j].value;
        j++;
    }

    // Si k n'est pas n, inclure partiellement le dernier élément pour la limite supérieure du profit
    if (j < n)
        profi_bound += (capacity - totweight) * sac[j].value / sac[j].weight;

    return profi_bound;
}

// Renvoie le profit maximum que nous pouvons obtenir avec la capacité W
int Backtracking(int capacity, Item2 sac[], int n)
{
    // trier l'article sur la base de la valeur par poids unitaire.
    sort(sac, sac + n, cmp2);

    // faire une file d'attente pour traverser le nœud
    queue<Noeud> Q;
    Noeud u, v;

    // Noeud factice au démarrage
    u.niveau = -1;
    u.profi = u.weight = 0;
    Q.push(u);

    // Un par un, extrayez un élément de l'arbre de décision, calculez le profit de tous les enfants
    // de l'élément extrait et continuez à enregistrer maxProfit
    int profi_max = 0;
    while (!Q.empty())
    {
        // Retirer un nœud de la file d'attente
        u = Q.front();
        Q.pop();

        // S'il s'agit du nœud de départ, attribuez le niveau 0
        if (u.niveau == -1)
            v.niveau = 0;

        // S'il n'y a rien au niveau suivant
        if (u.niveau == n-1)
            continue;

        // Sinon, si ce n'est pas le dernier nœud, puis incrémentez le niveau et calculez le profit des nœuds enfants.
        v.niveau = u.niveau + 1;

        // Prendre l'élément du niveau actuel ajoute le poids et la valeur du niveau actuel au poids et à la valeur du nœud u
        v.weight = u.weight + sac[v.niveau].weight;
        v.profi = u.profi + sac[v.niveau].value;

        // Si le poids cumulé est inférieur à Capacity et que le profit est supérieur au profit précédent, mettez à jour maxprofit
        if (v.weight <= capacity && v.profi > profi_max)
            profi_max = v.profi;

        // Obtenez la limite supérieure du profit pour décider d'ajouter v à Q ou non.
        v.bound = bound(v, n, capacity, sac);

        // Si la valeur liée est supérieure au profit, ne mettez en file d'attente que pour un examen plus approfondi
        if (v.bound > profi_max)
            Q.push(v);

        // Faire la même chose, mais sans prendre l'article dans le sac à dos
        v.weight = u.weight;
        v.profi = u.profi;
        v.bound = bound(v, n, capacity, sac);
        if (v.bound > profi_max)
            Q.push(v);
    }

    return profi_max;
}

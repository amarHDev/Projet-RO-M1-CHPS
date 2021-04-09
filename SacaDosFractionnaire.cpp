#include<iostream>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include<queue>
#include <malloc.h>

#include "header.h"

using namespace std;

// Fonction de comparaison pour trier l'article selon le rapport valeur / poids
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

//Fonction de résolution du problème de Sac à dos  Fractionnaire
double fractionalKnapsack(int capacity, struct Item sac[], int n)
{
    //Trier par rapport au ratio
    sort(sac, sac + n, cmp);

    //    Uncomment to see new order of Items with their ratio
    /*
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].value << "  " << arr[i].weight << " :
    "
             << ((double)arr[i].value / arr[i].weight) <<
    endl;
    }
    */

    int poidCourant = 0; // poids courant du sac à dos
    double valeurFinal = 0.0; // varibale pour stocker le resultat de l'algorithme

    // Boucle sur tout les objets à mettre dans le sac à dos
    for (int i = 0; i < n; i++) {
        // Si l'ajout d'un élément ne fait pas débrder le sac à dos, ajoutez l'element en entier
        if (poidCourant + sac[i].weight <= capacity) {
            poidCourant += sac[i].weight;
            valeurFinal += sac[i].value;
        }

        //Si l'ajout d'un element ne peut pas se faire totalement on ajoute pas ce dernier
        else {
            int reste = capacity - poidCourant;
            valeurFinal += sac[i].value * ((double)reste / (double)sac[i].weight);
            break;
        }
    }

    return valeurFinal;
}

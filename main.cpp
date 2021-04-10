// Problème du sac à dos
// branch and bound
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

// Programme principale
int main()
{

  //1- Sac à dos fractionnaire
    int capacity = 10;
    //Contenu du sac a dos (Static dans un premier temps)
    Item sac[] = { { 10, 1 }, { 15, 2 }, { 40, 3 } };

    int n = sizeof(sac) / sizeof(sac[0]);

    // Calcul de la valeur finale
    cout << "Valeur maximum obtenu avec Knapsack fractionnaire = " << fractionalKnapsack(capacity, sac, n) << endl;


 //2- Sac à dos Dynamic programming
    int valeurs[]={10,15,40};
    int poids[]={1,2,3};
    cout << "Valeur maximum obtenu avec Knapsack Dynamic Programmation = " << DPKnapsack(capacity, valeurs, poids, n) << endl;

 //3- Sac à dos version amelioré (sans trop  de récursivité)
    cout << "Valeur maximum obtenu avec Knapsack Dynamic Programmation amelioré = " << DPKnapsackAmeliorer(capacity, valeurs, poids, n) << endl;

 //4- Backtracking (valeur,poids)
    Item2 sac2[] = { { 2, 40}, { 3.14, 50 }, { 1.98, 100 }, { 5, 95 }, { 3, 30} };
    int n2 = sizeof(sac2) / sizeof(sac2[0]);
    cout << "Valeur maximum obtenu avec le Backtracking = " << Backtracking(capacity, sac2, n2) << endl;


    return 0;
}

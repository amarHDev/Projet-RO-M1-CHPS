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
    int capacity = 6;
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




    return 0;
}

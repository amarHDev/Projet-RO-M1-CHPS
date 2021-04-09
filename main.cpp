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
    int capacity = 50;
    //Contenu du sac a dos (Static dans un premier temps)
    Item sac[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

    int n = sizeof(sac) / sizeof(sac[0]);

    // Calcul de la valeur finale
    cout << "Valeur maximum obtenu avec Knapsack fractionnaire = " << fractionalKnapsack(capacity, sac, n);


 //2- Sac à dos Dynamic programming
    int valeurs[]={60,100,120};
    int poids[]={10,20,30};
    cout << "Valeur maximum obtenu avec Knapsack Dynamic Programmation = " << DPKnapsack(capacity, valeurs, poids, n);


    return 0;
}

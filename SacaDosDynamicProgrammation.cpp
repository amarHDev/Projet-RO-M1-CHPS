//Implementation récursive du problème du sac à dos
#include<bits/stdc++.h>
#include "header.h"

using namespace std;


int max(int a, int b){
  return (a > b) ? a : b;
}


int DPKnapsack(int capacity, int valeurs[], int poids[], int n){

  if( (capacity == 0) || (n==0) ){
    return 0;
  }

  //Si le poid tu dernier objet est supérieur à la capacité de sac à dos (capacity)
  //alors cet objet ne peut pas rentrer à l'interieur, in sera donc écarté de la solution optimale

  if(poids[n-1] > capacity){
    return DPKnapsack(capacity, valeurs, poids, n);
  }else{
        //Sinon renvoyé le max entre : 1- dernier objet inclus / 2- dernier objet non inclus

        return max(valeurs[n-1]+DPKnapsack(capacity-poids[n-1],valeurs,poids,n-1),DPKnapsack(capacity,valeurs,poids,n-1));
  }
}


//Dynamic Programming amelioré
int DPKnapsackAmeliorer(int capacity, int valeurs[], int poids[], int n){

  int temp_tab[n+1][capacity+1];

  for( int i = 0; i <= n ; i++){
    for(int w = 0 ; w <= capacity ; w++){
      if( (w == 0) || (i == 0)){
        temp_tab[i][w] = 0;
      }else if(poids[i-1] <= w){
        temp_tab[i][w] = max (valeurs[i-1] + temp_tab[i-1][w - poids[i-1]], temp_tab[i-1][w]);
      }else{
        temp_tab[i][w] = temp_tab[i-1][w];
      }
    }
  }

  return temp_tab[n][capacity];
}

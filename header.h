//1- Header du problème Sac à dos fractionnaire
bool cmp(struct Item a, struct Item b);
double fractionalKnapsack(int capacity, struct Item sac[], int n);

// Structure d'un article qui stocke le poids et la valeur correspondante de l'article
struct Item {
    int value;
    double weight;

    // Constructor
    Item(int value, double weight){
       this->value=value;
       this->weight=weight;
    }
};

//2- Header problème Sac à dos Dynamic programmation (Implementation récursive brute)
int DPKnapsack(int capacity, int valeurs[], int poids[], int n);

//3- Hearder problème Sac à dos Dynamic programmation (Amelioré)
int DPKnapsackAmeliorer(int capacity, int valeurs[], int poids[], int n);


//4- Backtracking
struct Item2
{
    float weight;
    int value;
};

//Structure afin de stocker les informations de l'arbre
struct Noeud
{
    int niveau; //Niveau du nœud dans l'arbre (index dans sac[])
    int profi; //Profit des nœuds sur le chemin de la racine à ce nœud
    int bound; //Limite supérieure du profit maximum dans le sous-arbre du nœud
    float weight;
};
bool cmp2(struct Item2 a, struct Item2 b);
int bound(Noeud u, int n, int capacity, Item2 sac[]);
int Backtracking(int capacity, Item2 sac[], int n);

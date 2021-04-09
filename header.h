//1- Header du problème Sac à dos fractionnaire
bool cmp(struct Item a, struct Item b);
double fractionalKnapsack(int capacity, struct Item sac[], int n);

// Structure d'un article qui stocke le poids et la valeur correspondante de l'article
struct Item {
    int value;
    int weight;

    // Constructor
    Item(int value, int weight)
    {
       this->value=value;
       this->weight=weight;
    }
};

//2- Header problème Sac à dos Dynamic programmation (Implementation récursive brute)
int DPKnapsack(int capacity, int valeurs[], int poids[], int n);

//3- Hearder problème Sac à dos Dynamic programmation (Amelioré)
int DPKnapsackAmeliorer(int capacity, int valeurs[], int poids[], int n);
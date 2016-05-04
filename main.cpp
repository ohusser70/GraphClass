#include <iostream>
#include <stdlib.h>   // pour les listes
#include <List>
#include "Graph.h"

using namespace std;

Graph MakeFilConducteur();

int main()
{
    Graph villes=MakeFilConducteur();
    villes.showGraph();
    villes.DepthFirstSearchRecursive();

    /*
    // range based for loop (C++11) STYLE
    list<int> valeurs ={1,2,3,5,8,13,21,34};  //declaration et initialisation d'une liste
    for (int i: valeurs)
      cout << i << ", ";
    cout <<  endl;

    valeurs.push_back(55);
    valeurs.push_back(89);

    // OLD STYLE
    list<int>::iterator it=valeurs.begin();
    for(; it != valeurs.end();it++)
      cout << *it << "--";
    cout <<  endl;
*/
    return 0;
}

Graph MakeFilConducteur()
{
    Graph filConducteur;
    filConducteur.AddLink('A','B');
    filConducteur.AddLink('A','F');
    filConducteur.AddLink('A','G');
    filConducteur.AddLink('A','C');
    filConducteur.AddLink('B','A');
    filConducteur.AddLink('C','A');
    filConducteur.AddLink('D','E');
    filConducteur.AddLink('D','F');
    filConducteur.AddLink('E','G');
    filConducteur.AddLink('E','F');
    filConducteur.AddLink('E','D');
    filConducteur.AddLink('F','A');
    filConducteur.AddLink('F','D');
    filConducteur.AddLink('F','E');
    filConducteur.AddLink('G','A');
    filConducteur.AddLink('G','E');
    filConducteur.AddLink('I','J');
    filConducteur.AddLink('I','K');
    filConducteur.AddLink('J','K');
    filConducteur.AddLink('J','I');
    filConducteur.AddLink('K','I');
    filConducteur.AddLink('K','J');
    return filConducteur; // une copie
}

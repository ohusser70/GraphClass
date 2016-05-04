#include <iostream>
#include <stdlib.h>   // pour les listes
#include <List>
#include "Graph.h"

using namespace std;

int main()
{
    Graph villes;
    villes.AddLink('A','B');
    villes.AddLink('A','K');
    villes.AddLink('B','A');
    villes.AddLink('D','F');
    villes.showGraph();

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

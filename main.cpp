/*
    Implémentation CPP avec des classes des Graphes et parcours de base

    Cours Algorithmes II (2017), HE-ARC
*/
#include <iostream>
#include <stdlib.h>   // pour les listes
#include <List>
#include "Graph.h"
#include <queue>

using namespace std;

Graph MakeFilConducteur();

int main()
{
    Graph villes=MakeFilConducteur();
    villes.showGraph();
   // cout << "PARCOURS EN PROFONDEUR RECURSIF"<<endl;
    //villes.DepthFirstSearchRecursive(); // on peut l'excéuter 2x
    //cout << "PARCOURS EN PROFONDEUR ITERATIF"<<endl;
    //villes.DepthFirstSearchIterative(); // l'ordre de parcours est différent

    cout << "PARCOURS EN LARGEUR ITERATIF"<<endl;
    villes.WidthFirstSearchIterative();

    queue <int> file;
    file.push(1);file.push(2);file.push(3);file.push(5);file.push(8);
    while (!file.empty())
    {
        cout <<  file.front() << ", ";
        file.pop();
    }

    return 0;
}

Graph MakeFilConducteur()
{
    ///construction d'un graphe avec 11 sommets(défaut) 'A', 'B', ...,'K'
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

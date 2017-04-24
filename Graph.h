/*
    Graph class sample




    OHU 2017
*/

#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include <iostream>
#include "Link.h"

class Vertex;

class Graph
{
  public:
    Graph(int nb=11);
    virtual ~Graph();
    void showGraph() const;
    bool AddLink(char linkStart, char linkEnd);

    /// Parcours spécifiques
    void DepthFirstSearchRecursive(); //parcours en profondeur récursif
    void DepthFirstSearchIterative(); //parcours en profondeur itératif
    void WidthFirstSearchIterative(); //parcours en largeur itératif
    void ParcoursGeneralise();// ajouter un paramètre de fonction de callback pour l'évaluation de priorité

  protected:
  private:
    /// Visite d'un somment en profondeur récursivement
    void VSPR(Vertex& sommet);
    /// Visite d'un somment en "profondeur" NON récursivement
    void VSPNR(Vertex& sommet);
    /// Visite d'un somment en "largeur" NON récursivement
    void VSLNR(Vertex& sommet);

    /// Visite d'un sommet itérativement à l'aide d'une priority queue et d'une méthode Compute priority
    void VSG(Vertex& startVertex);   // ajouter un paramètre de fonction de callback pour l'évaluation de priorité


    int nbSommets;
    Vertex * ptrSommets;
};

#endif // GRAPH_H

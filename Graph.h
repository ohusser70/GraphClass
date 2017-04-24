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

    /// Parcours sp�cifiques
    void DepthFirstSearchRecursive(); //parcours en profondeur r�cursif
    void DepthFirstSearchIterative(); //parcours en profondeur it�ratif
    void WidthFirstSearchIterative(); //parcours en largeur it�ratif
    void ParcoursGeneralise();// ajouter un param�tre de fonction de callback pour l'�valuation de priorit�

  protected:
  private:
    /// Visite d'un somment en profondeur r�cursivement
    void VSPR(Vertex& sommet);
    /// Visite d'un somment en "profondeur" NON r�cursivement
    void VSPNR(Vertex& sommet);
    /// Visite d'un somment en "largeur" NON r�cursivement
    void VSLNR(Vertex& sommet);

    /// Visite d'un sommet it�rativement � l'aide d'une priority queue et d'une m�thode Compute priority
    void VSG(Vertex& startVertex);   // ajouter un param�tre de fonction de callback pour l'�valuation de priorit�


    int nbSommets;
    Vertex * ptrSommets;
};

#endif // GRAPH_H

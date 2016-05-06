#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include <iostream>
#include "Link.h"
#include <stack>

class Vertex;

class Graph
{
  public:
    Graph(int nb=11);
    virtual ~Graph();
    void showGraph();
    bool AddLink(char linkStart, char linkEnd);
    void DepthFirstSearchRecursive(); //parcours en profondeur récursif
    void DepthSearchIterative();
    void WidthSearchIterative();
  protected:
  private:
    /// Visite d'un sommet en profondeur récursivement
    void VSPR(Vertex& sommet);
    /// Visite d'un sommet en "profondeur" itérativement (avec  une pile)
    void VSPNR(Vertex& sommet);
    int nbSommets;
    Vertex * ptrSommets;
};

#endif // GRAPH_H

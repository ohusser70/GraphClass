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
    void showGraph();
    bool AddLink(char linkStart, char linkEnd);
    void DepthFirstSearchRecursive(); //parcours en profondeur récursif
  protected:
  private:
    /// Visite d'un somment en profondeur récursivement
    void VSPR(Vertex& sommet);
    int nbSommets;
    Vertex * ptrSommets;
};

#endif // GRAPH_H

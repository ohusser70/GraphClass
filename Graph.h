#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include <iostream>
#include "Link.h"

class Graph
{
  public:
    Graph(int nb=11);
    virtual ~Graph();
    void showGraph();
    bool AddLink(char linkStart, char linkEnd);
  protected:
  private:
    int nbSommets;
    Vertex * ptrSommets;
};

#endif // GRAPH_H
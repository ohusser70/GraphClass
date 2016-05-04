#include "Graph.h"

Graph::Graph(int nb) : nbSommets(nb)
{
  ptrSommets = new Vertex[nbSommets];
}

Graph::~Graph()
{
  delete [] ptrSommets;
}

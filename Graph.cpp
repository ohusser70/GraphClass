#include "Graph.h"

void Graph::showGraph()
{
    for (int i=0;i<nbSommets;i++)
    {
        std::cout << (ptrSommets+i)->getLabel() << " : ";
        for (Link& l: (ptrSommets+i)->getNeighboursList())
            std::cout << " -- " << l.getNeighbour().getLabel();
        std::cout << std::endl;
    }
}

Graph::Graph(int nb) : nbSommets(nb)
{
  ptrSommets = new Vertex[nbSommets];
}

Graph::~Graph()
{
  delete [] ptrSommets;
}

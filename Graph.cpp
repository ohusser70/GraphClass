#include "Graph.h"

void Graph::showGraph()
{
    for (int i=0;i<nbSommets;i++)
    {
        char c = (ptrSommets+i)->wasVisited() ? 'X':' ';
        std::cout << "[" << c << "]";
        c = (ptrSommets+i)->wasEncountered() ? 'X':' ';
        std::cout << "[" << c << "]";
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

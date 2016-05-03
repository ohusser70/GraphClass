#include "Graph.h"

void Graph::showGraph()
{
    for (int i=0;i<nbSommets;i++)
    {
        char c = (ptrSommets+i)->wasVisited() ? 'X':' ';
        std::cout << "[" << c << "]";
        c = (ptrSommets+i)->wasEncountered() ? 'X':' ';
        std::cout << "[" << c << "]  ";
        std::cout << (ptrSommets+i)->getLabel() << " : ";
        for (Link& l: (ptrSommets+i)->getNeighboursList())
            std::cout << " -- " << l.getNeighbour().getLabel();
        std::cout << std::endl;
    }
}

bool Graph::AddLink(char linkStart, char linkEnd)
{
    /// Look for Start Vertex
    int i=0;
    bool startNotFound=true;
    while ((i<nbSommets)&& (startNotFound))
    {
        if (linkStart == ptrSommets[i].getLabel())
            startNotFound = false;
        else
            i++;
    }
    /// Verify if End Vertex exists
    int j=0;
    bool endNotFound=true;
    while ((j<nbSommets)&& (endNotFound))
    {
        if (linkEnd == ptrSommets[j].getLabel())
            endNotFound = false;
        else
            j++;
    }
    std::cout << "i:"<<i<< "   j:"<<j<<std::endl;
    if ((!startNotFound)&&(!endNotFound))
    {
        ptrSommets[i].getNeighboursList().push_back(ptrSommets[j]);
        return true;
    }
    return false;
}

Graph::Graph(int nb) : nbSommets(nb)
{
  ptrSommets = new Vertex[nbSommets];
}

Graph::~Graph()
{
  delete [] ptrSommets;
}

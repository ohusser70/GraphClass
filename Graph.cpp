#include "Graph.h"
#include <stack>
#include <queue>

/// Construction, edition, destruction
Graph::Graph(int nb) : nbSommets(nb)
{
  ptrSommets = new Vertex[nbSommets];
}

Graph::~Graph()
{
  delete [] ptrSommets;
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
    //std::cout << "i:"<<i<< "   j:"<<j<<std::endl;
    if ((!startNotFound)&&(!endNotFound))
    {
        ptrSommets[i].getNeighboursList().push_back(ptrSommets[j]);
        return true;
    }
    return false;
}


/// UTILITAIRES

void Graph::showGraph() const
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



/// PARCOURS

// initie le parcours à partir de chaque sommet (itératif)
void Graph::DepthFirstSearchRecursive()
{
  for (int i =0; i< nbSommets;i++)
    ptrSommets[i].visited=ptrSommets[i].encountered=false;
  for (int i =0; i< nbSommets;i++)
    VSPR(ptrSommets[i]);
}

void Graph::DepthFirstSearchIterative()
{
  for (int i =0; i< nbSommets;i++)
    ptrSommets[i].visited=ptrSommets[i].encountered=false;
  for (int i =0; i< nbSommets;i++)
    VSPNR(ptrSommets[i]);
}

void Graph::WidthFirstSearchIterative()
{
  for (int i =0; i< nbSommets;i++)
    ptrSommets[i].visited=ptrSommets[i].encountered=false;
  for (int i =0; i< nbSommets;i++)
    VSLNR(ptrSommets[i]);
}

void Graph::VSPR(Vertex& sommet)
{
  if (false == sommet.visited)
  {
    sommet.visited = true;
    std::cout << sommet.getLabel() << std::endl;  //traitement
    for (Link& l: sommet.AdjacencyList)
      VSPR(l.getNeighbour() );  // appel récursif
  }
}

void Graph::VSPNR(Vertex& sommet)
{
  // créer PILE
  std::stack<Vertex> pile;
  if ((!sommet.visited)&&(!sommet.encountered))
  {
    sommet.visited = true;
    pile.push(sommet);//empiler le sommet
    while (! pile.empty())
    {
        Vertex& refSommet= pile.top();
        pile.pop();
        refSommet.visited = true;
        std::cout << refSommet.getLabel() << std::endl;  //traitement
        for (Link& l: refSommet.AdjacencyList)   //      pour chaque sommet voisin du sommet courant boucler
        {
            //std::cout<<l.getNeighbour().getLabel()<< " ";
            if (!l.neighbourVertex.wasVisited()&&!l.neighbourVertex.wasEncountered())//si le sommet voisin n'est ni rencontré ni visité alors
            {
                l.neighbourVertex.encountered = true;
                pile.push(l.neighbourVertex);
            }
        }
    }
  }
}

void Graph::VSLNR(Vertex& sommet)
{
  // créer FILE
  std::queue<Vertex> file;
  if ((!sommet.visited)&&(!sommet.encountered))
  {
    sommet.visited = true;
    file.push(sommet); //enfiler le sommet
    std::cout << 'A';
    while (!file.empty())
    {
        Vertex& refSommet= file.front();
        file.pop();
        refSommet.visited = true;
        std::cout << "TRAITEMENT DE " << refSommet.getLabel() << std::endl;  //traitement
        for (Link& l: refSommet.getNeighboursList())   //      pour chaque sommet voisin du sommet courant boucler
        {
            std::cout << '.';
            if (!l.neighbourVertex.wasEncountered())//si le sommet voisin n'est ni rencontré ni visité alors
            {
                l.neighbourVertex.encountered = true;
                std::cout << "AJOUT DE " << l.neighbourVertex.getLabel() << std::endl;  //traitement
                file.push(l.neighbourVertex);
            }
        }
    }
  }
}

void Graph::ParcoursGeneralise()
{
    for (int i=0; i<nbSommets;i++)
    {
        ptrSommets[i].visited = false;
        ptrSommets[i].encountered = false;
    }
    for (int i=0; i<nbSommets;i++)
    {
        VSG(ptrSommets[i]);
    }
}

void Graph::VSG(Vertex& startVertex)
{
    startVertex.encountered = true;


}

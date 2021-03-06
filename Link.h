#ifndef LINK_H
#define LINK_H
#include "Vertex.h"
#include "Graph.h"
class Vertex;

/// classe lien entre les sommets (maillon des listes d'adjacence)
class Link
{
  public:
    friend class Graph;
    Link(Vertex& target, int w=1);
    Vertex& getNeighbour(){return neighbourVertex;}
    virtual ~Link();
  protected:
  private:
    Vertex& neighbourVertex;
    int weight;
};

#endif // LINK_H

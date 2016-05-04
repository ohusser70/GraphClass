#ifndef VERTEX_H
#define VERTEX_H
#include "Link.h"
#include "Graph.h"
#include <List>
#include <stdlib.h>
/*
    C'est la classe Sommet qui contient
    - une liste de sommets voisins (adjacents)
    - un identifiant unique (une lettre)




*/
class Link;

class Vertex
{
  public:
    Vertex();
    char getLabel(){return label;}
    bool wasVisited(){return visited;}
    bool wasEncountered(){return encountered;}
    std::list<Link>& getNeighboursList(){return AdjacencyList;}
    virtual ~Vertex();
    friend class Graph;
  protected:
  private:
    // the list of neighbor vertices
    std::list<Link> AdjacencyList;
    // the vertex identifier (and information for the moment)
    char label;
    bool visited;
    bool encountered;
    static int counter;
};

#endif // VERTEX_H

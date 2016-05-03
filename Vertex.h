#ifndef VERTEX_H
#define VERTEX_H
#include "Link.h"
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
    std::list<Link>& getNeighboursList(){return AdjacencyList;}
    virtual ~Vertex();
  protected:
  private:
    std::list<Link> AdjacencyList;
    char label;
    static int counter;
};

#endif // VERTEX_H

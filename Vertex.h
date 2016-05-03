#ifndef VERTEX_H
#define VERTEX_H
#include "Link.h"
#include <list>
#include <stdlib.h>
/*
    C'est la classe Sommet qui contient
    - une liste de sommets voisins (adjacents)
    - un identifiant unique (une lettre)




*/
class Vertex
{
  public:
    Vertex();
    virtual ~Vertex();
  protected:
  private:
    std::List<Link> AdjacencyList;
    char labek;
};

#endif // VERTEX_H

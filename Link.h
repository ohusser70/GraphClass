#ifndef LINK_H
#define LINK_H
#include "Vertex.h"

/// classe lien entre les sommets (maillon des listes d'adjacence)
class Link
{
  public:
    Link(Vertex& target, int w=1);
    virtual ~Link();
  protected:
  private:
    Vertex& neighbourVertex;
    int weight;
};

#endif // LINK_H

#include "Vertex.h"

int Vertex::counter=0;
Vertex::Vertex()
{
    this->label = static_cast<char>('A'+counter);
  counter++;
}

Vertex::~Vertex()
{
  //dtor
}

#include "Coordinate.h"

Coordinate::Coordinate(){
  this->x = 0;
  this->y = 0;
}
Coordinate::Coordinate( int x, int y ){
  this->x = x;
  this->y = y;
}
Coordinate operator + ( Coordinate a, const Coordinate& b ){
  return Coordinate( a.x + b.x, a.y + b.y );
}
Coordinate operator / ( Coordinate a, const int& b ){
  return Coordinate( a.x / b, a.y / b );
}

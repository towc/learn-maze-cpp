#include "Coordinate.h"

Coordinate::Coordinate() : x(0), y(0) {}
Coordinate::Coordinate( int x, int y ) : x(x), y(y) {}
Coordinate operator + ( Coordinate a, const Coordinate& b ){
  return Coordinate( a.x + b.x, a.y + b.y );
}
Coordinate operator / ( Coordinate a, const int& b ){
  return Coordinate( a.x / b, a.y / b );
}

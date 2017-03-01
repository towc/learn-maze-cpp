#ifndef Coordinate_H
#define Coordinate_H

struct Coordinate {
  Coordinate();
  Coordinate( int x, int y );

  int x, y;
};
Coordinate operator + ( Coordinate a, const Coordinate& b );
Coordinate operator / ( Coordinate a, const int& b );

#endif

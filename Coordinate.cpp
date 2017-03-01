#include "Coordinate.h"

Coordinate::Coordinate(){
  set( 0, 0 );
}
Coordinate::Coordinate( int x, int y ){
  set( x, y );
}
Coordinate::~Coordinate(){}
void Coordinate::setX( int x ){
  this->x = x;
}
void Coordinate::setY( int y ){
  this->y = y;
}
void Coordinate::set( int x, int y ){
  this->x = x;
  this->y = y;
}
Coordinate Coordinate::add( Coordinate coord ){
  return Coordinate( this->x + coord.x, this->y + coord.y );
}

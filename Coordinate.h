#ifndef Coordinate_H
#define Coordinate_H

struct Coordinate {
  public:
    Coordinate();
    Coordinate( int x, int y );
    ~Coordinate();
    int x, y;
    void setX( int x );
    void setY( int y );
    void set( int x, int y );
    Coordinate add( Coordinate coord );
};

#endif

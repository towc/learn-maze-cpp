#ifndef Maze_H
#define Maze_H

#include <vector>
#include "Coordinate.h"
#include "Random.h"

class Maze {
  public:
    Maze();
    Maze( int w, int h );
    void gen();
    void gen( int w, int h );
    std::vector<std::vector<bool>> structure;
    bool getCell( Coordinate coord );
    void setCell( Coordinate coord, bool value );
    void fillPrintMap( std::vector<std::vector<char>>& map );
    Coordinate goal;

  private:
    int w, h;
    std::vector<Coordinate> stack;
    int stackIndex;
    std::vector<Coordinate> availableNeighbours;
    void checkNeighbours();
    static const Coordinate neighbourDirs[4];
    static const bool WALL;
    static Random random;
    static const char charWALL;
    static const char charEMPT;
    static const char charGOAL;
  };
#endif

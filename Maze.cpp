#include "Maze.h"
#include <iostream>

using std::vector;

Maze::Maze(){
  w = 20;
  h = 20;

  gen();
}
Maze::Maze( int w, int h ){
  gen( w, h );
}
void Maze::gen(){
  gen( w, h );
}
void Maze::gen( int w, int h ){
  this->w = w;
  this->h = h;

  structure.clear();
  for( int x = 0; x < w; ++x ){
    structure.push_back( vector<bool>() );
    for( int y = 0; y < h; ++y ){
      structure[ x ].push_back( WALL );
    }
  }

  stack.clear();

  stack.push_back( Coordinate( 1, 1 ) );
  stackIndex = 0;

  setCell( Coordinate( 1, 1 ), !WALL );

  int maxIndex = 0;

  int security = 1000000;
  bool keepGoing = true;

  do {

    checkNeighbours();

    int availNeighbourNumber = availableNeighbours.size();

    if( availNeighbourNumber == 0 ){

      --stackIndex;
      stack.pop_back();

    } else {
    
      Coordinate& head = stack[ stackIndex ];
      
      Coordinate &cellD = availableNeighbours[ random->gen() % availNeighbourNumber ];
      Coordinate cell = head + cellD;
      Coordinate hcell = head + ( cellD / 2 );
      
      ++stackIndex;
      stack.push_back( cell );
      setCell( hcell, !WALL );
      setCell( cell, !WALL );

      if( stackIndex > maxIndex ){
        maxIndex = stackIndex;
        goal = cell;
      }


    } 
     
    keepGoing = --security > 0 && stackIndex > 0;

  } while ( keepGoing );
  
}
bool Maze::getCell( Coordinate coord ){
  if( coord.x > 0 && coord.x < w && coord.y > 0 && coord.y < h )
    return structure[ coord.x ][ coord.y ];
  else
    return !WALL;
}
void Maze::setCell( Coordinate coord, bool value ){
  structure[ coord.x ][ coord.y ] = value;
}
void Maze::fillPrintMap( vector<vector<char>>& map ){
  map.clear();
  
  for( int x = 0; x < w; ++x ){
    map.push_back(vector<char>());
    for( int y = 0; y < h; ++y ){
      map[ x ].push_back( structure[ x ][ y ] ? charWALL : charEMPT );
    }
  }

  map[ goal.x ][ goal.y ] = charGOAL;
}
void Maze::checkNeighbours(){

  availableNeighbours.clear();

  Coordinate head = stack[ stackIndex ];

  int i = 0;
  while( i != 4 ){
    Coordinate cell = head + neighbourDirs[ i ];

    if( getCell( cell ) == WALL )
      availableNeighbours.push_back( neighbourDirs[ i ] );

    ++i;
  }
}

const Coordinate Maze::neighbourDirs[4] = {
  Coordinate(  0, -2 ),
  Coordinate(  2,  0 ),
  Coordinate(  0,  2 ),
  Coordinate( -2,  0 )
};
const bool Maze::WALL = true;
Random* Maze::random = new Random();

const char Maze::charWALL = 'x';
const char Maze::charEMPT = ' ';
const char Maze::charGOAL = '.';

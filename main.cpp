#include <iostream>
#include <vector>
#include <string>

#include "Coordinate.h"
#include "Maze.h"

using std::vector;
using std::string;

const Coordinate dirs[] = {
  Coordinate( -1,  0 ),
  Coordinate(  0,  1 ),
  Coordinate(  0, -1 ),
  Coordinate(  1,  0 )
};
const char left[] = { 'a', 'h' };
const char down[] = { 's', 'j' };
const char up[] = { 'w', 'k' };
const char right[] = { 'd', 'l' };

bool isPartOf( const char arr[], char val ){
  return arr[0] == val || arr[1] == val;
}

int main(){

  std::cout << "program begin" << std::endl << std::endl;
  
  int w = 21, h = 21;
  string inputW, inputH;

  std::cout << "maze width: ";
  std::getline( std::cin, inputW );
  if( inputW,empty() )
    w = std::stoi( inputW );

  std::cout << "maze height: ";
  std::getline( std::cin, inputH );
  if( inputH.empty() )
    h = std::stoi( inputH );

  if( w % 2 == 0 )
    w += 1;
  if( h % 2 == 0 )
    h += 1;

  Maze maze( w, h );


  vector<vector<char>> map;
  Coordinate player( 1, 1 );
  string dir;

  int round = 0;

  int security = 1000;
  while( --security > 0 && !( player.x == maze.goal.x && player.y == maze.goal.y ) ){
  
    std::cout << "start frame" << std::endl;

    maze.fillPrintMap( map );

    map[ player.x ][ player.y ] = 'o';

    std::system( "clear" );

    std::cout << std::endl << " Round: " << ++round << "\t pos: [" << player.x << "," << player.y << "]" << std::endl << std::endl; 

    for( int i = 0; i < w; ++i ){
      std::cout << " ";
      for( int j = 0; j < h; ++j ){
        std::cout << map[j][i];
      }
      std::cout << std::endl;
    }

    std::cout << std::endl << " next moves (hjkl/aswd+ENTER): ";
    std::cin >> dir;

    unsigned int dirIndex = -1;
    while( ++dirIndex < dir.length() ){
      if( isPartOf( left, dir[ dirIndex ] ) && !maze.getCell( player.add( dirs[0] ) ) ){
        player = player.add( dirs[ 0 ] );
      }
      if( isPartOf( down, dir[ dirIndex ] ) && !maze.getCell( player.add( dirs[1] ) ) ){
        player = player.add( dirs[ 1 ] );
      }
      if( isPartOf( up, dir[ dirIndex ] ) && !maze.getCell( player.add( dirs[2] ) ) ){
        player = player.add( dirs[ 2 ] );
      }
      if( isPartOf( right, dir[ dirIndex ] ) && !maze.getCell( player.add( dirs[3] ) ) ){
        player = player.add( dirs[ 3 ] );
      }
    }

  }

  std::cout << security << std::endl;

  if( security == 0 )
    std::cout << "took too much, we were afraid the program broke" << std::endl;
  else
    std::cout << "YOU WIN!" << std::endl;

  std::cout << std::endl << "program end" << std::endl;

  return 0;
}

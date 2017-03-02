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

bool arrayContains( const char arr[], char val ){
  return arr[0] == val || arr[1] == val;
}

int main(){

  std::cout << "program begin \n\n";
  
  int w = 21, h = 21;
  string inputW, inputH;

  std::cout << "maze width (20): ";
  std::getline( std::cin, inputW );
  if( !inputW.empty() )
    w = std::stoi( inputW );

  std::cout << "maze height (20): ";
  std::getline( std::cin, inputH );
  if( !inputH.empty() )
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
  
    std::cout << "start frame \n";

    maze.fillPrintMap( map );

    map[ player.x ][ player.y ] = 'o';

    std::system( "clear" );

    std::cout << "\n Round: " << ++round << "\t pos: [" << player.x << "," << player.y << "] \n\n"; 

    for( int i = 0; i < h; ++i ){
      std::cout << " ";
      for( int j = 0; j < w; ++j ){
        std::cout << map[j][i];
      }
      std::cout << "\n";
    }

    std::cout << "\n next moves (hjkl/aswd+ENTER): ";
    std::cin >> dir;

    unsigned int dirIndex = -1;
    while( ++dirIndex < dir.length() ){
      if( arrayContains( left, dir[ dirIndex ] ) && !maze.getCell( player + dirs[0] ) ){
        player = player + dirs[ 0 ];
      }
      if( arrayContains( down, dir[ dirIndex ] ) && !maze.getCell( player + dirs[1] ) ){
        player = player + dirs[ 1 ];
      }
      if( arrayContains( up, dir[ dirIndex ] ) && !maze.getCell( player + dirs[2] ) ){
        player = player + dirs[ 2 ];
      }
      if( arrayContains( right, dir[ dirIndex ] ) && !maze.getCell( player + dirs[3] ) ){
        player = player + dirs[ 3 ];
      }
    }

  }

  if( security == 0 )
    std::cout << "took too much, we were afraid the program broke \n";
  else
    std::cout << "YOU WIN! \n";

  std::cout << "\n program end \n";

  return 0;
}

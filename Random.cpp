#include "Random.h"

Random::Random(){
  setSeed( static_cast<long int> (std::time(0)) ); 
}
Random::Random( long int seed ){
  setSeed( seed );
}
Random::~Random(){}
void Random::setSeed( long int seed ){
  a = seed + 5;
  b = seed + 31;
  c = seed + 1297;

  gen();
}
long int Random::gen(){

  if( c <= 0 )
    c = -c;

  c = ( b % c ) * 34332 - a;
  b = ( a + c ) * 942427;
  a += c % 422342321;

  last = c + b + a;
  if( last < 0 )
    last = -last;

  return last;
}

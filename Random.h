#ifndef Random_h
#define Random_h

#include <ctime>

// only because I was offline when writing the code
// and didn't remember how to use randomness.
// This is an awful implementation, but I wrote it
// for it to work well enough in my case, and it does

class Random {
  public:
    Random();
    Random( long int );
    ~Random();
    long int gen();
    long int last;

  private:
    long int a, b, c;
    void setSeed( long int );
};

#endif

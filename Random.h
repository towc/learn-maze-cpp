#ifndef Random_h
#define Random_h

#include <ctime>

class Random {
  public:
    Random();
    Random( long int );
    ~Random();
    long int gen();
    long int last;
    void printABC();

  private:
    long int a, b, c;
    void setSeed( long int );
};

#endif


#include <chrono>
#include <iostream>
#include <vector>
#include <tuple>
#include <thread>
#include <math.h>

int main();

void schedule(double time);

class Grain {
public:
  int lengthInSamples;
  int startPosition; 
  int currentPosition;
   /**
    CONSTRUCTOR
    */
   Grain()
   {
      startPosition = 0;
      lengthInSamples = 2048;
   };

   Grain(int start, int length){
      startPosition = start;
      lengthInSamples = length;
   };
};

/* maybe play around with this function in a seperate file first */
class GrainStack {
  /** 
   the stack should consist of a vector of tuples of Grain objects and times (of type double)
   */
public:
  std::vector<std::tuple<Grain, double> > stack;
  void push( int startPosition, int length, double startTime)
  {
    stack.push_back(std::make_tuple(Grain(startPosition, length), startTime));
  }

  
  void pop()
  {
    stack.pop_back();
  }

  std::tuple<Grain, double> back()
  {
    return stack.back();
  }
};

GrainStack stack;
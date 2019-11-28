#include <stdio.h>

typedef unsigned int uint;

uint calculate(uint n) {
  if (n <= 1) 
    return 1;
  return calculate(n - 1) + calculate(n - 2);
}
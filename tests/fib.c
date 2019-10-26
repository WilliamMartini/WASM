#include <stdio.h>

typedef unsigned int uint;

uint fib(uint n) {
  if (n <= 1) 
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  printf("%u \n", fib(42));
  return 0;
}
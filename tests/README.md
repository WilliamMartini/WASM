# Tests
We complied some c code to wasm and then ran it on the different runtime tools. We ran each test 3 times for each tool.

### Primes
This test checks if a large prime number is indeed a prime number.  
time wasmtime primes.wasm
```
real	0m35.891s
user	0m35.870s

real	0m35.891s
user	0m35.870s

real	0m36.569s
user	0m36.548s
```
time wasmer run primes.wasm 
```
real	0m27.062s
user	0m27.057s

real	0m26.689s
user	0m26.670s

real	0m26.785s
user	0m26.775s
```
Here we observe wasmer runs about 10 seconds faster

------
### Fibonacci
Here we find the Nth fibonacci number (in the test we used N=42)  
time wasmtime primes.wasm
```
real	0m10.217s
user	0m10.216s

real	0m10.322s
user	0m10.313s

real	0m10.207s
user	0m10.199s
```
time wasmer run primes.wasm 
```
real	0m11.407s
user	0m11.401s

real	0m11.386s
user	0m11.380s

real	0m11.402s
user	0m11.391s
```
Here we observe wasmer runs about 1 second slower

------

# Tests
We complied some c code to wasm and then ran it on the different runtime tools. We ran each test 3 times for each tool.
## How to run the benchmarks
### Wasmtime
```shell
wasm32-wasi-clang -Ofast -o ***.wasm ***.c
time wasmtime ***.wasm
```
### Wasmer
```shell
wasm32-wasi-clang -Ofast -o ***.wasm ***.c
time wasmer run ***.wasm 
```
### Lucetc-wasi
```shell
wasm32-wasi-clang -Ofast -o ***.wasm ***.c
lucetc-wasi -o ***.so ***.wasm
time lucet-wasi ***.so
```
------
## Primes
This test checks if a large prime number is indeed a prime number.  
### Wasmtime
```shell
real    0m19.243s
user    0m19.279s
sys     0m0.009s

real    0m19.194s
user    0m19.180s
sys     0m0.009s

real    0m19.067s
user    0m19.051s
sys     0m0.009s
```
### Wasmer
```shell
real    0m12.620s
user    0m12.620s
sys     0m0.021s

real    0m12.518s
user    0m12.506s
sys     0m0.009s

real    0m12.553s
user    0m12.550s
sys     0m0.000s
```
### Lucetc-wasi
```shell
real    0m12.863s
user    0m0.072s
sys     0m0.039s

real    0m12.788s
user    0m0.069s
sys     0m0.048s

real    0m12.832s
user    0m0.067s
sys     0m0.045s
```

### Observations
Here we observe wasmer and lucetc are running about 7 seconds faster then wasmtime

------
## Fibonacci
Here we find the Nth fibonacci number (in the test we used N=42 and N=52)
### Wasmtime N=42
```shell
real    0m2.108s
user    0m2.139s
sys     0m0.020s

real    0m1.918s
user    0m1.918s
sys     0m0.001s

real    0m1.937s
user    0m1.921s
sys     0m0.016s
```
### Wasmer N=42
```shell
real    0m1.575s
user    0m1.588s
sys     0m0.008s

real    0m1.501s
user    0m1.497s
sys     0m0.004s

real    0m1.482s
user    0m1.469s
sys     0m0.012s
```
### Lucetc-wasi N=42
```shell
real    0m1.726s
user    0m0.050s
sys     0m0.063s

real    0m1.725s
user    0m0.069s
sys     0m0.049s

real    0m1.714s
user    0m0.079s
sys     0m0.037s
```
### Wasmtime N=52
```shell
real    3m54.373s
user    3m54.327s
sys     0m0.045s

real    3m53.036s
user    3m52.998s
sys     0m0.005s

real    3m53.520s
user    3m53.451s
sys     0m0.037s
```
### Wasmer N=52
```shell
real    3m0.951s
user    3m0.923s
sys     0m0.012s

real    3m0.762s
user    3m0.710s
sys     0m0.024s

real    3m3.490s
user    3m3.376s
sys     0m0.056s
```
### Lucetc-wasi N=52
```shell
real    2m50.199s
user    0m0.060s
sys     0m0.070s

real    2m50.220s
user    0m0.078s
sys     0m0.047s

real    2m49.963s
user    0m0.061s
sys     0m0.062s
```
### Observations
Here we observe that for n = 42 wasmer is the fastest with 1.5s followed by lucets with 1.7s and wasmtime with 1.9s
But for n = 52 lucets (2m50s) is about 10s faster then wasmer (3m) and more than a minute faster then lucets (3m53s)

------
## Bubble Sort
50000 integers between 1 and 1000000
This benchmark doesn't work at the moment because wasm can't access other files on a server.
### Wasmtime
```shell

```
### Wasmer
```shell

```
### Lucetc-wasi
```shell

```

### Observations

------
## Multiplication of Square Matrices
The program multiplies two square matrices of size 800x800 with intergers between 1 and 100 (change N for different dimension).

### Wasmtime
```shell
real    0m0.068s
user    0m0.076s
sys     0m0.024s

real    0m0.021s
user    0m0.015s
sys     0m0.007s

real    0m0.021s
user    0m0.018s
sys     0m0.004s
```
### Wasmer
```shell
real    0m0.034s
user    0m0.045s
sys     0m0.005s

real    0m0.019s
user    0m0.016s
sys     0m0.004s

real    0m0.019s
user    0m0.011s
sys     0m0.007s
```
### Lucetc-wasi
```shell
real    0m0.476s
user    0m0.069s
sys     0m0.049s

real    0m0.370s
user    0m0.063s
sys     0m0.051s

real    0m0.381s
user    0m0.056s
sys     0m0.056s
```

### Observations
wasmer (0.025s) is the fastes being almost 10 times faster than lucets and slightly faster then wasmtime (0.034s).
------

## Conclusions
From the first tests it seems that lucets is fastes for larger calculation being significantly faster than wasmer and wasmtime in the fib test with n=52. But in smaller things wasmer seems to be a bit faster. Wasmtime appears to be the slowest in general although it outperformed lucets in the matrix multiplication benchmark.


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
Here we observe wasmer runs about 10 seconds faster

------
## Fibonacci
Here we find the Nth fibonacci number (in the test we used N=42 and N=52)
### Wasmtime N=42
```shell

```
### Wasmer N=42
```shell

```
### Lucetc-wasi N=42
```shell

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

```
### Observations
Here we observe wasmer runs about 1 second slower

------
## Bubble Sort
50000 integers between 1 and 100000000
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

```
### Wasmer
```shell

```
### Lucetc-wasi
```shell

```

### Observations

------

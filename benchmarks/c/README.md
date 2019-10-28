# Tests
We complied some c code to wasm and then ran it on the different runtime tools. We ran each test 3 times for each tool.
## How to run the benchmarks
### Wasmtime
```shell
?
time wasmtime ***.wasm
```
### Wasmer
```shell
?
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
real	0m35.891s
user	0m35.870s

real	0m35.891s
user	0m35.870s

real	0m36.569s
user	0m36.548s
```
### Wasmer
```shell
real	0m27.062s
user	0m27.057s

real	0m26.689s
user	0m26.670s

real	0m26.785s
user	0m26.775s
```
### Lucetc-wasi
```shell
real  0m12.730s
user  0m0.075s

real  0m12.800s
user  0m0.067s

real  0m12.743s
user  0m0.054s
```

### Observations
Here we observe wasmer runs about 10 seconds faster

------
## Fibonacci
Here we find the Nth fibonacci number (in the test we used N=42)
### Wasmtime
```shell
real	0m10.217s
user	0m10.216s

real	0m10.322s
user	0m10.313s

real	0m10.207s
user	0m10.199s
```
### Wasmer
```shell
real	0m11.407s
user	0m11.401s

real	0m11.386s
user	0m11.380s

real	0m11.402s
user	0m11.391s
```
### Lucetc-wasi
```shell
real    0m1.815s
user    0m0.052s

real    0m1.750s
user    0m0.085s

real    0m1.779s
user    0m0.075s
```

### Observations
Here we observe wasmer runs about 1 second slower

------
## Bubble Sort
1000000 integers between 1 and 100000000
### Wasmtime
```shell

```
### Wasmer
```shell

```
### Lucetc-wasi
```shell
thread 'main' panicked at 'lucet-wasi runtime error: Runtime fault: FaultDetails { fatal: false, trapcode: Some(HeapOutOfBounds), rip_addr: 140662650330365, rip_addr_details: Some(AddrDetails { in_module_code: true, file_name: Some("/lucet/src/c/bubbleSort.so"), sym_name: None }) }', lucet-wasi/src/main.rs:250:23
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace.

real    0m0.399s
user    0m0.058s
sys     0m0.062s
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
real    0m0.430s
user    0m0.058s

real    0m0.366s
user    0m0.055s

real    0m0.383s
user    0m0.064s
```

### Observations

------

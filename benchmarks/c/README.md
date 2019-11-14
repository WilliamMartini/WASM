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
### Native C
```shell
gcc ***.c -o ***
time ./***
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
### Native C
```shell
real    0m11.093s
user    0m11.091s
sys     0m0.001s

real    0m11.069s
user    0m11.068s
sys     0m0.000s

real    0m11.089s
user    0m11.083s
sys     0m0.005s
```

### Observations
![chart](/benchmarks/c/charts/Primes.png)
Here we observe wasmer and lucetc are running about 7 seconds faster then wasmtime. Lucetc, wasmer and native are very close to each other but native is still the fastest one.

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
### Native C
```shell
real    0m1.855s
user    0m1.851s
sys     0m0.004s

real    0m1.830s
user    0m1.829s
sys     0m0.000s

real    0m1.912s
user    0m1.903s
sys     0m0.008s
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
### Native C
```shell
real    3m41.914s
user    3m41.826s
sys     0m0.040s

real    3m41.320s
user    3m41.236s
sys     0m0.052s

real    3m40.613s
user    3m40.562s
sys     0m0.036s
```
### Observations
![chart](/benchmarks/c/charts/Fibonacci_42.png)
![chart](/benchmarks/c/charts/Fibonacci_52.png)
Here we observe that for n = 42 wasmer is the fastest with 1.5s followed by lucets with 1.7s and wasmtime with 1.9s.
But for n = 52 lucets (2m50s) is about 10s faster then wasmer (3m) and more than a minute faster then wasmtime (3m53s). Therefore we suspect that lucetc performs better on bigger workloads and wasmer is the better choice for small workloads.

------
## Bubble Sort
Used the bubble sort algorithm to sort different long arrays. This is the only benchmark, that doesn't run with ```time```and only measures the time was needed by sort function to sort the array.

### Wasmtime
```shell
N(1000):      0.003376 seconds
N(5000):      0.076115 seconds
N(10000):     0.280492 seconds
N(50000):     8.734309 seconds
N(75000):    15.000688 seconds
N(100000):  24.465735 seconds
N(250000):  203.373910 seconds
N(500000):  766.793208 seconds

N(1000):      0.002790 seconds
N(5000):      0.076161 seconds
N(10000):     0.283975 seconds
N(50000):     8.728257 seconds
N(75000):    15.126057 seconds
N(100000):   24.424220 seconds
N(250000):  203.571486 seconds
N(500000):  767.521276 seconds

N(1000):      0.002850 seconds
N(5000):      0.075879 seconds
N(10000):     0.290626 seconds
N(50000):     8.936685 seconds
N(75000):    15.112901 seconds
N(100000):   24.608519 seconds
N(250000):  203.118514 seconds
N(500000):  765.585718 seconds
```
### Wasmer
```shell
N(1000):      0.002168 seconds
N(5000):      0.047558 seconds
N(10000):     0.170905 seconds
N(50000):     5.598032 seconds
N(75000):     9.039308 seconds
N(100000):   14.447494 seconds
N(250000):  127.417652 seconds
N(500000):  478.209336 seconds

N(1000):      0.001700 seconds
N(5000):      0.045453 seconds
N(10000):     0.173779 seconds
N(50000):     5.567362 seconds
N(75000):     9.089426 seconds
N(100000):   14.344330 seconds
N(250000):  128.331921 seconds
N(500000):  476.794052 seconds

N(1000):      0.002090 seconds
N(5000):      0.045872 seconds
N(10000):     0.173729 seconds
N(50000):     5.595121 seconds
N(75000):     9.131566 seconds
N(100000):   14.465606 seconds
N(250000):  128.206120 seconds
N(500000):  478.388806 seconds
```
### Lucetc-wasi
```shell
N(1000):      0.004069 seconds
N(5000):      0.047006 seconds
N(10000):     0.161986 seconds
N(50000):     5.150115 seconds
N(75000):     8.490713 seconds
N(100000):   13.517197 seconds
N(250000):  119.187731 seconds
N(500000):  447.631079 seconds

N(1000):      0.001276 seconds
N(5000):      0.043938 seconds
N(10000):     0.165508 seconds
N(50000):     5.247637 seconds
N(75000):     8.611324 seconds
N(100000):   13.625511 seconds
N(250000):  119.577103 seconds
N(500000):  448.519106 seconds

N(1000):      0.002993 seconds
N(5000):      0.045907 seconds
N(10000):     0.164070 seconds
N(50000):     5.181462 seconds
N(75000):     8.554390 seconds
N(100000):   13.721605 seconds
N(250000):  120.241962 seconds
N(500000):  446.838263 seconds
```
### Native C
```shell
N(1000):      0.003313 seconds
N(5000):      0.060817 seconds
N(10000):     0.228301 seconds
N(50000):     7.785158 seconds
N(75000):    12.786361 seconds
N(100000):   20.359726 seconds
N(250000):  183.375277 seconds
N(500000):  686.636290 seconds

N(1000):      0.002926 seconds
N(5000):      0.060933 seconds
N(10000):     0.227535 seconds
N(50000):     7.728809 seconds
N(75000):    12.743064 seconds
N(100000):   20.333683 seconds
N(250000):  183.147819 seconds
N(500000):  685.229332 seconds

N(1000):      0.003341 seconds
N(5000):      0.059551 seconds
N(10000):     0.223157 seconds
N(50000):     7.718848 seconds
N(75000):    12.840300 seconds
N(100000):   20.241532 seconds
N(250000):  183.019325 seconds
N(500000):  684.039957 seconds
```
### Observations
![chart](/benchmarks/c/charts/Bubble_Sort_all.png)
![chart](/benchmarks/c/charts/Bubble_Sort_focus.png)
Wasmtime was slower than all other toolchain and even than native C with the exception of the smallest array. Wasmer and Lucet performed significantly faster than native C. Wasmer was faster when using smaller arrays but Lucet gained speed when increasing the length of the array. For the longest tested array, Lucet was half a minute faster than Wasmer. The startup time can't be the reason for this behavior because only the execution time of the function was measured and not the whole program.

------
## Multiplication of Square Matrices
The program multiplies two square matrices of size 800x800 with intergers between 1 and 100 (change N for different dimension).

### Wasmtime
```shell
real    0m6.913s
user    0m5.959s
sys     0m0.980s

real    0m6.967s
user    0m6.126s
sys     0m0.840s

real    0m6.573s
user    0m5.675s
sys     0m0.896s
```
### Wasmer
```shell
real    0m4.259s
user    0m3.411s
sys     0m0.860s

real    0m4.305s
user    0m3.399s
sys     0m0.903s

real    0m4.456s
user    0m3.488s
sys     0m0.963s
```
### Lucetc-wasi
```shell
thread 'main' panicked at 'lucet-wasi runtime error: Runtime fault: FaultDetails { fatal: false, trapcode: Some(HeapOutOfBounds), rip_addr: 139640631123235, rip_addr_details: Some(AddrDetails { in_module_code: true, file_name: Some("/lucet/src/c/matrixMult.so"), sym_name: None }) }', lucet-wasi/src/main.rs:250:23
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace.

real    0m0.462s
user    0m0.079s
sys     0m0.062s
```
### Native C
```shell
real    0m4.202s
user    0m4.185s
sys     0m0.016s

real    0m4.493s
user    0m4.475s
sys     0m0.016s

real    0m4.129s
user    0m4.113s
sys     0m0.016s
```
### Observations
![chart](/benchmarks/c/charts/Matirx_Multiplication.png)
Wasmertime was again the slowest one by 2.5 seconds. Wasmer and lucetc were close together but the benchmark didn't work for lucet because the main thread panicked.

------

## Conclusions
From the first tests it seems that lucets is fastes for larger calculation being significantly faster than wasmer and wasmtime in the Fibonacci and the bubble sort benchmark. But in smaller things wasmer seems to be a bit faster. Wasmtime appears to be the slowest in general.


# Tests
We complied some c code to wasm and then ran it on the different runtime tools. We ran each test 3 times for each tool.
## How to run the benchmarks
### Wasmtime
```shell
cargo build --target wasm32-wasi
time wasmtime ***.wasm
```
### Wasmer
```shell
cargo build --target wasm32-wasi
time wasmer run ***.wasm 
```
### Lucetc-wasi
```shell
cargo build --target wasm32-wasi
lucetc-wasi -o ***.so ***.wasm
time lucet-wasi ***.so
```
### Native C
```shell
cargo build
time cargo run
```

------
## Fibonacci
Here we find the Nth fibonacci number (in the test we used N=42 and N=52)
### Wasmtime N=42
```shell
real    0m10.047s
user    0m10.030s
sys     0m0.012s

real    0m9.985s
user    0m9.980s
sys     0m0.005s

real    0m9.970s
user    0m9.951s
sys     0m0.016s
```
### Wasmer N=42
```shell
real    0m9.961s
user    0m9.943s
sys     0m0.013s

real    0m9.931s
user    0m9.922s
sys     0m0.009s

real    0m9.828s
user    0m9.809s
sys     0m0.017s
```
### Lucetc-wasi N=42
```shell
real    0m6.493s
user    0m0.066s
sys     0m0.053s

real    0m6.380s
user    0m0.086s
sys     0m0.039s

real    0m6.360s
user    0m0.067s
sys     0m0.055s
```
### Native Rust N=42
```shell
real    0m3.220s
user    0m3.124s
sys     0m0.047s

real    0m2.932s
user    0m2.927s
sys     0m0.004s

real    0m2.986s
user    0m2.977s
sys     0m0.009s
```
### Wasmtime N=52
```shell
real    21m55.741s
user    21m55.730s
sys     0m0.042s
```
### Wasmer N=52
```shell
real    20m23.753s
user    20m23.742s
sys     0m0.024s
```
### Lucetc-wasi N=52
```shell
real    12m35.650s
user    0m0.152s
sys     0m0.055s

real    12m37.574s
user    0m0.108s
sys     0m0.066s

real    12m35.889s
user    0m0.104s
sys     0m0.078s
```
### Native Rust N=52
```shell
real    5m56.834s
user    5m56.716s
sys     0m0.064s

real    5m58.209s
user    5m58.116s
sys     0m0.044s

real    5m58.401s
user    5m58.260s
sys     0m0.076s
```
### Observations


------
## Conclusions

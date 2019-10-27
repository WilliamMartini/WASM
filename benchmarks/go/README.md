# Go benchmarks
### nativ go
```shell
go test -bench=.
``` 
### Lucet go
```shell
GOOS=js GOARCH=wasm go build -o ***.wasm
```
```shell
lucetc-wasi -o prime.so ***.wasm
```
## Prime
### nativ go
```shell
goos: linux
goarch: amd64
BenchmarkPrime-2          146020              8128 ns/op
PASS
ok      _/home/ubuntu/github/WASM/tests/go      1.273s
```
```shell
goos: linux
goarch: amd64
BenchmarkPrime-2          143911              8163 ns/op
PASS
ok      _/home/ubuntu/github/WASM/tests/go      1.263s
```
```shell
goos: linux
goarch: amd64
BenchmarkPrime-2          136954              8134 ns/op
PASS
ok      _/home/ubuntu/github/WASM/tests/go      1.206s
```
### Lucet go
```shell
GOOS=js GOARCH=wasm go build -o prime.wasm
```
```shell
lucetc-wasi -o prime.so prime.wasm
```
```shell
ErrorMessage { msg: "Input is neither valid WASM nor WAT" }

Input
```

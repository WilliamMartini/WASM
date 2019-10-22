Following Tutorial: https://github.com/wasmerio/go-ext-wasm
Wasmer is a Go library for executing WebAssembly binaries.

# Install

To install the library, follow the classical:

```sh
# Enable cgo
$ export CGO_ENABLED=1; export CC=gcc;

$ go get github.com/wasmerio/go-ext-wasm/wasmer
```

To install the `go-wasmer` CLI, follow the classical:

```sh
$ go install github.com/wasmerio/go-ext-wasm/go-wasmer
```

`go install` check go version, didn't work with older go version.

go file to wasm file:
GOOS=js GOARCH=wasm go build -o hello.wasm

wasmer run hello.wasm error:
Error: Can't instantiate module: LinkError([ImportNotFound { namespace: "go", name: "debug" }, ImportNotFound { namespace: "go", name: "runtime.wasmExit" }, ImportNotFound { namespace: "go", name: "runtime.wasmWrite" }, ImportNotFound { namespace: "go", name: "runtime.nanotime" }, ImportNotFound { namespace: "go", name: "runtime.walltime" }, ImportNotFound { namespace: "go", name: "runtime.scheduleTimeoutEvent" }, ImportNotFound { namespace: "go", name: "runtime.clearTimeoutEvent" }, ImportNotFound { namespace: "go", name: "runtime.getRandomData" }, ImportNotFound { namespace: "go", name: "syscall/js.stringVal" }, ImportNotFound { namespace: "go", name: "syscall/js.valueGet" }, ImportNotFound { namespace: "go", name: "syscall/js.valueSet" }, ImportNotFound { namespace: "go", name: "syscall/js.valueIndex" }, ImportNotFound { namespace: "go", name: "syscall/js.valueSetIndex" }, ImportNotFound { namespace: "go", name: "syscall/js.valueCall" }, ImportNotFound { namespace: "go", name: "syscall/js.valueNew" }, ImportNotFound { namespace: "go", name: "syscall/js.valueLength" }, ImportNotFound { namespace: "go", name: "syscall/js.valuePrepareString" }, ImportNotFound { namespace: "go", name: "syscall/js.valueLoadString" }, ImportNotFound { namespace: "go", name: "syscall/js.copyBytesToJS" }])

testing wapm 
wapm install -g cowsay
worked

testing wasmer run
wapm run cowsay "Hello, world!"
worked

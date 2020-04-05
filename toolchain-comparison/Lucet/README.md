# Lucet
## VM
```***.**.***.143```

## Getting started with Lucet
Source of the tutorial: https://github.com/fastly/lucet/wiki

### Setting up the environment
1. The Lucet repository uses git submodules. Make sure they are checked out by running ```git submodule init && git submodule update```.
2. Install and run the ```docker``` service. We do not support ```podman``` at this time. On MacOS, Docker for Mac is an option.
3. Once Docker is running, in a terminal, and at the root of the cloned repository, run: ```source devenv_setenv.sh```. (This command requires the current shell to be ```zsh```, ```ksh``` or ```bash```). After a couple minutes, the Docker image is built and a new container is run.
4. Check that new commands are now available:
```lucetc --help```

### First Lucet application
The ```devenv_setenv.sh``` shell script ensures the Lucet executables are available in your shell:

```shell
source ./devenv_setenv.sh
```
Under the hood, these commands are executed in the Docker container. The container has limited visibility into the host's filesystem - it can only see files under the ```lucet``` repository.

Create a new work directory in the ```lucet``` directory:

```shell
mkdir -p src/hello
cd src/hello
```
Save the following C source code as ```hello.c```:
```C
#include <stdio.h>

int main(void)
{
    puts("Hello world");
    return 0;
}
```

Time to compile to WebAssembly! The development environment includes a version of the Clang toolchain that is built to generate WebAssembly by default. The related commands are accessible from your current shell, and are prefixed by ```wasm32-wasi-```.

For example, to create a WebAssembly module ```hello.wasm``` from ```hello.c```:

```shell
wasm32-wasi-clang -Ofast -o hello.wasm hello.c
```
The next step is to use Lucet to build native ```x86_64``` code from that WebAssembly file:

```shell
lucetc-wasi -o hello.so hello.wasm
```

```lucetc``` is the WebAssembly to native code compiler. The ```lucetc-wasi``` command runs the same compiler, but automatically configures it to target WASI.

```hello.so``` is created and ready to be run:

```shell
lucet-wasi hello.so
```

## Getting started with Go
### Install
https://github.com/golang/go/wiki/Ubuntu
### First example
https://gobyexample.com/hello-world

## Getting started with WebAssembly and Go
https://github.com/golang/go/wiki/WebAssembly  
https://github.com/markfarnan/go-canvas

## Links
https://github.com/fastly/lucet  
https://www.fastly.com/blog/announcing-lucet-fastly-native-webassembly-compiler-runtime  
https://jaxenter.com/webassembly-lucet-157393.html

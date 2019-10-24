# wasmtime
Wasmtime is a small and efficient runtime for WebAssembly & WASI (WebAssembly System Interface)

## VM
***.**.***.64

### Prerequisites
Install rust
```
curl https://sh.rustup.rs -sSf | sh
```
Ensure rust is installed
```
cargo -v
```
Install cmake
```
sudo apt install cmake
```
------

### Install the wasmtime tool
```
curl https://wasmtime.dev/install.sh -sSf | bash
```
We can build the latest wasmtime using
```
> git clone --recurse-submodules https://github.com/CraneStation/wasmtime.git
> cd wasmtime/
> cargo build --release
```
------
### Compiling c code to Wasm
We must first get the appropiate clang to compile to wasm
```
> cd ~ && wget https://github.com/CraneStation/wasi-sdk/releases/download/wasi-sdk-7/wasi-sdk_7.0_amd64.deb
> sudo apt install ~/wasi-sdk_7.0_amd64.deb
```
Lets add the sdk's bin directory to our bash profile so we can call clang without specifying it's full path
```
echo "export PATH="/opt/wasi-sdk/bin:$PATH"" >> ~/.bashrc
```
Note: Restart the terminal after editing the bash. Also, the path ```/opt/wasi-sdk/bin``` might be different in future releases, you can search for the path with
```
find / -name clang 2>/dev/null
```
------
### Testing the complier
Create a hello world in c
```
vim demo.c
```
press ```i``` to insert text in vim and paste
```c
#include <stdio.h>

int main(void) {
    printf("Hello World\n");
    return 0;
}
```
Exit vim by pressing ```ctrl+c``` and then to save type ```:x``` and hit [enter]

Compile the file using
```
clang demo.c -o demo.wasm
```
Double check the it was sucessful compiled to web assembly
```
file demo.wasm
```
We should see the output
```
demo: WebAssembly (wasm) binary module version 0x1 (MVP)
```
Now run the binary with
```
wasmtime demo.wasm
```
We should see the ```Hello World``` printed

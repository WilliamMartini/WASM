# About the program
The program takes in a json string (encoded in base64) from standard input, decodes it and saves it to a file.

# Prerequisite
1. Ensure Rust is installed
```
carvo -V
```
2. Ensure that the WASI toolchain is enabled on rust:
```
rustup target add wasm32-wasi
```

# Create a new Rust project
We will call our project demo
```
cargo new --bin demo
```
Navigate to ```demo/src/main.rs``` and copy the code


Now we can build the project using:
```
cargo build --target wasm32-wasi
```
### Running the project
Navigate to ```demo/target/wasm32-wasi/debug/``` and run:
```
wasmer run --dir=. demo.wasm "eyJhIjoidHh0IiwiYiI6IDEyM30="
```
You should see the output:
```
The program accepts an input in base64
[Usage]: wasmer run --dir=. main.wasm "eyJhIjoidHh0IiwiYiI6IDEyM30="
JSON structure {"a":"txt","b": 123}
----------------------------------------
Got input = eyJhIjoidHh0IiwiYiI6IDEyM30=
Converts to = {"a":"txt","b": 123}
File log.txt updated
```
------

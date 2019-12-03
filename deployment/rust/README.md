# About the program
The program takes in a json string (encoded in base64) from standard input, decodes it and saves it to a file.

# Prerequisite
1. Ensure Rust is installed
```
cargo -V
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
Edit the ```Cargo.toml``` file to include the dependencies

Now we can build the project using:
```
cargo build --target wasm32-wasi
```
### Running the project
Navigate to ```demo/target/wasm32-wasi/debug/``` and run:
```
wasmer run --dir=. demo.wasm '{"a":"txt", "b":1}'
```
You should see the output:
```
The program accepts a JSON input via stdin
[Usage]: wasmer run --dir=. main.wasm '{"a":"txt", "b":2}'
The input is unmarshaled and saved to a file log.txt
----------------------------------------
Got input = {"a":"txt","b": 1}
File log.txt updated
```
Note: The ```log.txt``` should have the data appended, however it appears that the ```.append(true)``` does not work properly with WASI at the moment
------

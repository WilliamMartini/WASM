# Deployment with Node.js

Start wsk
```
cd ~/openwhisk-devtools/docker-compose/
sudo make run
export WSK_CONFIG_FILE=.wskprops
```

Running the add program
```
clang add.c -o add.wasm
zip action.zip index.js add.wasm package.json
wsk -i action create wasm action.zip --kind nodejs:10
wsk -i action invoke wasm -r -p a 2 -p b 2
```
Remove the action:
```
wsk -i action delete wasm
```
Obtained error:
<pre>
{
    "error": {
        "message": "WebAssembly Instantiation: Import #0 module=\"wasi_unstable\" error: <b>module is not an object or function</b>",
        "name": "TypeError",
        "stack": "TypeError: WebAssembly Instantiation: Import #0 module=\"wasi_unstable\" error: module is not an object or function"
    }
}
</pre>
Cause:  
The expected assembly code is itf:
<pre>
(<b>module</b>
  (func (export "add") (param $num1 i32) (param $num2 i32) (result i32)
    get_local $num1
    get_local $num2
    i32.add))
</pre>
To get this format we need to compile with enscripten:
<pre> emcc -s WASM=1 -s SIDE_MODULE=1 -s <b>EXPORTED_FUNCTIONS="['_add']"</b> -O1 add.c -o add.wasm </pre>



## Links
James Thomas blog(http://jamesthom.as/blog/2019/08/06/serverless-and-webassembly-modules/)

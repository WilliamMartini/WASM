# Bluemix

## Setup ibmcloud
First create an account.  
Download ibmcloud cli.  

#### Login to ibmbloud  
ibmcloud login  

#### Set target, region, group for ibmbloud
``` shell
ibmcloud target -r eu-gb -o wasm-soft -s dev
```




## Deploy Serverless Function
#### To use wasm function in js with node.js
``` javascript
const wasm_module = 'library.wasm'
const bytes = fs.readFileSync(wasm_module)
const wasmModule = new WebAssembly.Module(bytes);
const wasmMemory = new WebAssembly.Memory({initial: 512});
const wasmInstance = new WebAssembly.Instance(wasmModule, { env: { memory: wasmMemory } }})

const result = wasmInstance.exports.add(2, 2)

```

#### Compile to wasm, export function you want to use
``` shell
emcc -s WASM=1 -s SIDE_MODULE=1 -s EXPORTED_FUNCTIONS="['_add']" -O1 add.c -o add.wasm
```

#### Create deployment package with source files.
``` shell
zip action.zip index.js add.wasm package.json
```

#### Create deployment package with source files. 
``` shell
zip action.zip index.js add.wasm package.json  
```

#### Create action on ibmcloud.  
``` shell
ibmcloud wsk action create wasm action.zip --kind nodejs:10
```

#### Invoke action on ibmcloud.  
``` shell
ibmcloud wsk action invoke wasm -r -p a 2 -p b 2
```


## Links
http://jamesthom.as/blog/2019/08/06/serverless-and-webassembly-modules/

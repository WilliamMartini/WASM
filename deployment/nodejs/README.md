# Deployment with Node.js

### Install Emscripten

[Getting Started](https://emscripten.org/docs/getting_started/downloads.html)

### Compile to wasm, export function you want to use
``` shell
emcc -s WASM=1 -s SIDE_MODULE=1 -s EXPORTED_FUNCTIONS="['_***']" -O1 ***.c -o ***.wasm
```
*** can be replaced with add or calculate   
If the following error appears:
``` shell
WARNING  root: LLVM version appears incorrect (seeing "(/b/s/w/ir/cache/git/chromium.googlesource.com-external-github.com-llvm-llvm--project", expected "3.4")
INFO     root: (Emscripten: Running sanity checks)
CRITICAL root: Cannot find /home/ubuntu/aws/emsdk/upstream/bin/lli, check the paths in ~/.emscripten
```
Use the following command to reactivate PATH and other environment variables in the current terminal:
``` shell
cd emsdk
source ./emsdk_env.sh
```
### Create deployment package with source files
``` shell
zip action.zip index.js *** package.json
```
*** can be replaced with add.wasm or fib.wasm

## Deployment on openwhisk
[Setup openwhisk](https://github.com/WilliamMartini/WASM/blob/master/deployment/nodejs/openwhisk.md)

### Create action on openwhisk
```shell
wsk -i action create *** action.zip --kind nodejs:10
```
*** can be replaced with wasm_add or wasm_fib

### Invoke action on openwhisk
add example:
```shell
wsk -i action invoke wasm_add -r -p a 1 -p b 2
```
fib example:
```shell
wsk -i action invoke wasm_fib -r -p a 10
```

## Deployment on bluemix
[Setup bluemix](https://github.com/WilliamMartini/WASM/blob/master/deployment/nodejs/bluemix.md)

### Create action on ibmcloud 
``` shell
ibmcloud wsk action create *** action.zip --kind nodejs:10
```
*** can be replaced with wasm_add or wasm_fib

### Invoke action on ibmcloud
add example:
``` shell
ibmcloud wsk action invoke wasm_add -r -p a 1 -p b 2
```
fib example:
``` shell
ibmcloud wsk action invoke wasm_add -r -p a 10
```

## Deployment on aws
[Setup aws](https://github.com/WilliamMartini/WASM/blob/master/deployment/nodejs/aws.md)
### Create action on aws 
``` shell
aws lambda update-function-code --function-name *** --zip-file fileb://action.zip
```
*** can be replaced with wasm_add or wasm_fib

### Invoke action on aws
add example:
``` shell
aws lambda invoke --function-name wasm_add --payload '{"a":1,"b":2}' response.json
```
fib example:
``` shell
aws lambda invoke --function-name wasm_fib --payload '{"a":10}' response.json
```

## Links
http://jamesthom.as/blog/2019/08/06/serverless-and-webassembly-modules/
https://emscripten.org/docs/getting_started/downloads.html

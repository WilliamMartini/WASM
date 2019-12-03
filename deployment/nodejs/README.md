# Deployment with Node.js

### Compile to wasm, export function you want to use
``` shell
emcc -s WASM=1 -s SIDE_MODULE=1 -s EXPORTED_FUNCTIONS="['_add']" -O1 add.c -o add.wasm
```

### Create deployment package with source files.
``` shell
zip action.zip index.js add.wasm package.json
```

### Create deployment package with source files. 
``` shell
zip action.zip index.js add.wasm package.json  
```


## Deployment on openwhisk
[Setup openwhisk](https://github.com/WilliamMartini/WASM/Jo-HANA/blob/master/deployment/nodejs/openwhisk.md)

```
### Create action on openwhisk
```shell
wsk -i action create *** action.zip --kind nodejs:10
```
### Invoke action on openwhisk
```shell
//add example
wsk -i action invoke wasm_add -r -p a 1 -p b 2
//fib example
wsk -i action invoke wasm_fib -r -p a 10
```

## Deployment on bluemix
[Setup bluemix](https://github.com/WilliamMartini/WASM/Jo-HANA/blob/master/deployment/nodejs/bluemix.md)

### Create action on ibmcloud 
``` shell
ibmcloud wsk action create wasm action.zip --kind nodejs:10
```

### Invoke action on ibmcloud
``` shell
//add example
ibmcloud wsk action invoke wasm_add -r -p a 1 -p b 2
//fib example
ibmcloud wsk action invoke wasm_add -r -p a 10
```

## Deployment on aws
[Setup aws](https://github.com/WilliamMartini/WASM/Jo-HANA/blob/master/deployment/nodejs/aws.md)

### Create action on aws 
``` shell
aws lambda update-function-code --function-name *** --zip-file fileb://action.zip
```
### Invoke action on aws
``` shell
//add example
aws lambda invoke --function-name wasm_add --payload '{ "a":1,"b":2}' response.json
//fib example
aws lambda invoke --function-name wasm_fib --payload '{ "a":10}' response.json
```
## Links
http://jamesthom.as/blog/2019/08/06/serverless-and-webassembly-modules/
https://emscripten.org/docs/getting_started/downloads.html
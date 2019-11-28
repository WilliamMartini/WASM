# Bluemix

## Setup ibmcloud
First create an account.  
Download ibmcloud cli.  

#### Login to ibmbloud  
ibmcloud login  

#### Set target, region, group for ibmbloud  
ibmcloud target -r eu-gb -o wasm-soft -s dev




## Deploy Serverless Function
#### Create deployment package with source files.  
zip action.zip index.js add.wasm package.json  

#### Create action on ibmcloud.  
ibmcloud wsk action create wasm action.zip --kind nodejs:10

#### Invoke action on ibmcloud.  
ibmcloud wsk action invoke wasm -r -p a 2 -p b 2



## Links
http://jamesthom.as/blog/2019/08/06/serverless-and-webassembly-modules/

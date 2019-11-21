# Openwhisk

## Prerequsites
Install npm and openssl:
```
apt install npm openssl -y
```
Install docker:
```
sudo apt-get remove docker docker-engine docker.io containerd runc
sudo apt-get update
sudo apt-get install apt-transport-https ca-certificates curl gnupg-agent software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io
```

## Installing OpenWisk
Install the platform with the following commands:  
```
git clone git@github.com:apache/incubator-openwhisk-devtools.git  
cd incubator-openwhisk-devtools/docker-compose  
make lean 
```
Export the config file path:
```
export WSK_CONFIG_FILE=~/openwhisk-devtools/docker-compose/.wskprops
```
If needed export the wsk binary
```
echo "export PATH="$HOME/tmp/openwhisk/src/bin/:$PATH"" >> ~/.bashrc
```
------
## Testing OpenWisk
Create a ```hello.js``` file with the following
```
function main (params) {
  var name = params.name || 'World'
  return { payload: 'Hello, ' + name + '!' }
}
```
create a new action called hello
```
wsk action create hello hello.js
```
If you get a authentication error you must set your ip using (replace x.x.x.x):
```
wsk property set --apihost https://x.x.x.x
```
Or you can copy the config file from ```/openwhisk-devtools/docker-compose/.wskprops``` to your current directory and run like this:
```
WSK_CONFIG_FILE=config wsk action create hello hello.js
```
If you get the following error certificate:
```
error: Unable to create action 'hello': Put https://localhost/api/v1/namespaces/_/actions/hello?overwrite=false: x509: certificate is valid for x.x.x.x, not localhost
```
Use the ```-i``` tag
```
wsk -i action create hello hello.js
```
Lets not check that your action was created and try to run it:
```
wsk -i action list
wsk -i action invoke -r hello -p name YourName
wsk activation list
```



## Links
http://jamesthom.as/blog/2018/01/19/starting-openwhisk-in-sixty-seconds/

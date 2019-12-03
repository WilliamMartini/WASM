# Wasmer in Docker Container
This container simply contains the wasmer binary and a hello world wasm file.

## Prerequsite 
Note: The wasmer binnary is too large for github, grab the latest binnary and place it into this folder  
Option A
```
curl https://get.wasmer.io -sSfL | sh
cp ~/.wasmer/bin/wasmer ~/WASM/doker-wasm/
```

Option B
```
wget https://github.com/wasmerio/wasmer/releases/latest/download/wasmer-linux-amd64.tar.gz
tar xvzf wasmer-linux-amd64.tar.gz
cp ./bin/wasmer ~/WASM/doker-wasm/
```
-----
Build:
``` 
sudo docker build -t wasmer .
```

Run example:
```
sudo docker run wasmer run /example/hello.wasm
```

Using a local file:
```
docker run -v $(pwd):/virtual/path/ wasmer run /virtual/path/myfile.wasm
```
Here we have ```myfile.wasm``` in our current directory and we link our current directory to a virtual path in the container 

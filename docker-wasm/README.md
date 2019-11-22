# Wasmer in Docker Container
This container simply contains the wasmer binary and a hello world wasm file.

Note: The wasmer binnary is too large for github, grab the latest binnary using ```curl https://get.wasmer.io -sSfL | sh``` and then copy the binnary ```~/.wasmer/bin/wasmer``` into this folder.

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

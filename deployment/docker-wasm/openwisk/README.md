# Wasmer-Flask in Docker Container for OpenWisk
To run WASM on OpenWisk we need a container with the end points `\init` and  `\run`. OpenWisk provides a [container](https://github.com/apache/openwhisk-runtime-docker) `openwisk/dockerskeleton`. We modified this [dockerfile](https://github.com/apache/openwhisk-runtime-docker/blob/master/core/actionProxy/Dockerfile), since in Alpine dynamically linked binnaries won't work. One solution is to add `RUN apk add --no-cache libc6-compat` but this didn't help. So we went for non-Alpine container (this however increases the size from 200mb to 1gb).

## Prerequsite 
Ensure openwisk is installed.  
If wisk environment has stopped, use the script provided to resatrt it:
```
sudo ./restart_wisk.sh
```

## Make the container
This is how we made the container. Note that if you make your own container you will have to upload it to Docker hub to run it on Openwisk. You can skip this step and use our container.
Build:
``` 
sudo docker build -t leonardas103/actionproxy .
```
Test that it works:
```
sudo docker run -it -p 8080:8080 leonardas103/actionproxy
curl -X post localhost:8080/run
```
## Push to you docker hub
```
sudo docker login
sudo docker push myusername/actionproxy
```

## Run on openwisk
If needed use the provided `restart_wisk.sh` script to restart openwisk.  
To run use `./run.sh yourwasmfile.wasm`
This script does the followin:
```
zip exec.zip exec myfile.wasm
wsk -i action create test1 exec.zip --docker leonardas103/actionproxy
wsk -i action invoke test1 --blocking --result
```

#!/bin/bash

if [ "$1" == "" ]; then
    echo "[usage ./run myfile.wasm]"
    exit
fi
WASM_FILE=$1

if [ ! -f "$WASM_FILE" ]; then
    echo "Specified fild not found"
    exit
fi

# zip files together
if [ -f "myfile.wasm" ]; then
    zip exec.zip exec myfile.wasm
else
    cp "$WASM_FILE" myfile.wasm
    zip exec.zip exec myfile.wasm
    rm myfile.wasm
fi

# run on openwisk
wsk -i action delete test1
wsk -i action create test1 exec.zip --docker leonardas103/actionproxy
wsk -i action invoke test1 --blocking --result

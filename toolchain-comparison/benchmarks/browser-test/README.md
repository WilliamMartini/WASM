# Golang WebAssembly
Our goal was to write a function that accepts a JSON string and then logs it to file. We found that currently Golang doesn't not support Web Assembly outside the Broswer. In the current state there in no file IO in the browser.

### Stetting up
In ```main.go``` we write our main program and compile it using: 
```
GOOS=js GOARCH=wasm go build -o main.wasm
```
To run this in the browser we need a Javascript support file ```wasm_exec.js``` and  ```index.html``` file. We then edit the index file to include our ```main.wasm``` file.
Next we run these on a ````server.go``` hosted locally:
```
go run server.go
```
We can then open  ```http://localhost:8080``` in our Browser and go to ```Inspecet > Console``` (```Ctrl+Shift+J```).
Now we can can access the function that we wrote by entering:
```
getJSON(`{"date": "0/0/0", "key": "example"}`)
```
Here our function converts the JSON to a struct and just returns the date value in the console. However when tring to save to file we encounter an error:
```
open myfile.data: not implemented on js
```
------

package main

import (
	"encoding/json"
	"fmt"
	"os"
	"syscall/js"
)

type Event struct {
	Date string `json:"date"`
	Key  string `json:"key"`
}

func save(data Event) {
	f, err := os.OpenFile("outputlog.txt", os.O_APPEND|os.O_WRONLY, 0644)
	if err != nil {
		fmt.Println(err)
	}
	f.WriteString(data.Date + "\n")
	f.Close()
}

//getJSON(`{"date": "0/0/0", "key": "example"}`)
func getJSON(this js.Value, i []js.Value) interface{} {
	data := Event{}
	json.Unmarshal([]byte(i[0].String()), &data)
	save(data)
	return js.ValueOf(data.Date)
}

func registerCallbacks() {
	js.Global().Set("getJSON", js.FuncOf(getJSON))
}

func main() {
	c := make(chan struct{}, 0)
	println("WASM Go Initialized")
	registerCallbacks()
	<-c
}

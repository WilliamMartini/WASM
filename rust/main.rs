use std::env;
use std::fs::OpenOptions;
use std::io::Write;
extern crate serde;
use serde::{Serialize, Deserialize};
use base64;

#[derive(Serialize, Deserialize, Debug)]
pub struct Event  {
    a: String,
    b: u8,
}

fn main() {
    println!("The program accepts an input in base64");
    println!(r#"[Usage]: wasmer run --dir=. main.wasm "eyJhIjoidHh0IiwiYiI6IDEyM30=""#);
    println!(r#"JSON structure {{"a":"txt","b": 123}}"#);
    println!("----------------------------------------");

    let input_base64 = env::args().nth(1).unwrap_or("eyJhIjoidHh0IiwiYiI6IDEyM30=".to_string());
    println!("Got input = {}",input_base64);
    let input_bytes = base64::decode(&input_base64).unwrap();
    let input_text = String::from_utf8(input_bytes).expect("Found invalid UTF-8"); 
    println!("Converts to = {}",input_text);
    let decoded: Event = serde_json::from_str(&input_text).unwrap();

	let output = format!("{} {}\n", decoded.a, decoded.b.to_string());
	let mut file = OpenOptions::new().append(true).create(true).open("log.txt").expect("cannot open file");
	file.write_all(output.as_bytes()).expect("write failed");
    
    println!("File log.txt updated");

}

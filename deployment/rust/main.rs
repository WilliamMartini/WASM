use std::env;
use std::fs::OpenOptions;
use std::io::Write;
extern crate serde;
use serde::{Serialize, Deserialize};

#[derive(Serialize, Deserialize, Debug)]
pub struct Event  {
    a: String,
    b: u32,
}

fn main() {
    println!("The program accepts a JSON input via stdin");
    println!(r#"[Usage]: wasmer run --dir=. main.wasm '{{"a":"txt", "b":2}}'"#);
    println!("The input is unmarshaled and saved to a file log.txt");
    println!("----------------------------------------");

    let input = env::args().nth(1).unwrap_or(r#"{"a":"txt","b": 123}"#.to_string());
    println!("Got input = {}",input);
    let decoded: Event = serde_json::from_str(&input).unwrap();
	let output = format!("{} {}\n", decoded.a, decoded.b.to_string());
	let mut file = OpenOptions::new().append(true).create(true).open("log.txt").expect("cannot open file");
	file.write_all(output.as_bytes()).expect("write failed");
    println!("File log.txt updated");

}

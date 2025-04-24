use std::{
    io::{stdin, Read, Write},
    net::{TcpListener, TcpStream},
};

fn main() {
    let mut stream = TcpStream::connect("localhost:8080").unwrap();
    let mut buffer = [0_u8; 1000];
	let mut input = String::new();
	stdin().read_line(&mut input).unwrap();
	buffer[0..input.as_bytes().len()] = input.as_bytes();
    stream.write(&buffer).unwrap();
    stream.read(&mut buffer).unwrap();
}

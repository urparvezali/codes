#![allow(unused)]

use std::sync::mpsc::channel;
use std::sync::{Arc, Mutex};
use std::thread::{self, sleep};
use std::time::{Duration, SystemTime, UNIX_EPOCH};

fn solve(scan: &mut Scanner, case: usize) {
    let v = Arc::new(Mutex::new(vec![])); // Initialize with a size of 10 for safe indexing
    let (tx, rx) = channel();

    let mut hndls = vec![];
    for i in 0..10 {
        let tx = tx.clone();
        let v = Arc::clone(&v); // Clone the Arc for use in the thread
        hndls.push(thread::spawn(move || {
            sleep(Duration::from_millis(
                (SystemTime::now()
                    .duration_since(UNIX_EPOCH)
                    .unwrap()
                    .as_nanos()
                    % 1000) as u64,
            ));
            tx.send(i).unwrap();
            v.lock().unwrap().push(i); // Update the shared vector
        }));
    }
    for x in hndls {
        x.join().unwrap();
    }
    for i in 0..10 {
        let j = rx.recv().unwrap();
        print!("{}", j); // Print received value
    }
    println!();
    for i in v.lock().unwrap().iter() {
        print!("{}", i);
    }
}

// Dummy Scanner for compilation
struct Scanner;

fn main() {
    let mut scanner = Scanner;
    solve(&mut scanner, 1);
}

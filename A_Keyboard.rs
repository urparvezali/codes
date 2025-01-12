#![allow(unused)]

use std::collections::HashMap;

fn solve(scan: &mut Scanner, case: usize) {
    let c: char = scan.next();
    let mut v: Vec<char> = scan.next::<String>().chars().collect();
    let mut left: HashMap<char, char> = HashMap::new();
    let mut right: HashMap<char, char> = HashMap::new();
    left.insert('q', 'p');
    left.insert('w', 'q');
    left.insert('e', 'w');
    left.insert('r', 'e');
    left.insert('t', 'r');
    left.insert('y', 't');
    left.insert('u', 'y');
    left.insert('i', 'u');
    left.insert('o', 'i');
    left.insert('p', 'o');
    left.insert('a', ';');
    left.insert('s', 'a');
    left.insert('d', 's');
    left.insert('f', 'd');
    left.insert('g', 'f');
    left.insert('h', 'g');
    left.insert('j', 'h');
    left.insert('k', 'j');
    left.insert('l', 'k');
    left.insert(';', 'l');
    left.insert('z', '/');
    left.insert('x', 'z');
    left.insert('c', 'x');
    left.insert('v', 'c');
    left.insert('b', 'v');
    left.insert('n', 'b');
    left.insert('m', 'n');
    left.insert(',', 'm');
    left.insert('.', ',');
    left.insert('/', '.');

    right.insert('p', 'q');
    right.insert('q', 'w');
    right.insert('w', 'e');
    right.insert('e', 'r');
    right.insert('r', 't');
    right.insert('t', 'y');
    right.insert('y', 'u');
    right.insert('u', 'i');
    right.insert('i', 'o');
    right.insert('o', 'p');
    right.insert(';', 'a');
    right.insert('a', 's');
    right.insert('s', 'd');
    right.insert('d', 'f');
    right.insert('f', 'g');
    right.insert('g', 'h');
    right.insert('h', 'j');
    right.insert('j', 'k');
    right.insert('k', 'l');
    right.insert('l', ';');
    right.insert('/', 'z');
    right.insert('z', 'x');
    right.insert('x', 'c');
    right.insert('c', 'v');
    right.insert('v', 'b');
    right.insert('b', 'n');
    right.insert('n', 'm');
    right.insert('m', ',');
    right.insert(',', '.');
    right.insert('.', '/');
    if c == 'R' {
        for i in 0..v.len() {
            v[i] = *left.get(&v[i]).unwrap();
        }
    } else {
        for i in 0..v.len() {
            v[i] = *right.get(&v[i]).unwrap();
        }
    }
    v.println();
}
fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
    (1..=t).for_each(|case| solve(&mut scan, case));
}
trait Print {
    fn println(&self);
}
impl<T: std::fmt::Display> Print for T {
    fn println(&self) {
        println!("{}", self);
    }
}

trait Prints {
    fn println(&self);
}
impl<T: std::fmt::Display> Prints for Vec<T> {
    fn println(&self) {
        if let Some((last, elements)) = self.split_last() {
            for element in elements {
                print!("{}", element);
            }
            println!("{}", last);
        }
    }
}
struct Scanner {
    arr: Vec<String>,
}
impl Scanner {
    fn new() -> Self {
        Self { arr: Vec::new() }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        T::Err: std::fmt::Debug,
    {
        if self.arr.is_empty() {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            self.arr = input.split_whitespace().rev().map(String::from).collect();
        }
        self.arr.pop().unwrap().parse().unwrap()
    }

    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T>
    where
        T::Err: std::fmt::Debug,
    {
        (0..n).map(|_| self.next()).collect()
    }
}

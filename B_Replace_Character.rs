#![allow(unused)]

use std::collections::HashMap;

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut v: Vec<char> = scan.next::<String>().chars().collect();
    let mut occ: HashMap<char, u32> = HashMap::new();
    for &c in &v {
        *occ.entry(c).or_insert(0) += 1;
    }
    let mut mxchar = 'a';
    let mut mx = 0;
    let mut mnchar = 'a';
    let mut mn = u32::MAX;
    for (&key, &val) in &occ {
        if val > mx {
            mxchar = key;
            mx = val;
        }
        if val <= mn {
            mnchar = key;
            mn = val;
        }
    }
    if mxchar == mnchar {
        let mut s = v.iter().fold(String::new(), |mut acc, &x| {
            acc.push(x);
            acc
        });
        println!("{}", s);
        return;
    }
    for ele in &mut v {
        if *ele == mnchar {
            *ele = mxchar;
            break;
        }
    }
    println!(
        "{}",
        v.iter().fold(String::new(), |mut acc, &x| {
            acc.push(x);
            acc
        })
    );
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    let t: usize = scan.next();
    (0..t).for_each(|case| solve(&mut scan, case + 1));
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
                print!("{} ", element);
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

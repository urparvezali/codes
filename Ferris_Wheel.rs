#![allow(unused)]

use std::collections::VecDeque;

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let k: i32 = scan.next();
    let mut v: Vec<i32> = scan.vec(n);
    v.sort();
    let mut vq: VecDeque<i32> = v.iter().map(|val| *val).collect();
    let mut ans = 0;
    while !vq.is_empty() {
        if vq.len() > 1 && vq.front().unwrap() + vq.back().unwrap() > k {
            ans += 1;
            vq.pop_back();
            continue;
        }
        if vq.len() > 1 && vq.front().unwrap() + vq.back().unwrap() <= k {
            ans += 1;
            vq.pop_back();
            vq.pop_front();
            continue;
        }
        if vq.len() == 1 {
            ans += 1;
            break;
        }
    }
    ans.println();
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

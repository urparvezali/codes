#![allow(unused)]

use std::collections::HashMap;

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let v: Vec<usize> = scan.vec(&n);
    let mut mp = HashMap::new();
    let mut ans = 0 as usize;
    for i in 0..n - 2 {
        let (a, b, c) = (v[i], v[i + 1], v[i + 2]);
        ans += mp.get(&(0, b, c)).unwrap_or(&0)
            + mp.get(&(a, 0, c)).unwrap_or(&0)
            + mp.get(&(a, b, 0)).unwrap_or(&0)
            - 3 * mp.get(&(a, b, c)).unwrap_or(&0);

        *mp.entry((0, b, c)).or_default() += 1;
        *mp.entry((a, 0, c)).or_default() += 1;
        *mp.entry((a, b, 0)).or_default() += 1;
        *mp.entry((a, b, c)).or_default() += 1;
    }
    ans.println();
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
        (0..self.len() - 1).for_each(|u| print!("{} ", self[u]));
        (0.max(self.len() - 1)..self.len()).for_each(|u| println!("{}", self[u]));
    }
}
struct Scanner {
    arr: Vec<String>,
}
impl Scanner {
    fn new() -> Self {
        Self {
            arr: Vec::default(),
        }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        match self.arr.pop() {
            Some(s) => s.parse().unwrap(),
            None => {
                let mut input = String::new();
                std::io::stdin().read_line(&mut input).unwrap();
                self.arr = input
                    .split_whitespace()
                    .rev()
                    .map(|s| s.to_string())
                    .collect();
                self.arr.pop().unwrap().parse().unwrap()
            }
        }
    }
    fn vec<T: std::str::FromStr>(&mut self, n: &usize) -> Vec<T>
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        (0..*n)
            .map(|_| match self.arr.pop() {
                Some(s) => s.parse().unwrap(),
                None => {
                    let mut input = String::default();
                    std::io::stdin().read_line(&mut input).unwrap();
                    self.arr = input
                        .split_whitespace()
                        .rev()
                        .map(|s| s.to_string())
                        .collect();
                    self.arr.pop().unwrap().parse().unwrap()
                }
            })
            .collect()
    }
}

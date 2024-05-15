#![allow(unused)]

use std::collections::BTreeMap;

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let m: usize = scan.next();
    let k: usize = scan.next();
    let a: Vec<usize> = scan.vec(&n);
    let b: Vec<usize> = scan.vec(&m);

    let mut st1: BTreeMap<usize, usize> = BTreeMap::new();
    let mut st2: BTreeMap<usize, usize> = BTreeMap::new();
    for &i in &b {
        *st2.entry(i).or_insert(0) += 1;
    }
    let (mut cnt, mut ans) = (0_usize, 0_usize);
    for i in 0..a.len() {
        if st1.len() < m {
            *st1.entry(a[i]).or_insert(0) += 1;
            if let Some(&res) = st2.get(&a[i]) {
                cnt += 1;
            }
            if cnt >= k && m == st1.len() {
                ans += 1;
            }
            println!("{:?} {}", st1, cnt);
            continue;
        }
        if let Some(&res) = st2.get(&a[i]) {
            cnt += 1;
        }
        if let Some(&res) = st2.get(&a[i - k]) {
            cnt -= 1;
        }
        *st1.entry(a[i]).or_insert(0) += 1;
        *st1.entry(a[i - k]).or_insert(0) -= 1;
        if cnt >= k {
            ans += 1;
        }
        println!("{:?} {}", st1, cnt);
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

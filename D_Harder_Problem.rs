#![allow(unused)]

use std::{
    collections::HashSet,
    time::{SystemTime, UNIX_EPOCH},
};

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut cntr = 0;
    let mut ans = Vec::with_capacity(n);
    let arr: Vec<i32> = scan.vec::<i32>(n);
    let used: HashSet<i32> = arr.clone().into_iter().collect();
    let unused: Vec<i32> = (1..=n as i32).filter(|val| !used.contains(val)).collect();
    let mut st: HashSet<i32> = HashSet::new();
    for &ele in &arr {
        if let Some(res) = st.get(&ele) {
            ans.push(unused[cntr]);
            st.insert(unused[cntr]);
            cntr += 1;
        } else {
            ans.push(ele);
            st.insert(ele);
        }
    }
    ans.println();
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = scan.next();
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

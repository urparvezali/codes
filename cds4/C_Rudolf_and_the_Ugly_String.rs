#![allow(unused)]

use std::{
    cmp::min,
    collections::{HashMap, HashSet},
};

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut str: String = scan.next();
    let mut ans: usize = 0;
    let mut st: HashSet<usize> = HashSet::new();
    for i in 0..str.len() - min(2, str.len()) {
        if str[i..i + 3] == "map".to_string()
            && st.contains(&i) == false
            && st.contains(&(i + 1)) == false
            && st.contains(&(i + 2)) == false
        {
            if i + 3 < str.len() && str[i + 3..i + 4] != "p".to_string() {
                st.insert(i + 2);
            } else {
                st.insert(i + 1);
            }
            ans += 1;
        }
    }
    for i in 0..str.len() - min(2, str.len()) {
        if str[i..i + 3] == "pie".to_string()
            && st.contains(&i) == false
            && st.contains(&(i + 1)) == false
            && st.contains(&(i + 2)) == false
        {
            ans += 1;
        }
    }
    ans.println();
}

fn main() {
    let mut scan = Scanner::new();
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

#![allow(unused)]
use std::{
    io::{stdin, BufRead},
    ops::Range,
};

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let q: isize = scan.next();
    let vec = scan.vec::<isize>(&n);
    let mut st = SegmentTree::new(&vec);
    for _ in 0..q {
        let wht: usize = scan.next();
        let l: usize = scan.next();
        let r: usize = scan.next();
        if wht == 2 {
            println!("{}", st.get(l - 1..r));
        } else {
            st.set(&(l - 1), &(r as isize));
        }
    }
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
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

struct SegmentTree {
    n: usize,
    sz: usize,
    tree: Vec<isize>,
}
impl SegmentTree {
    fn new(vec: &Vec<isize>) -> Self {
        let n = (1 << ((vec.len() as f64).log2().ceil() as usize));
        let mut sz = 2 * n - 1;
        let tree = vec![isize::MAX; sz];
        let mut st = Self { n, sz, tree };
        st.build(vec);
        st
    }
    fn show(&self) {
        println!("{:?}", self.tree);
    }
    fn build(&mut self, vec: &Vec<isize>) {
        for i in 0..vec.len() {
            self.tree[self.sz / 2 + i] = vec[i];
        }
        for i in (0..self.sz / 2).rev() {
            self.tree[i] = self.tree[2 * i + 1].min(self.tree[2 * i + 2]);
        }
    }
    fn set(&mut self, idx: &usize, val: &isize) {
        self._set(idx, val, 0, 0..self.n);
    }
    fn _set(&mut self, idx: &usize, val: &isize, i: usize, r: Range<usize>) {
        // println!("{:?}", r);
        if r.len() == 1 {
            self.tree[i] = *val;
            return;
        }
        let m = (r.end + r.start) / 2;
        if *idx < m {
            self._set(idx, val, 2 * i + 1, r.start..m);
        } else {
            self._set(idx, val, 2 * i + 2, m..r.end);
        }
        self.tree[i] = self.tree[2 * i + 1].min(self.tree[2 * i + 2]);
    }
    fn get(&self, r: Range<usize>) -> isize {
        self._get(&r, 0, 0..self.n)
    }
    fn _get(&self, r: &Range<usize>, idx: usize, b: Range<usize>) -> isize {
        // println!("{b:?}  {idx}");
        if r.start >= b.end || r.end <= b.start {
            return isize::MAX;
        } else if r.start <= b.start && r.end >= b.end {
            return self.tree[idx];
        }
        let m = (b.end + b.start) / 2;
        self._get(r, 2 * idx + 1, b.start..m)
            .min(self._get(r, 2 * idx + 2, m..b.end))
    }
}

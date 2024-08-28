#![allow(unused)]
use std::ops::Range;

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let q: usize = scan.next();
    let vec: Vec<isize> = vec![0; n];
    let mut st = SegmentTree::new(&vec);
    for _ in 0..q {
        let wht: isize = scan.next();
        if wht == 1 {
            let l: usize = scan.next();
            let r: usize = scan.next();
            let v: isize = scan.next();
            st.set(&(l..r), &v);
        } else {
            let i: usize = scan.next();
            println!("{}", st.get(&i));
        }
    }
    // st.show();
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
    (0..t).for_each(|case| solve(&mut scan, case + 1));
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
        let tree = vec![isize::default(); sz];
        let mut st = Self { n, sz, tree };
        st
    }
    fn show(&self) {
        println!("{:?}", self.tree);
    }
    fn set(&mut self, r: &Range<usize>, v: &isize) {
        self._set(r, v, 0, 0..self.n);
    }
    fn _set(&mut self, r: &Range<usize>, v: &isize, idx: usize, b: Range<usize>) {
        if b.end < r.start || b.start >= r.end {
            return;
        }
        if (b.start >= r.start && b.end <= r.end) {
            self.tree[idx] += v.clone();
            return;
        }
        if b.len() == 1 {
            if b.start >= r.start && b.end <= r.end {
                self.tree[idx] = v.clone();
            }
            return;
        }
        let m = (b.end + b.start) / 2;
        self._set(&r, v, 2 * idx + 1, b.start..m);
        self._set(&r, v, 2 * idx + 2, m..b.end);
    }
    fn get(&self, i: &usize) -> isize {
        self._get(i, 0, 0..self.n)
    }
    fn _get(&self, i: &usize, idx: usize, b: Range<usize>) -> isize {
        if b.len() == 1 {
            return self.tree[idx];
        }
        let m = (b.end + b.start) / 2;
        if *i < m {
            return self.tree[idx] + self._get(i, 2 * idx + 1, b.start..m);
        } else {
            return self.tree[idx] + self._get(i, 2 * idx + 2, m..b.end);
        }
    }
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

#![allow(unused)]

use std::ops::Range;

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let q: usize = scan.next();
    let st = SegmentTree::new(&vec![0_isize; n]);

    for _ in 0..q {
        let wht: u8 = scan.next();
        if wht == 1 {
            let l: usize = scan.next();
            let r: usize = scan.next();
            let v: isize = scan.next();
        } else {
            let i: usize = scan.next();
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

struct SegmentTree {
    n: usize,
    sz: usize,
    tree: Vec<isize>,
}
impl SegmentTree {
    fn new(vec: &Vec<isize>) -> Self {
        let n = (1 << ((vec.len() as f64).log2().ceil() as usize));
        let mut sz = 2 * n - 1;
        let tree = vec![0_isize; sz];
        let mut st = Self { n, sz, tree };
        st
    }
    fn show(&self) {
        println!("{:?}", self.tree);
    }
    fn set(&mut self, r: &Range<usize>, val: &isize) {
        self._set(r, val, 0, 0..self.n);
    }
    fn _set(&mut self, r: &Range<usize>, val: &isize, i: usize, b: Range<usize>) {
        if r.end <= b.start || r.start >= b.end {
            return;
        }
        if r.start >= b.start && r.end >= b.end {
            self.tree[i] = self.tree[i].max(*val);
            return;
        }
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

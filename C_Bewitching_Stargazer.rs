#![allow(unused)]

fn rec(l: usize, r: usize, k: &usize, ln: usize) -> usize {
    if r - l + 1 < *k {
        return 0;
    }
    if r - l + 1 == 1 {
        return l;
    }
    let mut m = (r + l) / 2;
    if (r - l + 1) % 2 == 1 {
        return m + rec(l, m - 1, k, ln + m) + (r - l + ln);
    } else {
        return rec(l, m, k, ln + m);
    }
}
fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let k: usize = scan.next();
    rec(1, n, &k, (n + 1) / 2).println();
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
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
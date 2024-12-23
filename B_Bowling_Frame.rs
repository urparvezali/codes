#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let w: i64 = scan.next();
    let b: i64 = scan.next();
    let total = w + b;
    let (mut l, mut r) = (0, total);

    let mut m = 0;
    let mut calc = 0;
    while l <= r {
        m = (l + r) / 2;
        calc = m * (m + 1) / 2;
        if calc == total {
            r = m;
            break;
        } else if calc < total {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    println!("{}", r);
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

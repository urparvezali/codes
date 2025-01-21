#![allow(unused)]
fn groupby(vc: Vec<u8>) -> Vec<u8> {
    let mut res = Vec::new();
    let mut prev: Option<u8> = None;

    for u in vc {
        if let Some(p) = prev {
            if p != u {
                res.push(u);
                prev = Some(u);
            }
        } else {
            prev = Some(u);
            res.push(u);
        }
    }
    res
}
fn solve(scan: &mut Scanner, case: usize) {
    let s: Vec<u8> = scan
        .next::<String>()
        .chars()
        .map(|c| c as u8 - 48)
        .collect();

    let v = groupby(s);
    let mut cnt = 0;
    let mut ans = 0_usize;

    for &u in &v {
        cnt += u;
        if cnt < 0 {
            cnt = 0;
        }
        ans = ans.max(cnt as usize);
    }
    (v.len() - ans).println();
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

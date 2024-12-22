#![allow(unused)]
// #![allow(overlapping_range_endpoints)]

fn solve(scan: &mut Scanner, case: usize) {
    let k: i64 = scan.next();

    let mut l1: i64 = scan.next();
    let mut r1: i64 = scan.next();

    let mut l2: i64 = scan.next();
    let mut r2: i64 = scan.next();

    let mut ans = 0;
    for i in 0..32 {
        let kv = k.checked_pow(i).unwrap_or(i64::MAX);
        let mn_x = (l2 as f64 / kv as f64).ceil() as i64;
        let mx_x = (r2 as f64 / kv as f64).floor() as i64;
        let l = if mn_x <= l1 { l1 } else { mn_x };
        let r = if mx_x < r1 { mx_x } else { r1 };
        ans += (r - l + 1).max(0);
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

#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let ss: Vec<char> = scan.next::<String>().chars().collect();
    let b: i64 = scan.next();
    let s: i64 = scan.next();
    let c: i64 = scan.next();
    let pb: i64 = scan.next();
    let ps: i64 = scan.next();
    let pc: i64 = scan.next();
    let rubble = scan.next();
    let (mut bn, mut sn, mut cn) = (0, 0, 0);
    for c in ss {
        match c {
            'B' => bn += 1,
            'S' => sn += 1,
            _ => cn += 1,
        };
    }
    let (mut l, mut r) = (0, 1e15 as i64);
    let mut m = (l + r) >> 1;
    let mut x: i64 = 0;
    let mut ans = 0;
    while l <= r {
        m = (l + r) / 2;
        x = 0.max(bn * m - b) * pb + 0.max(sn * m - s) * ps + 0.max(cn * m - c) * pc;
        if x <= rubble {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    ans.println();
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
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

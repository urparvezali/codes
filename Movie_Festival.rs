#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut v: Vec<(usize, usize)> = vec![(0, 0); n];
    for i in 0..n {
        v[i].0 = scan.next();
        v[i].1 = scan.next();
    }
    v.sort_by(|a, b| {
        let ord = a.1.cmp(&b.1);
        if ord == std::cmp::Ordering::Equal {
            a.0.cmp(&b.0)
        } else {
            ord
        }
    });
    let mut ans = 0;
    let mut last: Option<usize> = None;
    for (f, s) in &v {
        if last.is_none() {
            ans += 1;
            last = Some(*s);
            continue;
        }
        if last.unwrap() < *f {
            last = Some(*s);
            ans += 1;
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
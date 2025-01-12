#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let maxdif: i64 = scan.next();
    let mut v: Vec<(i64, i64)> = vec![(0, 0); n];
    for i in 0..n {
        v[i].0 = scan.next();
        v[i].1 = scan.next();
    }
    v.sort();

    let (mut l, mut r) = (0, 0);
    let (mut sum, mut ans) = (0, 0);
    while r < n && l <= r {
        if r == 0 {
            sum += v[r].1;
            ans = ans.max(sum);
			r+=1;
        } else if v[r].0 - v[l].0 < maxdif {
			sum += v[r].1;
            ans = ans.max(sum);
            r += 1;
        } else {
            sum -= v[l].1;
            l += 1;
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

#![allow(unused)]

fn solve(sc: &mut Scanner, case: usize) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let k: usize = sc.next();
    let v = sc.vec::<usize>(m+1);

    let mut ans = -1;
    let mut cnt = 0;

    for x in &v {
		let mut x = x.clone();
        x = x ^ v[m];
        cnt = 0;
        while x > 0 {
            x = x & (x - 1);
            cnt += 1;
        }
        if cnt <= k {
            ans += 1;
        }
    }
    ans.println();
}

fn main() {
    let mut sc = Scanner::new();
    let t: usize = 1;
    // let t: usize = sc.next();
    (1..=t).for_each(|case| solve(&mut sc, case));
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

#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut v = scan.vec::<i64>(n);
    v.sort();
    if n == 1 {
        1.println();
        return;
    }
    let mut distance = Vec::with_capacity(n);
    for i in (0..n - 1).step_by(2) {
        distance.push(v[i + 1] - v[i]);
    }
    if n % 2 == 0 {
        distance.iter().max().unwrap().println();
        return;
    }
    let mut distance2 = Vec::with_capacity(n);
    let mut i: isize = n as isize - 1;
    while i > 0 {
        distance2.push(v[i as usize] - v[i as usize - 1]);
        i -= 2;
    }
    distance2.reverse();
    let mut dp1 = Vec::with_capacity(n);
    let mut dp2 = Vec::with_capacity(n);

    let (mut mx) = (0);
    for i in 0..distance.len() {
        mx = mx.max(distance[i]);
        dp1.push(mx);
    }
    mx = 0;
    for i in (0..distance2.len()).rev() {
        mx = mx.max(distance2[i]);
        dp2.push(mx);
    }
    dp2.reverse();

	v.println();
    dp1.println();
	dp2.println();
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

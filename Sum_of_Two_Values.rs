#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let t: usize = scan.next();
    let vv: Vec<usize> = scan.vec(n);
    let mut v: Vec<(usize, usize)> = vec![(0, 0); n];
    for i in 0..n {
        v[i].0 = vv[i];
        v[i].1 = i+1;
    }
    v.sort();
    let (mut l, mut r) = (0, n - 1);
    while l < r {
        if v[l].0 + v[r].0 == t {
            break;
        } else if v[l].0 + v[r].0 > t {
            r -= 1;
        } else {
            l += 1;
        }
    }
	if l==r || v[l].0 + v[r].0 != t || v.len()<=1{
		println!("IMPOSSIBLE");return;
	}
    println!("{} {}", v[l].1.min(v[r].1), v[l].1.max(v[r].1));
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

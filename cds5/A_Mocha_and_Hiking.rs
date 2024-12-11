#![allow(unused)]
fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let v: Vec<usize> = scan.vec(n);
    if v.first().unwrap() == &1 {
        print!("{} ", n + 1);
        for number in 1..=n {
            print!("{} ", number);
        }
		println!();
        return;
    }
    if v.last().unwrap() == &0 {
        for number in 1..=n + 1 {
            print!("{} ", number);
        }
		println!();
        return;
    }
    for i in 0..v.len() - 1 {
        if v[i] == 0 && v[i + 1] == 1 {
            for j in 1..=i + 1 {
                print!("{} ", j);
            }
            print!("{} ", n + 1);
            for j in i + 2..=n {
                print!("{} ", j);
            }
			println!();
            return;
        }
    }
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

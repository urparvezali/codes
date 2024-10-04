#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut mat: Vec<Vec<i32>> = Vec::new();
    for i in 0..n {
        mat.push(scan.vec(5));
    }
    let mut mins = vec![i32::MAX; 5];
    for i in 0..5 {
        for j in 0..n {
            mins[i] = mat[j][i].min(mins[i]);
        }
    }
    let mut counts = vec![0; n];
    for j in 0..5 {
        for i in 0..n {
            counts[i] += if mins[j] == mat[i][j] { 1 } else { 0 };
        }
    }
    let mx = *counts.iter().max().unwrap();
	counts.println();
    let mut cnt = 0;
    counts.iter().for_each(|&val| {
        if val == mx {
            cnt += 1;
        }
    });
    if cnt > 1 {
        println!("-1");
    } else {
        counts.iter().enumerate().for_each(|(i, j)| {
            if *j == mx {
                (i+1).println();
                return;
            }
        });
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

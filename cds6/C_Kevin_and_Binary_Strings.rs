#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let v: Vec<char> = scan.next::<String>().chars().collect();
    let mut idx: Option<usize> = None;
    let mut cnt = 0;
    for i in 0..v.len() {
        if v[i] == '0' && idx.is_none() {
            idx = Some(i+1);
            cnt += 1;
        }
        if v[i] == '0' && idx.is_some() {
            cnt += 1;
        }
        if idx.is_some() && v[i] == '1' {
            break;
        }
    }
    if idx.is_none() {
        println!("1 {} 1 1", v.len());
        return;
    }
    println!(
        "1 {} {} {}",
        v.len(),
        idx.unwrap() - idx.unwrap().min(cnt)+1,
        v.len() - idx.unwrap().min(cnt)+1
    );
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

#![allow(unused)]
fn valid(a: i32, b: i32, c: i32) -> bool {
    !(a + b <= c || b + c <= a || c + a <= b)
}
fn get_number(b: i32, c: i32, arr: &Vec<i32>) -> Option<i32> {
    let (mut l, mut r) = (0, arr.len() - 1);
    let mut m = 0;
    let mut calc = 0;
    while l <= r {
        m = (l + r) / 2;
        if arr[m] > b + c && valid(arr[m], b, c) {
            return Some(arr[m]);
        }
        if arr[m] < b + c {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    Some(arr[r])
}
fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let mut v: Vec<i32> = scan.vec(n);
    let mut sorted = v.clone();
    sorted.sort();
	let mut ans = 0;
    for i in 0..n - 2 {
        if !valid(v[i], v[i + 1], v[i + 2]) {
            // v[i] = get_number(v[i + 1], v[i + 2], &sorted).unwrap();
			ans+=1;
        }
    }
	ans.println();
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

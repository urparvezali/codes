#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let (n, m, k) = (
        scan.next::<usize>(),
        scan.next::<usize>(),
        scan.next::<usize>(),
    );
    let questions = scan.vec::<usize>(m);
    let can_do = scan.vec::<usize>(k);

    let mut check = vec![false; n + 1];
    can_do.iter().for_each(|&i| check[i as usize] = true);

    let mut ans = String::with_capacity(n);
    for i in 0..m {
        if k==n || (k==n-1 && !check[questions[i]]) {
            ans.push('1');
        }else {
			ans.push('0');
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

#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let m: usize = scan.next();
    let k: i32 = scan.next();
    let mut app = scan.vec::<i32>(n);
    let mut avl = scan.vec::<i32>(m);
    app.sort();
    avl.sort();

    let taken = vec![false; avl.len()];
    let mut idx = 0;
    let mut ans = 0;
    for i in 0..app.len() {
        for j in idx..avl.len() {
            if avl[j] >= app[i] - k && avl[j] <= app[i] + k {
                ans += 1;
                idx = j + 1;
                break;
            }
			if j == avl.len()-1 {
				idx=avl.len();
			}
			if avl[j]>app[i]+k {
				idx=j;
				break;
			}
        }
    }
	ans.println();
}

fn main() {
    let mut scan = Scanner::new();
    let t: usize = 1;
    // let t: usize = scan.next();
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

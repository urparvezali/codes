#![allow(unused)]

fn solve(scan: &mut Scanner, case: usize) {
    let n: usize = scan.next();
    let t: usize = scan.next();
    let v: Vec<usize> = scan.vec(&n);

    let mut dp = vec![1e9 as usize; t + 1];
	dp[0]=0;
    for i in 1..t + 1 {
        for j in 0..n {
            if i as isize - v[j] as isize >= 0 {
                dp[i] = dp[i].min(dp[i - v[j]] + 1);
            }
			dp.println();
        }
    }
	// dp.println();
    if dp[t] == 1e9 as usize {
        "-1".println();
    } else {
        dp[t].println();
    }
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
        (0..self.len() - 1).for_each(|u| print!("{} ", self[u]));
        (0.max(self.len() - 1)..self.len()).for_each(|u| println!("{}", self[u]));
    }
}
struct Scanner {
    arr: Vec<String>,
}
impl Scanner {
    fn new() -> Self {
        Self {
            arr: Vec::default(),
        }
    }
    fn next<T: std::str::FromStr>(&mut self) -> T
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        match self.arr.pop() {
            Some(s) => s.parse().unwrap(),
            None => {
                let mut input = String::new();
                std::io::stdin().read_line(&mut input).unwrap();
                self.arr = input
                    .split_whitespace()
                    .rev()
                    .map(|s| s.to_string())
                    .collect();
                self.arr.pop().unwrap().parse().unwrap()
            }
        }
    }
    fn vec<T: std::str::FromStr>(&mut self, n: &usize) -> Vec<T>
    where
        <T as std::str::FromStr>::Err: std::fmt::Debug,
    {
        (0..*n)
            .map(|_| match self.arr.pop() {
                Some(s) => s.parse().unwrap(),
                None => {
                    let mut input = String::default();
                    std::io::stdin().read_line(&mut input).unwrap();
                    self.arr = input
                        .split_whitespace()
                        .rev()
                        .map(|s| s.to_string())
                        .collect();
                    self.arr.pop().unwrap().parse().unwrap()
                }
            })
            .collect()
    }
}

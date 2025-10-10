use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn is_interleave(&self, s1: String, s2: String, s3: String) -> bool {
        let mut dp: HashMap<(usize, usize), bool> = HashMap::new();
        fn rec(
            i: usize,
            j: usize,
            k: usize,
            s1: &String,
            s2: &String,
            s3: &String,
            dp: &mut HashMap<(usize, usize), bool>,
        ) -> bool {
            if i == s1.len() && j == s2.len() {
                return true;
            }
            if let Some(&res) = dp.get(&(i, j)) {
                return res;
            }
            let mut ok = false;
            if i < s1.len() && s1[i..i + 1] == s3[k..k + 1] {
                ok |= rec(i + 1, j, k + 1, s1, s2, s3, dp);
            }
            if j < s2.len() && s2[j..j + 1] == s3[k..k + 1] {
                ok |= rec(i, j + 1, k + 1, s1, s2, s3, dp);
            }
            dp.insert((i, j), ok);
            ok
        }
        rec(0, 0, 0, &s1, &s2, &s3, &mut dp)
    }
}
fn solve(scan: &mut Scanner, case: usize) {
    let sol = Solution::new();
    let s1: String = scan.next();
    let s2: String = scan.next();
    let s3: String = scan.next();
    println!("{}", sol.is_interleave(s1, s2, s3));
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

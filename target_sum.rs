#![allow(unused)]

use std::collections::HashMap;

fn solve(scan: &mut Scanner, case: usize) {
    let nums = vec![1, 1, 1, 1, 1];
    let target = 3;
    let mut dp: HashMap<(usize, i32), i32> = HashMap::new();
    fn rec(
        i: usize,
        target: &i32,
        sum: i32,
        nums: &Vec<i32>,
        dp: &mut HashMap<(usize, i32), i32>,
    ) -> i32 {
        if i == nums.len() {
            if sum == *target {
                return 1;
            } else {
                return 0;
            }
        }
        if let Some(&result) = dp.get(&(i, sum)) {
            return result;
        }

        let result = rec(i + 1, target, sum + nums[i], nums, dp)
            + rec(i + 1, target, sum - nums[i], nums, dp);

        dp.insert((i, sum), result);
        result
    }
    println!("{}", rec(0, &target, 0, &nums, &mut dp));
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

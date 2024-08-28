struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn rob(&self, nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![0; 1];
        dp.extend(nums.iter());
        for i in (3..n+1) {
			dp[i] += dp[i - 2].max(dp[i - 3]);
        }
        dp[n].max(dp[n - 1])
    }
}

fn solve(scan: &mut Scanner, case: usize) {
    let sol = Solution::new();
    let nums = vec![2, 7, 9, 3, 1];
    sol.rob(nums).println();
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

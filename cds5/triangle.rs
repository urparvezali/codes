struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn minimum_total(&self, triangle: Vec<Vec<i32>>) -> i32 {
        let n = triangle.len();
        let mut dp = triangle.clone();
        for i in (0..n - 1).rev() {
            for j in 0..i + 1 {
                dp[i][j] += dp[i + 1][j].min(dp[i + 1][j + 1]);
            }
        }
        dp[0][0]
    }
}

fn main() {
    let sol = Solution::new();
    let triangle = vec![vec![2], vec![3, 4], vec![6, 5, 7], vec![4, 1, 8, 3]];
    println!("{}", sol.minimum_total(triangle));
}

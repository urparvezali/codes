struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn coin_change(&self, coins: Vec<i32>, amount: i32) -> i32 {
        let n = coins.len();
        let mut dp = vec![i32::MAX; amount as usize + 1];
        dp[0] = 0;
        for i in 0..amount as usize + 1 {
            for &coin in &coins {
                if i as i32 - coin >= 0 && dp[i - coin as usize] != i32::MAX {
                    dp[i] = dp[i].min(dp[i - coin as usize] + 1)
                }
            }
        }
        if dp[amount as usize] == i32::MAX {-1}else{dp[amount as usize]}
    }
}

fn main() {
    let sol = Solution::new();
    let coins = vec![2];
    let amount = 3;
    println!("{}", sol.coin_change(coins, amount));
}

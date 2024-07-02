struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn find_target_sum_ways(&self, nums: Vec<i32>, target: i32) -> i32 {
        let mut dp = vec![vec![0; nums.len()]; nums.len()];
        dp[0] = nums.clone();
        for i in 0..dp.len() {
            dp[i][0] = nums[i];
        }
        println!("{:?}", dp);
        4
    }
}

fn main() {
    let nums = vec![1, 1, 1, 1, 1];
    let target = 3;
    let sol = Solution::new();
    let _ = sol.find_target_sum_ways(nums, target);
}

struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    fn length_of_lis(&self, nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut dp = vec![1; n];

        for i in (0..n).rev() {
            let mut mx = 0;
            for j in i + 1..n {
                if nums[j] > nums[i] {
                    mx = mx.max(dp[j]);
                }
            }
            dp[i] += mx;
        }
        *dp.iter().max().unwrap()
    }
}

fn main() {
    let sol = Solution::new();
    let nums = vec![7,7,7,7,7];
    println!("{}", sol.length_of_lis(nums));
}

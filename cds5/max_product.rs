struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn max_product(&self, nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut prefix = nums.clone();
        let mut suffix = nums.clone();
        for i in 1..n {
            if prefix[i-1] == 0 {
                continue;
            }
            prefix[i] *= prefix[i - 1];
        }
        for i in (0..n - 1).rev() {
            if suffix[i+1] == 0 {
                continue;
            }
            suffix[i] *= suffix[i + 1];
        }
        let mut ans = i32::MIN;
        for i in 0..n {
            ans = ans.max(prefix[i].max(suffix[i].max(nums[i])));
        }
		println!("{:?}",prefix);
		println!("{:?}",suffix);
        ans
    }
}

fn main() {
    let sol = Solution::new();
    let nums = vec![-1,-2,-3,0];
    println!("{:?}", sol.max_product(nums));
}

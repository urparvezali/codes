struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let n = nums.len();
        let total: i32 = nums.iter().sum();
		if total%p == 0 {return 0}
		
		-1
    }
}

fn main() {
    let sol = Solution::new();
}

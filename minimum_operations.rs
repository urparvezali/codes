use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut mp = HashMap::new();
        for &ele in &nums {
            *mp.entry(ele).or_insert(0) += 1;
        }
		let mut ans = 0;
        for i in 0..nums.len() {
            if let Some(x) = mp.get_mut(&nums[i]) {
				if *x > 1 {
					ans = ((i as f32 + 1.0)/3.0).ceil() as i32;
				}
				*x -= 1;
            }
        }
		ans
    }
}

fn main() {
    let sol = Solution::new();
}

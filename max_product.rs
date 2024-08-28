struct Solution;
impl Solution {
	pub fn new() -> Self {
		Self {}
	}
	pub fn max_product(&self, nums: Vec<i32>) -> i32{
		let n = nums.len();
		let mut dp = nums.clone();
		
		for i in 0..n {
			for j in 0..i+1 {
				
			}
		}
		
		i32::MIN
	}
}


fn main() {
	let sol = Solution::new();
	let nums = vec![2,3,-2,4];
	println!("{:?}", sol.max_product(nums));
}
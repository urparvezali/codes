
struct Solution;
impl Solution {
	fn new() -> Self{
		Self{}
	}
    pub fn length_of_lis(&self, nums: Vec<i32>) -> i32 {
		fn rec(i:usize,nums:&Vec<i32>) -> i32 {
			if i==nums.len() {
				return 0;
			}
			let mut mx = 0;
			for j in i+1..nums.len() {
				if nums[j]>nums[i] {
					mx=mx.max(1+rec(j, nums));
				}
			}
			mx
		}
		let mut ans = 0;
		for i  in 0..nums.len() {
			ans = ans.max(1+rec(i, &nums));
		}
		ans
	}
}

fn solve() {
    let nums: Vec<i32> = vec![7,7,7,7,7,7,7];
	let sol = Solution::new();
	println!("{}",sol.length_of_lis(nums));
}

fn main() {
    let t: usize = 1;
    // let t: usize = scan.next();
    (0..t).for_each(|case| solve());
}
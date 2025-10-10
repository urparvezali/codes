struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn length_of_lis(&self, nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans = 1;
        fn rec(i: usize, nums: &Vec<i32>) -> i32 {
            let mut mx = 1;
            for j in i + 1..nums.len() {
                if nums[j] > nums[i] {
                    mx = mx.max(1 + rec(j, nums));
                }
            }
            mx
        }
        for idx in 0..n {
            ans = ans.max(rec(idx, &nums));
        }
        ans
    }
}

fn main() {
    let sol = Solution::new();
    let nums = vec![10, 9, 2, 5, 3, 7, 101, 18];
    println!("{}", sol.length_of_lis(nums));
    let nums = vec![0, 1, 0, 3, 2, 3];
    println!("{}", sol.length_of_lis(nums));
}

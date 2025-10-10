struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn num_decoding(&self, s: String) -> i32 {
        let n = s.len();
        let mut dp = vec![0; n + 1];

        for i in 0..n + 1 {
			
		}

        dbg!(dp.clone());
        dp[n]
    }
}

fn main() {
    let sol = Solution::new();
    let s = "226".to_string();
    println!("{}", sol.num_decoding(s));
}

// 2 2 6
// 22 6
// 2 26

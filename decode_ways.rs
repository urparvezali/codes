use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn new() -> Self {Self{}}
    pub fn num_decodings(&self,s: String) -> i32 {
		let mut dp: HashMap<usize,i32> = HashMap::new();
		fn rec(i:usize,s:&String,dp:&mut HashMap<usize,i32>) -> i32 {
			if i>= s.len() {
				return 1;
			}
			if let Some(&res)=dp.get(&i) {
				return res;
			}
			let mut z = 0;
			if i+1<s.len() && s[i..i+2].parse::<i32>().unwrap()<=26 && s[i..i+1]!=*"0" {
				z +=rec(i+2, s, dp);
			}
			if s[i..i+1]!=*"0" {
				z+= rec(i+1, s, dp);
			}
			dp.insert(i, z);
			z
		}
		rec(0, &s, &mut dp)
	}
}

fn main() {
    let sol = Solution::new();
	let s = "12".to_string();
	println!("{}",sol.num_decodings(s));
}

use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn longest_common_subsequence(&self, text1: String, text2: String) -> i32 {
        let mut map: HashMap<(usize, usize), i32> = HashMap::new();
        fn rec(
            i: usize,
            j: usize,
            text1: &String,
            text2: &String,
            map: &mut HashMap<(usize, usize), i32>,
        ) -> i32 {
            if i == text1.len() || j == text2.len() {
                return 0;
            }
			if let Some(&res) = map.get(&(i,j)){
				return res;
			}
            if text1[i..i + 1] != text2[j..j + 1] {
				let res = rec(i + 1, j, text1, text2, map).max(rec(i, j + 1, text1, text2, map));
				map.insert((i,j), res);
				return res;
            }
            let res = 1 + rec(i + 1, j + 1, text1, text2, map);
			map.insert((i,j), res);
			res
        }
        rec(0, 0, &text1, &text2, &mut map)
    }
}

fn main() {
    let sol = Solution::new();
    let text1 = "abcde".to_string();
    let text2 = "ace".to_string();
    println!("{}", sol.longest_common_subsequence(text1, text2));
}

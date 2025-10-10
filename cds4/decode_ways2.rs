use std::collections::HashMap;

struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn num_decodings(&self, s: String) -> i32 {
        let mut dp: HashMap<usize, isize> = HashMap::new();
        fn rec(i: usize, s: &String, dp: &mut HashMap<usize, isize>) -> isize {
            if i >= s.len() {
                return 1;
            }
            if let Some(&res) = dp.get(&i) {
                return res;
            }
            let mut z = 0;
            if i + 1 < s.len() && s[i..i + 1] != *"0" {
                match s[i..i + 2].parse::<isize>() {
                    Ok(val) => {
                        if val <= 26 {
                            z = (z + rec(i + 2, s, dp)) % 1000000007;
                        }
                    }
                    Err(_) => {
                        if s[i..i + 2] == *"**" {
                            z = (z + (15 * rec(i + 2, s, dp)) % 1000000007) % 1000000007;
                        } else {
                            if let Ok(val) = s[i + 1..i + 2].parse::<isize>() {
                                if val <= 6 {
                                    z = (z + (2 * rec(i + 2, s, dp)) % 1000000007) % 1000000007;
                                } else {
                                    z = (z + rec(i + 2, s, dp)) % 1000000007;
                                }
                            }
                            if let Ok(val) = s[i..i + 1].parse::<isize>() {
                                if val == 1 {
                                    z = (z + (9 * rec(i + 2, s, dp)) % 1000000007) % 1000000007;
                                } else if val == 2 {
                                    z = (z + (6 * rec(i + 2, s, dp)) % 1000000007) % 1000000007;
                                }
                            }
                        }
                    }
                };
            }
            if s[i..i + 1] != *"0" {
                if s[i..i + 1] == *"*" {
                    z = (z + (9 * rec(i + 1, s, dp)) % 1000000007) % 1000000007;
                } else {
                    z = (z + rec(i + 1, s, dp)) % 1000000007;
                }
            }
            dp.insert(i, z);
            z
        }
        rec(0, &s, &mut dp) as i32
    }
}

fn main() {
    let sol = Solution::new();
    let s = "7*9*3*6*3*0*5*4*9*7*3*7*1*8*3*2*0*0*6*".to_string();
    println!("{}", sol.num_decodings(s));
}

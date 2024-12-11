use std::collections::{HashMap, HashSet};
struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn find_judge(&self, n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut believer: HashSet<i32> = HashSet::new();
        let mut believed: HashMap<i32, i32> = HashMap::new();

        for v in trust {
			let (a,b) = (v[0], v[1]);
            believer.insert(a);
            *believed.entry(b).or_insert(0) += 1;
        }
        for i in 1..n + 1 {
			if believer.contains(&i) == false {
				if let Some(&res) = believed.get(&i) {
					if res == n-1 {
                        return i;
                    }
                }
            }
        }
        -1
    }
}

fn main() {
    let sol = Solution::new();
    println!(
        "{}",
        sol.find_judge(
            2,
            vec![vec![1, 2]]
        )
    )
}

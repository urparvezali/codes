use std::collections::HashMap;
struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn can_arrange(&self, arr: Vec<i32>, k: i32) -> bool {
        let n = arr.len();
        let mut map: HashMap<i32, i32> = HashMap::new();

        for &val in &arr {
            let r = (val % k + k) % k;
            *map.entry(r).or_insert(0) += 1;
        }

        for i in 1..k / 2 + 1 {
            let (left, right) = (*map.entry(i).or_default(), *map.entry(k - i).or_default());
            if left != right {
                return false;
            }
        }
        true
    }
}

fn main() {
    let sol = Solution::new();
    println!("{:?}", sol.can_arrange(vec![1, 2, 3, 4, 5, 6], 7));
}

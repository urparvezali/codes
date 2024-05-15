struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn num_rescue_boats(&self, people: Vec<i32>, limit: i32) -> i32 {
        let mut people = people.clone();
        people.sort_by(|a, b| b.cmp(a));
        let mut ans = 0;
        let (mut i, mut j) = (0, people.len() - 1);
        while i <= j {
            if people[i] + people[j] <= limit {
                i += 1;
                j -= 1;
                ans += 1;
            } else {
                i += 1;
                ans += 1;
            }
        }
        ans
    }
}

fn main() {
    let sol = Solution::new();
    let people = vec![3, 5, 3, 4];
    let limit = 5;
    println!("{}",sol.num_rescue_boats(people, limit));
}

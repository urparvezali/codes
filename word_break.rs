use std::{collections::HashSet, iter::FromIterator};

struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn word_break(&self, s: String, word_dict: Vec<String>) -> bool {
        let mut st: HashSet<String> = HashSet::from_iter(word_dict.into_iter());
		
        true
    }
}

fn main() {
    let sol = Solution::new();
    println!(
        "{}",
        sol.word_break(
            "iloveyou".to_string(),
            vec!["i".to_string(), "love".to_string(), "you".to_string()]
        )
    );
}
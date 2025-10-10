struct Solution;
impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut ans = vec![];
        Self::rec(1, &n, &mut ans);
        ans
    }
    pub fn rec(i: i32, n: &i32, ans: &mut Vec<i32>) {
        if i > *n {
            return;
        }
        ans.push(i);
        Self::rec(i * 10, n, ans);
        if (i + 1) % 10 != 0 {
            Self::rec(i + 1, n, ans);
        }
    }
}

fn main() {
    println!("{:?}", Solution::lexical_order(34));
}

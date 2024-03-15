use std::collections::HashSet;

fn main() {
    let nums = vec![-3, -2, -1, 0, 0, 1, 2, 3];
    let target = 0;
    let mut nums: Vec<i32> = nums.clone();
    let target = target as isize;
    let n = nums.len();
    let mut ans: HashSet<Vec<i32>> = HashSet::new();
    nums.sort();

    for i in 0..n - 3 {
        for j in i + 1..n - 2 {
            let (mut l, mut r) = (j + 1, n - 1);
            while l < r {
                let t = nums[i] as isize + nums[j] as isize + nums[l] as isize + nums[r] as isize;
                if t == target {
                    ans.insert(vec![nums[i], nums[j], nums[l], nums[r]]);
                    break;
                } else if t > target {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
    }
    let ans: Vec<Vec<i32>> = ans.into_iter().collect();
    println!("{:?}", ans);
}

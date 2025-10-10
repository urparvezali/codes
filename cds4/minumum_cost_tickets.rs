struct Solution;
impl Solution {
    pub fn new() -> Self {
        Self {}
    }
    pub fn mincost_tickets(&self, days: Vec<i32>, costs: Vec<i32>) -> i32 {
        Self::rec(&self, 0, &days, &costs)
    }
    fn rec(&self, i: usize, days: &Vec<i32>, costs: &Vec<i32>) -> i32 {
        if i >= days.len() {
            return 0;
        }
        let one = costs[0] + self.rec(i + 1, days, costs);
        let mut idx = i+1;
        for n in i + 1..days.len() {
			if days[n] > days[i] + 6 {
				idx = n;
                break;
            } else if n == days.len() - 1 {
				idx = days.len();
            }
        }
        let seven = costs[1] + self.rec(idx, days, costs);
		let mut idx = i+1;
        for n in i + 1..days.len() {
            if days[n] > days[i] + 29 {
                idx = n;
                break;
            } else if n == days.len() - 1 {
                idx = days.len();
            }
        }
        let thirty = costs[2] + self.rec(idx, days, costs);
        one.min(seven).min(thirty)
    }
}

fn main() {
    let days = vec![1, 4, 6, 7, 8, 20];
    let costs = vec![2, 7, 15];
    let solution = Solution::new();
    println!("{}", solution.mincost_tickets(days, costs));
}

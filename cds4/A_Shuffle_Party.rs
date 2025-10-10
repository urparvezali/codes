#[allow(unused)]
use std::io::{stdin, BufRead};

fn main() {
    let mut lines = stdin().lock().lines().map(|f| f.unwrap());
    let t: usize = 1;
    let t: usize = lines.next().unwrap().parse().unwrap();
    (0..t).for_each(|case| solve(&mut lines, case + 1));
}

fn solve(lines: &mut dyn Iterator<Item = String>, case: usize) {
    let n: usize = lines.next().unwrap().parse().unwrap();
	let ans = 2_isize.pow(f64::log2(n as f64) as u32);
	println!("{}",ans);
}

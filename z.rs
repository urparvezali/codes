use std::io::{stdin, BufRead};

fn main() {
    let v = stdin()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split_whitespace()
        .map(|w| w.parse().unwrap())
        .collect::<Vec<isize>>();
	// groupby in rust is not available
}

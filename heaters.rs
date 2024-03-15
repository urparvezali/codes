use std::cmp::min;

fn solution() {
    read!(houses<i32>);
    read!(heaters<i32>);
	let mut houses = houses.clone();
	let mut heaters = heaters.clone();
    houses.sort();
    heaters.sort();
    let mut ans: i32 = 0;
    for i in &houses {
        let p = match heaters.binary_search(i) {
            Ok(idx) => idx,
            Err(idx) => idx,
        };
        if heaters.len() > p && heaters[p] == *i {
            continue;
        }
        if p == 0 {
            ans = ans.max(heaters[0].abs_diff(*i) as i32);
            continue;
        } else if p == heaters.len() {
            ans = ans.max(heaters[p - 1].abs_diff(*i) as i32);
            continue;
        }
        ans = ans.max(min(heaters[p].abs_diff(*i), heaters[p - 1].abs_diff(*i)) as i32);
    }
    write!(ans);
}
fn main() {
    let t = 3;
    // read!(t:isize);
    for _ in 0..t {
        solution();
    }
}
#[macro_export]
macro_rules! write {
	($name:ident<char>) => {
		for i in &$name{
			print!("{}",i);
		}
		println!();
	};
	($name:ident<$type:ty>) => {
		for i in &$name{
			print!("{} ",i);
		}
		println!();
	};
	($($name:expr),*) => {
		$(print!("{} ", $name);)*
		println!();
	};
}
#[macro_export]
macro_rules! read {
	($name:ident<char>) => {
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).unwrap();
		let mut $name: Vec<char>=input.chars().collect();
		input.clear();
	};
	($name:ident<$type:ty>) => {
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).unwrap();
		let mut $name:Vec<$type>=input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();
		input.clear();
	};
	($($name:ident:$type:ty), *) => {
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).unwrap();
		let mut it = input.trim().split_whitespace();
		$(
			let mut $name = it.next().unwrap().parse::<$type>().unwrap();
		)*
		input.clear();
	};
}

use std::collections::VecDeque;

#[allow(unused)]
fn solution() {
    read!(temperatures<i32>);
    let n = temperatures.len();
	let mut ans = vec![0;n];
    let mut d:Vec<(i32,usize)> = Vec::new();
	for i  in 0..n {
		if d.is_empty() {
			d.push((temperatures[i],i));
		} else if d.last().unwrap().0<temperatures[i] {
			while d.len()>0 && d.last().unwrap().0<temperatures[i] {
				ans[d.last().unwrap().1 as usize]=i-d.last().unwrap().1;
				d.pop();
			}
			d.push((temperatures[i],i));
		} else {
			d.push((temperatures[i],i));
		}
	}
    println!("{:?}",ans);
}
fn main() {
    let t: isize = 1;
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

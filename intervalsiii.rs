fn solution() {
	let intervals = vec![vec![0,2],vec![1,3],vec![2,4],vec![3,5],vec![4,6]];
	let mut intervals = intervals;
	intervals.sort();
	println!("{:?}",intervals);
	let mut ans=0;
	let mut mem=&intervals[0];
	for i in &intervals[1..]{
		if i[0]<mem[1] {
			if i[1]<mem[1] {
				ans+=1;
				mem=i;
			} else {
				ans+=1;
			}
		} else {
			mem=i;
		}
	}
	println!("{}",ans);
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

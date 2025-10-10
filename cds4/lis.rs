

fn solution() {
	read!(nums of i32);
	if nums.len()==0{
		write!(0);
		return;
	}
	let mut n:i32=nums.len() as i32;
	let mut dp:Vec<i32>=vec![1;n as u32];
	for i in 1..n{
		for j in 0..i{
			if nums[i]>nums[j]{
				dp[i]=std::cmp::max(dp[i], dp[j]+1);
			}
		}
	}
	let mut ans = dp.iter().max().cloned().unwrap();
	write!(ans);
}
fn main() {
	let t:isize=1;
	// read!(t:isize);
	for _ in 0..t {
		solution();
	}
}
#[macro_export]
macro_rules! write {
	($($name:tt),*) => {
		$(print!("{} ", $name);)*
		println!();
	};
	($name:tt of char) => {
		for i in &$name{
			print!("{}",i);
		}
		println!();
	};
	($name:tt of $type:tt) => {
		for i in &$name{
			print!("{} ",i);
		}
		println!();
	};
}
#[macro_export]
macro_rules! read {
	($($name:tt:$type:tt), *) => {
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).unwrap();
		let mut it = input.trim().split_whitespace();
		$(
			let mut $name = it.next().unwrap().parse::<$type>().unwrap();
		)*
		input.clear();
	};
	($name:tt of char) => {
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).unwrap();
		let mut $name: Vec<char>=input.chars().collect();
	};
	($name:tt of $type:tt) => {
		let mut input = String::new();
		std::io::stdin().read_line(&mut input).unwrap();
		let mut $name: Vec<$type>=input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();
	};
}

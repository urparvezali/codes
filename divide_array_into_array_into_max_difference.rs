#[allow(unused)]
fn solution() {
    let nums: Vec<i32> = vec![1,3,3,2,7,3];
    let k = 3;
    let mut n = nums.len();
    let mut nums = nums.clone();
    nums.sort();
    let mut ans: Vec<Vec<i32>> = vec![];
    for i in (0..n-1).step_by(3) {
		let mut newvec = vec![nums[i],nums[i+1],nums[i+2]];
		if nums[i+2]-nums[i]>k {
			print!("NONE");
			break;
		}
		ans.push(newvec);
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

use std::mem::swap;

fn solution() {
    read!(n:isize);
    read!(v of isize);
	let mut ans:isize=0;
    let mut x:isize=isize::MAX;
	let mut y:isize=isize::MAX;
    for i in &v {
		if x>y{
			swap(&mut x, &mut y);
		}
		if *i<=x{
			x=*i;
		} else if *i<=y{
			y=*i;
		} else {
			x=*i;
			ans+=1;
		}
    }
    write!(ans);
}
fn main() {
    let t: isize = 1;
    read!(t:isize);
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

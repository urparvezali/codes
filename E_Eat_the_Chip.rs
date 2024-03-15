fn solution() {
    read!(h:isize,w:isize,ya:isize,xa:isize,yb:isize,xb:isize);
}
fn main() {
    read!(t:isize);
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

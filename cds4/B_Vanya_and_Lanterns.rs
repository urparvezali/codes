
fn solution() {
    read!(n:usize,l:isize);
	read!(v<isize>);
	let mut mx:isize = 0;
	v.sort();
	mx=mx.max(v[0].max(l-v[n-1]));
	mx*=2;
	for i in 0..n-1{
		mx=mx.max(v[i+1]-v[i]);
	}
	write!(mx as f64/2 as f64);
}
fn main() {
    let t = 1;
    // read!(t:f64);
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

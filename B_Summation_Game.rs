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

fn solution() {
	read!(n:usize,k:usize,x:usize);
	read!(v<isize>);
	v.sort();
	let mut pre: Vec<isize> = vec![0; n];
	pre[0]=v[0];
	for i in 1..n {
		pre[i]=pre[i-1]+v[i];
	}
	// write!(pre<isize>);
	let mut ans:isize=pre[n-x]-pre[n-1]+pre[n-x];
	for i  in 0..=k {
			ans=ans.max(pre[n-i-x]-pre[n-i-1]+pre[n-i-x]);
	}
	write!(ans);
}

fn main() {
	read!(t:isize);
    for _ in 0..t {
        solution();
    }
}

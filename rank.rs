fn solution() {
	read!(score<i32>);
	let mut cln = score.clone();
	cln.sort_by(|a,b| b.cmp(a));
	let mut pos:Vec<String>=vec!["".to_string();1000001];
	let V=vec!["Gold Medal","Silver Medal","Bronze Medal"];
	for i in 0..cln.len(){
		if i<3 {
			pos[cln[i] as usize]=V[i].to_string();
		} else {
			pos[cln[i] as usize]=(i+1).to_string();
		}
	}
	let mut ans:Vec<String>=vec![];
	for i in score{
		ans.push(pos[i as usize].clone());
	}
	write!(ans<String>);
}
fn main() {
	let t: isize = 2;
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
		let $name:Vec<$type>=input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();
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

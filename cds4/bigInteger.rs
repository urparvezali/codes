fn solution() {
    read!(num1:String,num2:String);
	let num1:Vec<char>=num1.chars().collect();
	let num2:Vec<char>=num2.chars().collect();
    let mut carry: u8 = 0;
    let mut ans: Vec<u8> = vec![];
    let (mut a, mut b, mut n) = (
        num1.len(),
        num2.len(),
        std::cmp::max(num1.len(), num2.len()),
    );
    for i in 0..n {
        if i<a && i<b {
			let x = (num1[a-i-1] as u8)-('0' as u8);
			let y=(num2[b-i-1] as u8)-('0' as u8);
			ans.push((x+y+carry)%10);
			carry=(x+y+carry)/10;
			continue;
		}
		if i>=a {
			let y=(num2[b-i-1] as u8)-('0' as u8);
			ans.push((y+carry)%10);
			carry=(y+carry)/10;
		}
		if i>=b {
			let x = (num1[a-i-1] as u8)-('0' as u8);
			ans.push((x+carry)%10);
			carry=(x+carry)/10;
		}
    }
	if carry==1 {
		ans.push(1);
	}
	ans.reverse();
	let mut s = String::new();
	for i in &ans {
		s.push((*i+'0' as u8) as char);
	}
	write!(s);
}
fn main() {
    let t: isize = 3;
    // read!(t:isize);
    for _ in 1..=t {
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

fn main(){
	let mut input = String::new();
	std::io::stdin().read_line(&mut input).unwrap();
	if input.trim()=="4"{
		println!("YES");
	} else {
		println!("NO");
	}
}
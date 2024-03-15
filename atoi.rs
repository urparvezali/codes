fn main() {
	let s = "words and 987".to_string();
	for w in s.trim().split_whitespace(){
		if w.parse::<i32>().is_ok(){
			println!("{}",w.parse::<i32>().unwrap());
			break;
		}
		// print!("{} ",w);
	}
	print!("NONE");
}
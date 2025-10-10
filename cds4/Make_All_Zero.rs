use std::io::stdin;

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: isize = input.trim().parse().unwrap();
    for _ in 0..n {
        solution();
    }
}

fn solution() {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let n: isize = input.trim().parse().unwrap();
    input.clear();
    stdin().read_line(&mut input).unwrap();
    let v: Vec<isize> = input
        .trim()
        .split_whitespace()
        .map(|f| f.parse().unwrap())
        .collect();
    let mut min = Vec::new();
    for i in &v {
		if min.len()==0{
			min.push(*i);
			continue;
		}
		if i<=min.last().unwrap() {
			min.push(*i);
		}
	}
	let mut ans = n;
	min.reverse();
	for i in 0..min.len() as isize{
		ans=ans.min(n-i-1+min[i as usize]);
	}
	// for i in &min{
	// 	print!("{i} ");
	// }
	// println!();
	println!("{ans}");

}

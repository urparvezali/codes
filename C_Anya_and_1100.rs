fn main() {
    let mut mx = 0;
    let x = 193483;
    let m = 87248634;
    for y in 1..=m {
        if (y ^ x) < m {
            mx = mx.max(y ^ x);
        }
    }
    println!("{}", mx);
	println!("{:b}", (0b1010^0b11001));
}

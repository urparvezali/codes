pub fn is_prime(n: u32) -> bool {
    match n {
        ..2 => false,
        2..4 => true,
		_ if n%2 == 0 => false,
		_ if n%3 == 0 => false,
        _ => {
            for i in (5..((n << 1) + 1)).step_by(6) {
                if n % i == 0 || n % (i + 2) == 0 {
                    return true;
                }
            }
            false
        }
    }
}

fn main() {
    println!("{}", is_prime(99999941));
}

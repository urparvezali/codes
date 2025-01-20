
fn phi(n: usize) -> usize {
    let mut x = n;
    let mut n = n;
    let mut i = 2;

    while i <= n {
        if n % i == 0 {
            while n % i == 0 {
                n /= i;
            }
			x -= (x/i);
        }
        i += 1;
    }
	x
}

struct Sieve {
    primes: [bool; 1000001],
}
impl Sieve {
    pub fn new() -> Self {
        let mut primes = [true; 1000001];
        for i in 2..1000001 {
            for j in (2 * i..1000001).step_by(i) {
                primes[j] = false;
            }
        }
        Self { primes }
    }
    pub fn is_prime(&self, n: usize) -> bool {
        self.primes[n]
    }
}

fn main() {
    let sv = Sieve::new();
    println!("{:?}", sv.is_prime(100003));
}

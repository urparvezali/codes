pub struct SegmentedSieve {
    r: std::ops::Range<usize>,
    segment: Vec<u8>,
}
impl SegmentedSieve {
    pub fn new(r: std::ops::Range<usize>) -> Self {
        let r_sqrt = (r.end as f64).sqrt().floor() as usize;
        let mut sieve = vec![1_u8; r_sqrt + 1];
        if r_sqrt > 0 {
            sieve[0] = 0;
        }
        if r_sqrt > 1 {
            sieve[1] = 0;
        }
        for i in 2..=(r_sqrt as f64).sqrt() as usize {
            if sieve[i] == 1 {
                for j in (2 * i..r_sqrt).step_by(i) {
                    sieve[j] = 0;
                }
            }
        }
        let primes: Vec<usize> = sieve
            .iter()
            .enumerate()
            .filter(|(_, &j)| j == 1)
            .map(|(i, _)| i)
            .collect();

        let mut segment = vec![1_u8; r.len()];
        for prime in primes {
            let lft = (r.start as f64 / prime as f64).ceil() as usize * prime;
            for i in (lft.max(2 * prime)..r.end).step_by(prime) {
                segment[i - r.start] = 0;
            }
        }
        Self { r, segment }
    }
    pub fn get(&self, n: usize) -> i32 {
        if self.segment[n - self.r.start] == 1 {
            1
        } else {
            0
        }
    }
    pub fn count(&self) -> usize {
        self.segment.iter().filter(|&&val| val == 1).count()
    }
}

fn main() {
    let ss = SegmentedSieve::new(2..1e7 as usize);
    println!("{}", ss.count());
}

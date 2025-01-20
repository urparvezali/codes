pub struct PhiSieve {
    phi: Vec<usize>,
}
impl PhiSieve {
    pub fn new(n: usize) -> Self {
        let mut phi = Vec::with_capacity(n + 1);
        for i in 0..=n {
            phi.push(i);
        }
		for i in 2..=n {
			if phi[i]==i {
				for j in (2*i..=n).step_by(i) {
					phi[j] -= phi[j]/i;
				}
				phi[i]-=1;
			}
		}
        Self { phi}
    }
	pub fn get(&self, n: usize) -> usize {
		self.phi[n]
	}
	pub fn println(&self) {
		for i in 0..self.phi.len() {
			print!("{} ", i);
		}
		println!();
		for i in self.phi.clone() {
			print!("{} ", i);
		}
		println!();

	}
}
fn main() {
	let phi = PhiSieve::new(35);
	phi.println();
}

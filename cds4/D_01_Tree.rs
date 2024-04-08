use std::collections::BinaryHeap;

const MAXN: isize = 200005;

fn good(i: isize, a: &[isize], prv: &[isize], nxt: &[isize], n: isize) -> bool {
	if i < 1 || i > n {
		return false;
	}
	a[prv[i as usize] as usize] == a[i as usize] - 1 || a[nxt[i as usize] as usize] == a[i as usize] - 1
}

fn main() {
	let mut input = String::new();
	std::io::stdin().read_line(&mut input).unwrap();
	let t: isize = input.trim().parse().unwrap();

	for _ in 0..t {
		input.clear();
		std::io::stdin().read_line(&mut input).unwrap();
		let n: isize = input.trim().parse().unwrap();

		let mut a: Vec<isize> = vec![0; (n + 2) as usize];
		let mut prv: Vec<isize> = vec![0; (n + 2) as usize];
		let mut nxt: Vec<isize> = vec![0; (n + 2) as usize];
		let mut in_set: Vec<bool> = vec![false; (n + 2) as usize];

		let mut pq: BinaryHeap<(isize, isize)> = BinaryHeap::new();

		input.clear();
		std::io::stdin().read_line(&mut input).unwrap();
		let numbers: Vec<isize> = input
			.split_whitespace()
			.map(|x| x.parse().unwrap())
			.collect();

		for i in 1..=n {
			a[i as usize] = numbers[(i - 1) as usize];
			prv[i as usize] = i - 1;
			nxt[i as usize] = i + 1;
		}
		a[0] = -2;
		a[(n + 1) as usize] = -2;

		for i in 1..=n {
			if good(i, &a, &prv, &nxt, n) {
				in_set[i as usize] = true;
				pq.push((a[i as usize], i));
			}
		}

		while let Some((_, i)) = pq.pop() {
			nxt[prv[i as usize] as usize] = nxt[i as usize];
			prv[nxt[i as usize] as usize] = prv[i as usize];

			if !in_set[prv[i as usize] as usize] && good(prv[i as usize], &a, &prv, &nxt, n) {
				in_set[prv[i as usize] as usize] = true;
				pq.push((a[prv[i as usize] as usize], prv[i as usize]));
			}
			if !in_set[nxt[i as usize] as usize] && good(nxt[i as usize], &a, &prv, &nxt, n) {
				in_set[nxt[i as usize] as usize] = true;
				pq.push((a[nxt[i as usize] as usize], nxt[i as usize]));
			}
		}

		let mut mn = n;
		let mut bad = 0;

		for i in 1..=n {
			if !in_set[i as usize] {
				bad += 1;
			}
			mn = a[i as usize].min(mn);
		}

		if bad == 1 && mn == 0 {
			println!("YES");
		} else {
			println!("NO");
		}
	}
}

#![allow(clippy::needless_range_loop)]
#![allow(clippy::collapsible_else_if, clippy::comparison_chain)]
#![allow(non_snake_case)]
/* ==================== SOLUTION ==================== */

#[allow(unused)]
use std::{
    cmp::{max, min, Ordering::*},
    collections::*,
    iter,
    str::from_utf8,
};

struct LazySegTree {
    size: usize,
    nodes: Vec<usize>,
    add: Vec<usize>,
}

impl LazySegTree {
    const ROOT: usize = 0;
    pub fn new(n: usize) -> Self {
        Self {
            size: n,
            nodes: vec![0; 2 * n - 1],
            add: vec![0; 2 * n - 1],
        }
    }

    fn childs(&self, v: usize, (l, r): (usize, usize)) -> (usize, usize) {
        let mid = (l + r) / 2;
        (v + 1, v + 2 * (mid - l + 1))
    }

    fn push(&mut self, v: usize, l: usize, r: usize) {
        let (v_l, v_r) = self.childs(v, (l, r));
        self.add[v_l] += self.add[v];
        self.add[v_r] += self.add[v];
        self.nodes[v_l] += self.add[v];
        self.nodes[v_r] += self.add[v];
        self.nodes[v_l] = max(self.nodes[v_l], self.nodes[v]);
        self.nodes[v_r] = max(self.nodes[v_r], self.nodes[v]);
        self.add[v] = 0;
    }

    fn get_impl(&mut self, v: usize, (l, r): (usize, usize), pos: usize) -> usize {
        if l == r {
            return self.nodes[v];
        }
        self.push(v, l, r);
        let mid = (l + r) / 2;
        if pos <= mid {
            self.get_impl(self.childs(v, (l, r)).0, (l, mid), pos)
        } else {
            self.get_impl(self.childs(v, (l, r)).1, (mid + 1, r), pos)
        }
    }

    pub fn get(&mut self, pos: usize) -> usize {
        assert!(1 <= pos && pos <= self.size);
        self.get_impl(Self::ROOT, (1, self.size), pos)
    }

    fn set_max_impl(&mut self, v: usize, (l, r): (usize, usize), pos: usize, val: usize) {
        if l == r {
            self.nodes[v] = max(self.nodes[v], val);
            return;
        }
        self.push(v, l, r);
        let mid = (l + r) / 2;
        if pos <= mid {
            self.set_max_impl(self.childs(v, (l, r)).0, (l, mid), pos, val);
        } else {
            self.set_max_impl(self.childs(v, (l, r)).1, (mid + 1, r), pos, val);
        }
    }

    pub fn set_max(&mut self, pos: usize, val: usize) {
        assert!(1 <= pos && pos <= self.size);
        self.set_max_impl(Self::ROOT, (1, self.size), pos, val);
    }

    pub fn set_all_max(&mut self, val: usize) {
        self.nodes[Self::ROOT] = max(val, self.nodes[1]);
        self.push(Self::ROOT, 1, self.size);
    }

    pub fn add(&mut self, val: usize) {
        self.add[Self::ROOT] += val;
        self.push(Self::ROOT, 1, self.size);
    }
}

fn solve(io: &mut (impl std::io::BufRead + std::io::Write), _ctx: ProblemCtx) {
    let (n, m, k) = io.r3u();
    let a = {
        let mut a = vec![vec![0; m + 1]; n + 1];
        for i in 1..=n {
            for j in 1..=m {
                let v = io.r1::<isize>();
                a[i][j] = if v == -1 { 0 } else { v as usize };
            }
        }
        a
    };

    let (c, zeros) = {
        let mut c = vec![HashMap::<usize, usize>::new(); n + 2];
        let mut zeros = vec![0; n + 1];
        for i in 1..=n {
            for j in 1..=m {
                if a[i][j] == 0 {
                    zeros[i] += 1;
                } else {
                    *c[i].entry(a[i][j]).or_default() += 1;
                }
            }
        }
        (c, zeros)
    };

    let cnt = |row: usize, col| c[row].get(&col).copied().unwrap_or_default();

    let alr = {
        let mut alr = vec![0; n + 1];
        for i in 1..=n {
            for (&k, &v) in &c[i] {
                if k != 0 {
                    alr[i] += v * cnt(i - 1, k);
                }
            }
        }
        alr
    };

    let mut dp = LazySegTree::new(k + 1);
    let mut ans = 0;
    let mut prev = HashMap::<usize, usize>::new();

    for i in 1..=n {
        prev.clear();

        for &j in c[i - 1].keys().chain(c[i].keys()) {
            prev.insert(j, dp.get(j));
        }

        let mut mx = ans + alr[i];
        for (&j, &v) in &c[i] {
            mx = max(mx, prev[&j] + alr[i] + zeros[i - 1] * v);
        }

        dp.add(alr[i] + zeros[i - 1] * zeros[i]);
        ans += alr[i] + zeros[i - 1] * zeros[i];

        dp.set_all_max(mx);
        ans = max(ans, mx);

        for (&j, &v) in &c[i - 1] {
            let res = mx + v * zeros[i];
            dp.set_max(j, res);
            ans = max(ans, res);
        }

        for &j in c[i - 1].keys().chain(c[i].keys()) {
            let res = prev[&j] + alr[i] - (cnt(i - 1, j) * cnt(i, j))
                + (cnt(i - 1, j) + zeros[i - 1]) * (cnt(i, j) + zeros[i]);
            dp.set_max(j, res);
            ans = max(ans, res);
        }
        log!((i, mx, ans));
    }

    wln!(io, "{ans}");
}

struct ProblemCtx<'a> {
    _test_id: &'a usize,
}

fn multi(io: &mut (impl std::io::BufRead + std::io::Write)) {
    let tests = io.r1();
    // let tests = 1;
    for id in 1..=tests {
        let ctx = ProblemCtx { _test_id: &id };
        solve(io, ctx);
    }
}

fn main() {
    let mut io = IO::new_from_stdio();
    multi(&mut io);
}

/* ==================== UTILITY ==================== */

use io::AnyRead;

#[allow(unused)]
use crate::{
    ds::{
        bitset::BitSet,
        dsu::Dsu,
        fenwick::FenwickTree,
        multiset::Multiset,
        neg_idx_vec::NegIdxVec,
        seg::{NodeAdd, SegTree, SegTreeNode},
        sparse::SparseTable,
    },
    geom::Point,
    io::IO,
    math::{
        bin_coef, crt, factorials, get_gcd, isqrt, lcm, mobius_function, set_prime_modulo, ExGcd,
        LinearSieve, ModNum, P007, P998,
    },
    str::{prefix_function, z_function},
    utils::{assert_mle, binary_search, prefix_sum, rand::Xoroshiro128, yesno},
};

// Maybe useful (didn't check it yet):
// https://github.com/TheAlgorithms/Rust
// https://github.com/rust-lang-ja/ac-library-rs/tree/master

/// I/O module intended only for competitive programming or other tasks where
/// you don't need multi-threaded i/o and the input is always valid.
pub mod io {
    // Borrowed: https://codeforces.com/contest/1985/submission/265381611

    use std::{
        io::{BufRead, BufReader, BufWriter, Read, StdinLock, StdoutLock, Write},
        str::FromStr,
    };

    pub struct IO<R, W> {
        reader: R,
        writer: W,
    }

    impl<R, W> IO<R, W> {
        pub fn new(reader: R, writer: W) -> Self {
            Self { reader, writer }
        }
    }

    impl<'a> IO<BufReader<StdinLock<'a>>, BufWriter<StdoutLock<'a>>> {
        pub fn new_from_stdio() -> Self {
            let stdin = std::io::stdin();
            let stdout = std::io::stdout();
            Self::new(BufReader::new(stdin.lock()), BufWriter::new(stdout.lock()))
        }
    }

    impl<R: Read, W> Read for IO<R, W> {
        fn read(&mut self, buf: &mut [u8]) -> std::io::Result<usize> {
            self.reader.read(buf)
        }
    }

    impl<R: BufRead, W> BufRead for IO<R, W> {
        fn fill_buf(&mut self) -> std::io::Result<&[u8]> {
            self.reader.fill_buf()
        }

        fn consume(&mut self, amt: usize) {
            self.reader.consume(amt)
        }
    }

    impl<R, W: Write> Write for IO<R, W> {
        fn write(&mut self, buf: &[u8]) -> std::io::Result<usize> {
            self.writer.write(buf)
        }

        fn flush(&mut self) -> std::io::Result<()> {
            self.writer.flush()
        }
    }

    macro_rules! read_n {
        ($name:ident, $($type:ident),+) => {
            #[allow(unused_parens)]
            fn $name<$($type: FromStr + 'static),+>(&mut self) -> ($($type),+)
            where
                $($type::Err: std::fmt::Debug),+,
                Self: Sized,
            {
                 ($(self.read_token::<$type>()),+)
            }
        };
    }

    macro_rules! read_n_usize {
        ($name:ident, $($type:ty),+) => {
            #[allow(unused_parens)]
            fn $name(&mut self) -> ($($type),+)
            where
                Self: Sized,
            {
                 ($(self.read_token::<$type>()),+)
            }
        };
    }

    pub trait AnyRead: BufRead {
        fn read_token<T: 'static>(&mut self) -> T
        where
            T: FromStr,
            T::Err: std::fmt::Debug,
            Self: Sized,
        {
            struct ReaderIter<'a, R: Read> {
                reader: &'a mut R,
            }

            impl<'a, R: Read> Iterator for ReaderIter<'a, R> {
                type Item = u8;

                fn next(&mut self) -> Option<Self::Item> {
                    let mut buf = [0u8; 1];
                    if self.reader.read(&mut buf).ok() == Some(1) {
                        Some(buf[0])
                    } else {
                        None
                    }
                }
            }

            let data: Vec<u8> = ReaderIter { reader: self }
                .skip_while(|c| c.is_ascii_whitespace())
                .take_while(|c| !c.is_ascii_whitespace())
                .collect();
            std::str::from_utf8(&data).unwrap().trim().parse().unwrap()
        }

        fn read_vec<T: 'static>(&mut self, start: usize, end: usize) -> Vec<T>
        where
            T: FromStr + Default + Clone,
            T::Err: std::fmt::Debug,
            Self: Sized,
        {
            let mut vec = vec![T::default(); end + 1];
            for el in &mut vec[start..=end] {
                *el = self.read_token();
            }
            vec
        }

        fn read_vecu(&mut self, start: usize, end: usize) -> Vec<usize>
        where
            Self: Sized,
        {
            self.read_vec(start, end)
        }

        fn read_bytes(&mut self) -> Vec<u8>
        where
            Self: Sized,
        {
            self.read_token::<String>().into_bytes()
        }

        read_n!(r1, T1);
        read_n!(r2, T1, T2);
        read_n!(r3, T1, T2, T3);
        read_n!(r4, T1, T2, T3, T4);
        read_n_usize!(r1u, usize);
        read_n_usize!(r2u, usize, usize);
        read_n_usize!(r3u, usize, usize, usize);
        read_n_usize!(r4u, usize, usize, usize, usize);
    }

    impl<R: BufRead> AnyRead for R {}

    #[macro_export]
    macro_rules! wln {
        ($dst:expr) => {
            writeln!($dst).ok()
        };

        ($dst:expr, $($args:tt)*) => {
            writeln!($dst, $($args)*).ok()
        };
    }

    #[macro_export]
    macro_rules! wr {
        ($dst:expr, $($args:tt)*) => {
            write!($dst, $($args)*).ok()
        };
    }
}

pub mod utils {
    // MUST
    pub fn yesno(yes_or_no: bool) -> &'static str {
        if yes_or_no {
            "YES"
        } else {
            "NO"
        }
    }

    // https://doc.rust-lang.org/src/std/macros.rs.html#352-374
    #[macro_export]
    macro_rules! log {
        ($($x:tt)*) => {{
            #[cfg(debug_assertions)]
            {std::dbg!($($x)*)}
            #[cfg(not(debug_assertions))]
            {($($x)*)}
        }}
    }

    // MUST
    pub fn binary_search<F>((l_lim, r_lim): (usize, usize), mut can: F) -> usize
    where
        F: FnMut(usize) -> bool,
    {
        let mut accum = l_lim;
        let mut step = 1 << (r_lim - l_lim + 1).ilog2();

        while step > 0 {
            if accum + step <= r_lim && can(accum + step) {
                accum += step;
            }
            step >>= 1;
        }

        accum
    }

    // Usage counter: 6
    pub fn prefix_sum<T>(a: &[T]) -> Vec<T>
    where
        T: Copy + std::ops::AddAssign<T>,
    {
        let mut sum = a[0];
        let mut pref = Vec::with_capacity(a.len());
        pref.push(sum);
        for &x in &a[1..] {
            sum += x;
            pref.push(sum);
        }
        pref
    }

    pub mod rand {
        // Taken from: https://github.com/astocko/xorshift/blob/master/src/xoroshiro128.rs
        use std::num::Wrapping as w;

        // MUST
        #[derive(Copy, Clone)]
        pub struct Xoroshiro128([u64; 2]);

        #[inline]
        fn rotl(x: u64, k: i32) -> u64 {
            (x << k) | (x >> (64 - k))
        }

        impl Xoroshiro128 {
            pub fn new() -> Self {
                // https://users.rust-lang.org/t/random-number-without-using-the-external-crate/17260/9
                let ptr = Box::into_raw(Box::new(44));
                Self::from_seed(&[
                    ptr as u64,
                    std::time::SystemTime::now()
                        .duration_since(std::time::UNIX_EPOCH)
                        .unwrap()
                        .subsec_nanos() as u64,
                ])
            }
            pub fn next_u32(&mut self) -> u32 {
                self.next_u64() as u32
            }
            pub fn next_usize(&mut self) -> usize {
                self.next_u64() as usize
            }
            #[inline]
            pub fn next_u64(&mut self) -> u64 {
                let s0 = w(self.0[0]);
                let mut s1 = w(self.0[1]);
                let result = s0 + s1;

                s1 ^= s0;
                self.0[0] = (w(rotl(s0.0, 55)) ^ s1 ^ (s1 << 14)).0;
                self.0[1] = rotl(s1.0, 36);

                result.0
            }

            fn from_seed(seed: &[u64; 2]) -> Self {
                Self(*seed)
            }

            // https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
            // Usage counter: 2
            pub fn shuffle<T: Copy>(&mut self, data: &mut [T]) {
                for i in 0..data.len() {
                    let j = self.next_u32() as usize % data.len();
                    (data[i], data[j]) = (data[j], data[i]);
                }
            }
        }

        impl Default for Xoroshiro128 {
            fn default() -> Self {
                Self::new()
            }
        }
    }

    /// Assert for interactive problems to recieve MLE instead of WA.
    /// RE doesn't work in interactive problems well.
    pub fn assert_mle(ok: bool) {
        if !ok {
            vec![0; 1_000_000_000];
        }
    }
}

#[rustfmt::skip] // fn_single_line is not stable yet.
pub mod math {
    // Borrowed: https://codeforces.com/contest/1985/submission/265363478
    use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign};

    // MUST
    #[derive(Clone, Copy, Debug, Default, PartialEq, Eq, PartialOrd, Ord)]
    pub struct ModNum(u32);

    // Good primes for hashes:
    // const MOD: [u32; 4] = [618_557_587, 998_244_353, 597_804_841, 1_000_000_009];

    /// MOD must be prime, otherwise there is a chance of collisions and division
    /// will not work properly.
    static mut MOD_PRIME: u32 = 0;
    pub const P007: u32 = 1_000_000_007;
    pub const P998: u32 = 998_244_353;

    pub fn set_prime_modulo(val: u32) {
            assert!(
                val <= i32::MAX as u32,
                "if the modulus is greater than half of u32::MAX, the base operations will not fit in u32"
            );
            unsafe { MOD_PRIME = val; }
    }

    impl ModNum {
        pub fn new(val: u32) -> Self { Self(val % unsafe{ MOD_PRIME }) }
        pub fn val(&self) -> u32 { self.0 }

        pub fn binpow(mut self, mut exp: u32) -> Self {
            let mut res = Self(1);
            while exp > 0 {
                if exp & 1 == 1 {
                    res *= self.val();
                    exp -= 1;
                } else {
                    self = self * self.val();
                    exp >>= 1;
                }
            }
            res
        }
    }

    impl std::fmt::Display for ModNum { fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result { self.0.fmt(f) } }

    impl From<u32> for ModNum {
        fn from(value: u32) -> Self {
            Self::new(value)
        }
    }
    impl From<usize> for ModNum {
        fn from(value: usize) -> Self {
            Self::new((value % unsafe { MOD_PRIME } as usize) as u32)
        }
    }
    impl From<isize> for ModNum {
        fn from(value: isize) -> Self {
            Self::from(unsafe { (MOD_PRIME as isize + value % MOD_PRIME as isize) as usize })
        }
    }
    impl From<ModNum> for u32 {
        fn from(value: ModNum) -> Self {
            value.0
        }
    }

    impl<T: Into<u32>> AddAssign<T> for ModNum { fn add_assign(&mut self, rhs: T) { *self = *self + rhs.into(); } }
    impl<T: Into<u32>> Add<T> for ModNum {
        type Output = Self;
        fn add(self, rhs: T) -> Self::Output { unsafe { Self::new((self.0 + rhs.into()) % MOD_PRIME) } }
    }
    impl<T: Into<u32>> SubAssign<T> for ModNum { fn sub_assign(&mut self, rhs: T) { *self = *self - rhs.into(); } }
    impl<T: Into<u32>> Sub<T> for ModNum {
        type Output = Self;
        fn sub(self, rhs: T) -> Self::Output { unsafe { Self::new((self.0 + MOD_PRIME - rhs.into()) % MOD_PRIME) } }
    }
    impl<T: Into<u32>> MulAssign<T> for ModNum { fn mul_assign(&mut self, rhs: T) { *self = *self * rhs.into(); } }
    impl<T: Into<u32>> Mul<T> for ModNum {
        type Output = Self;
        fn mul(self, rhs: T) -> Self::Output {
            unsafe { Self(((self.0 as u64 * rhs.into() as u64) % MOD_PRIME as u64) as u32) }
        }
    }
    impl<T: Into<u32>> DivAssign<T> for ModNum { fn div_assign(&mut self, rhs: T) { *self = *self / rhs.into(); } }
    impl<T: Into<u32>> Div<T> for ModNum {
        type Output = Self;
        fn div(self, rhs: T) -> Self::Output {
            self * Self::new(rhs.into()).binpow(unsafe { MOD_PRIME } - 2)
        }
    }

    /// Linear Sieve: https://cp-algorithms.com/algebra/prime-sieve-linear.html
    /// Finds all primes and minimum prime factor for each number up until N.
    /// O(n), not O(n * log (log n))
    // Usage counter: 6
    pub struct LinearSieve {
        primes: Vec<usize>,
        prime_fac: Vec<usize>,
    }

    impl LinearSieve {
        pub fn new(n: usize) -> LinearSieve {
            assert!(n <= 10_000_000, "Linear Sieve uses O(n) memory.");
            let mut prime_fac = vec![0; n + 1];
            let mut primes = vec![];
            prime_fac[0] = 1;
            prime_fac[1] = 1;
            for idx in 2..=n {
                if prime_fac[idx] == 0 {
                    prime_fac[idx] = idx;
                    primes.push(idx);
                }
                for &pr in &primes {
                    if pr as u64 * idx as u64 > n as u64 {
                        break;
                    }
                    prime_fac[pr * idx] = pr;
                    if pr == prime_fac[idx] {
                        break;
                    }
                }
            }
            LinearSieve { primes, prime_fac }
        }
        pub fn primes(&self) -> &[usize] { &self.primes }
        pub fn prime_factors(&self) -> &[usize] { &self.prime_fac }
    }

    /// Mobius function mu(f):
    /// * 1 if n=1
    /// * (-1)^k if n is the product of k distinct primes.
    /// * 0 otherwise.
    /// Can be used for gcd inclusion-exclusion coeficients.
    /// Example: https://codeforces.com/contest/803/submission/292542116
    // Usage counter: 2
    pub fn mobius_function(n: usize) -> Vec<isize> {
        let mut mob = vec![0; n + 1];
        mob[1] = -1;
        for i in 1..=n {
            if mob[i] == 0 { continue; }
            mob[i] = -mob[i];
            for j in ((i + i)..=n).step_by(i) { mob[j] += mob[i]; }
        }
        mob
    }

    // Usage counter: 3
    pub fn get_gcd<N>(a: N, b: N) -> N
    where
        N: Into<u64> + TryFrom<u64>,
        N::Error: std::fmt::Debug,
    {
        let (mut a, mut b) = (a.into(), b.into());
        while b != 0 {
            (a, b) = (b, a % b);
        }
        a.try_into().unwrap()
    }

    // https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
    //
    // Usage counter: 1
    #[derive(Debug, Clone, Copy)]
    pub struct ExGcd {
        pub x: i64,
        pub y: i64,
        pub d: i64,
    }

    impl ExGcd {
        pub fn new(a: i64, b: i64) -> Self { Self::ex_gcd_impl(a, b) }

        // I didn't write iterative version, because I don't understand it. A
        // recursive one is just a little slower and at least I approximately
        // understand what's going on.
        fn ex_gcd_impl(a: i64, b: i64) -> ExGcd {
            if b == 0 {
                return ExGcd { x: 1, y: 0, d: a };
            }
            let gcd = Self::ex_gcd_impl(b, a % b);
            ExGcd { d: gcd.d, x: gcd.y, y: gcd.x - gcd.y * (a / b) }
        }
    }

    // Usage counter: 0
    pub fn lcm<N>(a: N, b: N) -> u64
    where
        N: Into<u64>,
    {
        let (a, b) = (a.into(), b.into());
        a / get_gcd(a, b) as u64 * b
    }

    /// Find solution for system of congruences (Chinese Remainder Theory).
    ///
    /// x = a1 mod n1 AND ... AND x = at mod nt
    /// All n_i must be pairwise coprime. Otherwise you need to manully check
    /// that returned solution is valid in your case. Also CRT can solve
    /// Diophantine equation.
    /// NOTE: Tested only with two congruences.
    //
    // https://codeforces.com/blog/entry/61290
    //
    // Usage examples:
    // https://codeforces.com/contest/1993/problem/F2
    // https://codeforces.com/contest/982/problem/E
    //
    // Usage counter: 2
    pub fn crt(congruences: &[(i64, u64)]) -> u64 {
        assert!(congruences.len() >= 2);
        let normalize = |x: i64, pmod| -> u64 { ((x + pmod as i64) % pmod as i64) as u64 };

        // I probably fckd up here with conversions, be careful (even though usage counter > 0).
        let mut cur_lcm = congruences[0].1;
        let mut ans = normalize(congruences[0].0, cur_lcm);
        for &(a_i, n_i) in congruences {
            let ExGcd { x, d, .. } = ExGcd::new(cur_lcm as i64, n_i as i64);
            let cur_ans = ans as i64 + x * (a_i - ans as i64) / d % (n_i as i64 / d) * cur_lcm as i64;
            cur_lcm = lcm(cur_lcm, n_i);
            ans = normalize(cur_ans, cur_lcm);
        }
        ans
    }

    // Usage counter: 3
    pub fn factorials(n: usize) -> Vec<ModNum> {
        let mut fac = vec![0u32.into(); n + 1];
        fac[0] = 1u32.into();
        for i in 1..fac.len() {
            fac[i] = fac[i - 1] * (i as u32);
        }
        fac
    }

    // Usage counter: 2
    pub fn bin_coef(n: usize, k: usize, factorials: &[ModNum]) -> ModNum {
        if k > n {
            return 0u32.into();
        };
        factorials[n] / (factorials[k] * factorials[n - k])
    }

    // MUST
    pub fn isqrt(n: usize) -> usize {
        // sqrt has rounding error.
        let mut res = f32::sqrt(n as f32) as usize;
        while res * res < n {
            res += 1;
        }
        while res * res > n {
            res -= 1;
        }
        res
    }
}

mod str {
    // Usage counter: 2
    /// The length of the longest proper prefix of the substring s[0..i] which
    /// is also a suffix of this substring.
    /// Example: "abcabcd" [0, 0, 0, 1, 2, 3, 0]
    pub fn prefix_function<T>(s: &[T]) -> Vec<usize>
    where
        T: PartialEq + Copy,
    {
        let mut pref = vec![0; s.len()];
        for (i, &x) in s.iter().enumerate().skip(1) {
            let mut j = pref[i - 1];
            while s[j] != x && j != 0 {
                j = pref[j - 1];
            }
            pref[i] = j + (s[j] == x) as usize;
        }
        pref
    }

    // Usage counter: 1
    /// The length of the longest string that is, at the same time, a prefix of
    /// s and a prefix of the suffix of s starting at i.
    pub fn z_function<T>(s: &[T]) -> Vec<usize>
    where
        T: PartialEq + Copy,
    {
        // https://github.com/rust-lang-ja/ac-library-rs/blob/5323fca53ff8a49e67387ddfabc299110c17922c/src/string.rs#L279
        let mut z = vec![0; s.len()];
        let mut j = 0;
        for i in 1..s.len() {
            z[i] = std::cmp::min((j + z[j]).saturating_sub(i), z[i - j]);
            while i + z[i] < s.len() && s[z[i]] == s[i + z[i]] {
                z[i] += 1;
            }
            if j + z[j] < i + z[i] {
                j = i;
            }
        }
        z[0] = s.len();
        z
    }
}

#[rustfmt::skip]
pub mod geom {
    use std::ops::{Add, Sub, Mul};
    // Maybe useful: https://codeforces.com/blog/entry/48122

    // Usage counter: 1
    #[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
    pub struct Point<T> { pub x: T, pub y: T, }

    impl<T> Point<T> where T: Copy + Mul<T, Output = T> + Sub<T, Output = T> + Add<T, Output = T>, {
        /// Distance between two Points.
        pub fn dist(&self, p2: &Self) -> T { (self.x - p2.x) * (self.x - p2.x) + (self.y - p2.y) * (self.y - p2.y) }
        /// Dot product: a * b = x_a * x_b + y_a * y_b = |a| * |b| cos a.
        pub fn dot(&self, p2: &Self) -> T { self.x * p2.x + self.y * p2.y }
    }

    impl<T> From<(T, T)> for Point<T> { fn from((x, y): (T, T)) -> Self { Self { x, y } } }

    impl<T> Add<Point<T>> for Point<T> where T: Add<T, Output = T>, {
        type Output = Self;
        fn add(self, rhs: Point<T>) -> Self::Output { Self { x: self.x + rhs.x, y: self.y + rhs.y } }
    }
    impl<T> Sub<Point<T>> for Point<T> where T: Sub<T, Output = T>, {
        type Output = Self;
        fn sub(self, rhs: Point<T>) -> Self::Output { Self { x: self.x - rhs.x, y: self.y - rhs.y } }
    }
}

pub mod ds {
    // Usage counter: 1
    pub mod neg_idx_vec {
        use std::ops::{Index, IndexMut, RangeInclusive};

        /// A vector that allows a negative index. Alternative for
        /// `std::collections::HashMap` when you need contiguous storage.
        /// For example: [-100; 100];
        #[derive(Debug)]
        pub struct NegIdxVec<T> {
            inner: Vec<T>,
            shift: usize,
        }

        impl<T> NegIdxVec<T>
        where
            T: Default + Clone,
        {
            pub fn new(range: RangeInclusive<isize>) -> Self {
                let (start, end) = range.into_inner();
                assert!(
                    start < 0,
                    "Why do you even use NegIdxVec with positive range?"
                );
                Self {
                    inner: vec![T::default(); (end - start + 1) as usize],
                    shift: start.unsigned_abs(),
                }
            }
        }

        impl<T, I: TryInto<isize>> Index<I> for NegIdxVec<T>
        where
            <I as TryInto<isize>>::Error: std::fmt::Debug,
        {
            type Output = T;

            fn index(&self, index: I) -> &Self::Output {
                &self.inner[(index.try_into().unwrap() + self.shift as isize) as usize]
            }
        }

        impl<T, I: TryInto<isize>> IndexMut<I> for NegIdxVec<T>
        where
            <I as TryInto<isize>>::Error: std::fmt::Debug,
        {
            fn index_mut(&mut self, index: I) -> &mut Self::Output {
                &mut self.inner[(index.try_into().unwrap() + self.shift as isize) as usize]
            }
        }
    }

    // Indexing starts from zero.
    // Fenwick is 3-4 times faster than recursive segment tree implementation
    // below. Example when segment tree TLs but BIT works:
    // https://codeforces.com/contest/2004/submission/276835186
    //
    // Usage counter: 2
    pub mod fenwick {
        #[derive(Clone, Debug)]
        pub struct FenwickTree<T, F> {
            bit: Vec<T>,
            n: usize,
            op: F,
        }

        impl<T, F> FenwickTree<T, F>
        where
            T: Default + Clone + Copy,
            T: std::ops::AddAssign + std::ops::Sub<Output = T>,
            F: Fn(T, T) -> T,
        {
            pub fn new(n: usize, op: F) -> Self {
                Self {
                    bit: vec![T::default(); n],
                    n,
                    op,
                }
            }

            fn get_impl(&self, r: usize) -> T {
                let mut r = r as isize;
                let mut res = T::default();
                while r >= 0 {
                    res = (self.op)(res, self.bit[r as usize]);
                    r = (r & (r + 1)) - 1;
                }
                res
            }

            pub fn get(&self, l: usize, r: usize) -> T {
                self.get_impl(r) - self.get_impl(l - 1)
            }

            pub fn get_r(&self, r: usize) -> T {
                self.get_impl(r)
            }

            pub fn add(&mut self, mut idx: usize, delta: T) {
                while idx < self.n {
                    self.bit[idx] += delta;
                    idx |= idx + 1;
                }
            }

            pub fn set(&mut self, mut idx: usize, val: T) {
                while idx < self.n {
                    self.bit[idx] = (self.op)(self.bit[idx], val);
                    idx |= idx + 1;
                }
            }
        }
    }

    // Usage counter: 5
    pub mod seg {
        use std::ops::RangeInclusive;
        // Partially borrowed: https://codeforces.com/contest/1997/submission/273633915
        //
        // Mostly done to serve as a reference for problem-specific segment
        // trees (copy and mofify >> write from scratch). Though the basic functionality
        // is generic.
        //
        // Memory efficient but slow Segment Tree.
        // Passed ranges and arrays must start at 1. Internal node indexing starts at 0.
        // Space: 2 * N.
        //
        // This implementation of the segment tree is slow and could be
        // rewritten more efficiently. But I don't need it right now, so let it be. In
        // the future I may read https://codeforces.com/blog/entry/18051 and optimize. For
        // example: https://codeforces.com/contest/1997/submission/273633915
        // ~3 times slower than non-recursive impl.
        //
        // <https://cp-algorithms.com/data_structures/segment_tree.html#memory-efficient-implementation>
        //
        #[derive(Debug, Clone)]
        pub struct SegTree<Node: SegTreeNode> {
            nodes: Vec<Node>,
            size: usize,
            root: usize,
        }

        pub trait SegTreeNode: Clone {
            type Output;
            fn new() -> Self;
            fn value(&self) -> Self::Output;
            fn merge(lhs: &Self, rhs: &Self) -> Self;
        }

        impl<Node: SegTreeNode> From<&[Node]> for SegTree<Node> {
            /// Indexing must starts from 1 (zero-th element is ignored).
            fn from(value: &[Node]) -> Self {
                let size = value.len() - 1;
                let mut tree = SegTree {
                    nodes: vec![Node::new(); 2 * size - 1],
                    size,
                    root: 0,
                };
                tree.build(tree.root, 1..=tree.size, Some(value));
                tree
            }
        }

        impl<Node: SegTreeNode> SegTree<Node> {
            pub fn with_size(n: usize) -> Self {
                let mut tree = SegTree {
                    nodes: vec![Node::new(); 2 * n - 1],
                    size: n,
                    root: 0,
                };
                tree.build(tree.root, 1..=tree.size, None);
                tree
            }

            fn childs(&self, v: usize, (l, r): (usize, usize)) -> (usize, usize) {
                let mid = (l + r) / 2;
                (v + 1, v + 2 * (mid - l + 1))
            }

            fn build(&mut self, v: usize, seg: RangeInclusive<usize>, from_arr: Option<&[Node]>) {
                let (l, r) = seg.into_inner();
                if l == r {
                    if let Some(arr) = from_arr {
                        self.nodes[v] = arr[l].clone();
                    }
                    return;
                }
                let mid = (l + r) / 2;
                let (v_l, v_r) = self.childs(v, (l, r));
                self.build(v_l, l..=mid, from_arr);
                self.build(v_r, (mid + 1)..=r, from_arr);
                self.nodes[v] = (Node::merge)(&self.nodes[v_l], &self.nodes[v_r]);
            }

            pub fn get(&self, (req_l, req_r): (usize, usize)) -> Node::Output {
                assert!(req_l >= 1 && req_r <= self.size);
                self.get_impl(self.root, 1..=self.size, req_l..=req_r)
                    .value()
            }

            fn get_impl(
                &self,
                v: usize,
                seg: RangeInclusive<usize>,
                req: RangeInclusive<usize>,
            ) -> Node {
                if seg == req {
                    return self.nodes[v].clone();
                }

                let (l, r) = seg.into_inner();
                let (req_l, req_r) = req.into_inner();

                let mid = (l + r) / 2;
                let (v_l, v_r) = self.childs(v, (l, r));

                let l_val =
                    (req_l <= mid).then(|| self.get_impl(v_l, l..=mid, req_l..=mid.min(req_r)));
                let r_val = (req_r > mid)
                    .then(|| self.get_impl(v_r, (mid + 1)..=r, (mid + 1).max(req_l)..=req_r));

                match (l_val, r_val) {
                    (Some(l_val), Some(r_val)) => (Node::merge)(&l_val, &r_val),
                    (Some(val), _) | (_, Some(val)) => val,
                    _ => unreachable!(),
                }
            }

            pub fn upd(&mut self, idx: usize, upd_fn: impl FnMut(&mut Node)) {
                assert!(idx >= 1 && idx <= self.size);
                self.upd_impl(self.root, 1..=self.size, idx, upd_fn);
            }

            fn upd_impl(
                &mut self,
                v: usize,
                seg: RangeInclusive<usize>,
                req_idx: usize,
                mut upd_fn: impl FnMut(&mut Node),
            ) {
                let (l, r) = seg.into_inner();
                if l == r {
                    (upd_fn)(&mut self.nodes[v]);
                    return;
                }
                let mid = (l + r) / 2;
                let (v_l, v_r) = self.childs(v, (l, r));
                if req_idx <= mid {
                    self.upd_impl(v_l, l..=mid, req_idx, upd_fn);
                } else {
                    self.upd_impl(v_r, (mid + 1)..=r, req_idx, upd_fn);
                }
                self.nodes[v] = (Node::merge)(&self.nodes[v_l], &self.nodes[v_r]);
            }
        }

        // Example of SegTreeNode trait implementation.
        #[derive(Clone, Debug)]
        pub struct NodeAdd<T: std::ops::Add<Output = T>> {
            pub value: T,
        }

        impl<T: From<u8> + Clone + std::ops::Add<Output = T>> SegTreeNode for NodeAdd<T> {
            type Output = T;
            fn new() -> Self {
                Self {
                    value: Self::Output::from(0),
                }
            }
            fn value(&self) -> Self::Output {
                self.value.clone()
            }
            fn merge(lhs: &Self, rhs: &Self) -> Self {
                Self {
                    value: lhs.value.clone() + rhs.value.clone(),
                }
            }
        }
    }

    pub mod lazy_seg {
        // Update & sum on range impl: https://codeforces.com/contest/1478/submission/278551889
    }

    // Usage counter: 6
    pub mod dsu {
        /// Indexing starts from zero.
        #[derive(Debug)]
        pub struct Dsu {
            parent: Vec<usize>,
            size: Vec<usize>,
            num_of_components: usize,
        }

        impl Dsu {
            pub fn new(nodes_cnt: usize) -> Self {
                Self {
                    parent: (0..nodes_cnt).collect(),
                    size: vec![1; nodes_cnt],
                    num_of_components: nodes_cnt,
                }
            }
            pub fn num_of_components(&self) -> usize {
                self.num_of_components
            }

            // Useless? Probably self.size[self.find(node)]
            // pub fn size_of_node(&self, node: usize) -> usize {
            //     self.size[self.parent[node]]
            // }

            // Actually can be a reason of the Time Limit if you are not using
            // union by rank/size. In that case use path compression (recursion).
            // For example: https://codeforces.com/contest/1706/submission/284992835
            pub fn find(&mut self, mut node: usize) -> usize {
                // Path splitting:
                // https://en.wikipedia.org/wiki/Disjoint-set_data_structure#Finding_set_representatives
                while self.parent[node] != node {
                    (node, self.parent[node]) = (self.parent[node], self.parent[self.parent[node]]);
                }
                node
            }

            pub fn union(&mut self, node_x: usize, node_y: usize) -> usize {
                let (mut root_x, mut root_y) = (self.find(node_x), self.find(node_y));
                if root_x == root_y {
                    return root_x;
                }
                self.num_of_components -= 1;
                if self.size[root_x] < self.size[root_y] {
                    (root_x, root_y) = (root_y, root_x);
                }
                self.parent[root_y] = root_x;
                self.size[root_x] += self.size[root_y];
                root_x
            }
        }
    }

    pub mod sparse {
        /// Answer RMQ in O(1).
        /// Indexing starts from 0.
        // Usage counter: 5
        pub struct SparseTable<T, F> {
            n: usize,
            logs: Vec<usize>,
            data: Vec<Vec<T>>,
            op: F,
        }

        impl<T, F> SparseTable<T, F>
        where
            F: Fn(&T, &T) -> T,
            T: Default,
        {
            pub fn new(basic: Vec<T>, op: F) -> Self {
                let logs = Self::precompute_logs(basic.len());
                let mut table = Self {
                    n: basic.len(),
                    data: Vec::with_capacity(logs[basic.len()]),
                    logs,
                    op,
                };
                table.data.push(basic);
                table.build();
                table
            }

            fn precompute_logs(n: usize) -> Vec<usize> {
                let mut next_pow = 2;
                let mut logs = vec![0; n + 1];
                for i in 2..=n {
                    logs[i] = logs[i - 1];
                    if next_pow == i {
                        next_pow *= 2;
                        logs[i] += 1;
                    }
                }
                logs
            }

            fn build(&mut self) {
                for lvl in 1..=self.logs[self.n] {
                    let layer_len = self.n - (1 << lvl) + 1;
                    let mut layer = Vec::with_capacity(layer_len);
                    for i in 0..layer_len {
                        layer.push((self.op)(
                            &self.data[lvl - 1][i],
                            &self.data[lvl - 1][i + (1 << (lvl - 1))],
                        ));
                    }
                    self.data.push(layer);
                }
            }

            pub fn get(&self, l: usize, r: usize) -> T {
                if r < l {
                    return T::default();
                }
                assert!(r < self.n);
                let lvl = self.logs[r - l + 1];
                (self.op)(&self.data[lvl][l], &self.data[lvl][r + 1 - (1 << lvl)])
            }
        }
    }
    // Usage counter: 3
    pub mod bitset {
        #[derive(Clone)]
        pub struct BitSet {
            len: usize,
            data: Vec<usize>,
        }
        impl BitSet {
            const TRUE: bool = true;
            const FALSE: bool = false;

            const SIZE: usize = std::mem::size_of::<usize>() * 8;
            const SIZE_MASK: usize = Self::SIZE - 1;
            const SLOG: u32 = Self::SIZE.ilog2();

            pub fn new(n: usize) -> Self {
                Self {
                    len: n,
                    data: vec![0; (n + Self::SIZE - 1) >> Self::SLOG],
                }
            }
            fn idx(pos: usize) -> usize {
                pos >> Self::SLOG
            }
            pub fn set_all(&mut self, bit: bool) {
                let val = if bit { !0 } else { 0 };
                for x in &mut self.data {
                    *x = val;
                }
            }
            pub fn set(&mut self, pos: usize, bit: bool) {
                self.data[Self::idx(pos)] = self.data[Self::idx(pos)]
                    & (!(1 << (pos & Self::SIZE_MASK)))
                    | (if bit { 1 } else { 0 } << (pos & Self::SIZE_MASK));
            }
            fn fix_last(&mut self) {
                if self.len & Self::SIZE_MASK != 0 {
                    let mask = (1 << (self.len & Self::SIZE_MASK)) - 1;
                    *self.data.last_mut().unwrap() &= mask;
                }
            }
        }
        impl std::ops::Index<usize> for BitSet {
            type Output = bool;
            fn index(&self, pos: usize) -> &Self::Output {
                if (self.data[Self::idx(pos)] >> (pos & Self::SIZE_MASK)) & 1 == 1 {
                    &Self::TRUE
                } else {
                    &Self::FALSE
                }
            }
        }
        impl std::ops::BitAndAssign<&Self> for BitSet {
            fn bitand_assign(&mut self, rhs: &Self) {
                for (x, y) in self.data.iter_mut().zip(&rhs.data) {
                    *x &= y;
                }
            }
        }
        impl std::ops::BitAnd<&Self> for BitSet {
            type Output = Self;
            fn bitand(mut self, rhs: &Self) -> Self::Output {
                self &= rhs;
                self
            }
        }
        impl std::ops::BitOrAssign<&Self> for BitSet {
            fn bitor_assign(&mut self, rhs: &Self) {
                for (x, y) in self.data.iter_mut().zip(&rhs.data) {
                    *x |= y;
                }
            }
        }
        impl std::ops::BitOr<&Self> for BitSet {
            type Output = Self;
            fn bitor(mut self, rhs: &Self) -> Self::Output {
                self |= rhs;
                self
            }
        }
        // ShlAssign/ShrAssign is adapted version of:
        // https://github.com/EgorKulikov/rust_algo/blob/master/algo_lib/src/collections/bit_set.rs#L193
        impl std::ops::ShlAssign<usize> for BitSet {
            fn shl_assign(&mut self, rhs: usize) {
                if rhs == 0 {
                    return;
                }
                if rhs >= self.len {
                    self.set_all(false);
                    return;
                }
                let small_shift = rhs & Self::SIZE_MASK;
                if small_shift != 0 {
                    let mut carry = 0;
                    for i in 0..self.data.len() {
                        let new_carry = self.data[i] >> (Self::SIZE - small_shift);
                        self.data[i] <<= small_shift;
                        self.data[i] |= carry;
                        carry = new_carry;
                    }
                }
                let big_shift = rhs >> Self::SLOG;
                if big_shift != 0 {
                    self.data.rotate_right(big_shift);
                    self.data[..big_shift].fill(0);
                }
                self.fix_last();
            }
        }
        impl std::ops::Shl<usize> for BitSet {
            type Output = Self;
            fn shl(mut self, rhs: usize) -> Self::Output {
                self <<= rhs;
                self
            }
        }
        impl std::ops::ShrAssign<usize> for BitSet {
            fn shr_assign(&mut self, rhs: usize) {
                if rhs == 0 {
                    return;
                }
                if rhs >= self.len {
                    self.set_all(false);
                    return;
                }
                let small_shift = rhs & Self::SIZE_MASK;
                if small_shift != 0 {
                    let mut carry = 0;
                    for i in (0..self.data.len()).rev() {
                        let new_carry = self.data[i] << (Self::SIZE - small_shift);
                        self.data[i] >>= small_shift;
                        self.data[i] |= carry;
                        carry = new_carry;
                    }
                }
                let big_shift = rhs >> Self::SLOG;
                if big_shift != 0 {
                    self.data.rotate_left(big_shift);
                    let from = self.data.len() - big_shift;
                    self.data[from..].fill(0);
                }
            }
        }
        impl std::ops::Shr<usize> for BitSet {
            type Output = Self;
            fn shr(mut self, rhs: usize) -> Self::Output {
                self >>= rhs;
                self
            }
        }
        impl std::fmt::Debug for BitSet {
            fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
                let mut res = String::with_capacity(self.len);
                for i in 0..self.len {
                    res.push(if self[i] { '1' } else { '0' });
                }
                write!(f, "{res}")
            }
        }
    }

    pub mod multiset {
        use std::{
            cmp::Ord,
            collections::{btree_map::Entry, BTreeMap},
        };
        // Usage counter: 1
        #[derive(Debug, Default)]
        pub struct Multiset<T> {
            inner: BTreeMap<T, usize>,
            len: usize,
        }
        impl<T: Ord> Multiset<T> {
            pub fn clear(&mut self) {
                self.inner.clear();
                self.len = 0;
            }
            pub fn len(&self) -> usize {
                self.len
            }
            pub fn is_empty(&self) -> bool {
                self.len == 0
            }
            pub fn insert(&mut self, val: T) {
                *self.inner.entry(val).or_default() += 1;
                self.len += 1;
            }
            // Removes single occurence of value.
            // Returns if value existed.
            pub fn remove(&mut self, val: T) -> bool {
                match self.inner.entry(val) {
                    Entry::Vacant(_) => false,
                    Entry::Occupied(mut cell) => {
                        if cell.get() == &1 {
                            cell.remove();
                        } else {
                            *cell.get_mut() -= 1;
                        }
                        self.len -= 1;
                        true
                    }
                }
            }
            pub fn inner(&self) -> &BTreeMap<T, usize> {
                &self.inner
            }
        }
    }
}

/* COMMON PITFALLS:
1. Wrong answer:
   * Arithmetic overflow. In release mode, Rust has no overflow checks, and as a
     result numbers can wrap instead of panic.
     Use u64 when solving combinatorial problems.
     Example: https://codeforces.com/contest/1997/submission/273778276
     Example: https://codeforces.com/contest/2000/submission/276165678
   * Interactive problems. Asserts do not work on interactive problems, so
     exceeding number of queries you will still recieve WA.
     Example: https://codeforces.com/blog/entry/135766?#comment-1214870
2. Time limit:
   * Slow hash{map,set} and time limit. Creating a HashMap is about 2 times
     slower than a vector. Insertion is not O(1). Iterating over keys is
     O(capacity) instead of O(len).
     Example: https://codeforces.com/contest/1750/submission/274139174
   * (or Idleness limit): debug macro and time/idleness limit. debug! macro
     works even in release builds, and as a result a lot of data can be written to
     stderr (only stdout is compared with actual results).
     Example: https://codeforces.com/contest/1750/submission/274984632
   * Modulo operations. They are heavy. If use it a lot (even on small numbers)
     it can slow down solution by a lot (2 times).
     Example: https://codeforces.com/contest/2035/submission/288969369 (TL)
              https://codeforces.com/contest/2035/submission/288970215 (OK)
   * Recursion. Rewrite it using stack/queue. It can speed up solution up to 2 times.
     For examples see `Modulo operations`.
3. Memory limit:
   * Optimization:
     * Use 32bit (or smaller) types instead of usize (64bit on cf runners).
     * Use fix size arrays instead of vectors.
     * Use stack to implement recursion (dfs for example). Reduces memory usage a little bit.
     Example: https://codeforces.com/contest/379/problem/F
     * 1500*1500=2250000 BTreeSet<(usize, usize)> > 256 MB
                         BTreeSet<(u16, u16)>     == 160 MB

The size of the file with the source code shouldn't exceed 64 kilobytes ~= 2k lines of code.
rustc --edition=2021 -O -C link-args=/STACK:268435456 --cfg ONLINE_JUDGE %1
*/

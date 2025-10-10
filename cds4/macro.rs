#[macro_export]
macro_rules! my_input {
    ($($name:tt : $type:tt), * $(,)?) => {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.trim().split_whitespace();
        $(
            let $name = iter.next().unwrap().parse::<$type>().unwrap();
        ) *
    };

}

#[macro_export]
macro_rules! vec_input {
    ($name:tt : $type:tt $(,)? ) => {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut $name: Vec<$type> = input.split_whitespace().map(|s| s.parse().unwrap()).collect();
    };
}

fn main() {
    my_input! {
        t:usize,
    }
    for _ in 0..t {
        vec_input! {
            lst:usize,
        }
        lst.sort();
        if lst[0] != lst[1] {
            println!("{}", lst[0]);
        } else {
            println!("{}", lst[2]);
        }
    }
}

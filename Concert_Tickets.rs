use std::collections::BTreeMap;
use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();

    let tickets: Vec<i32> = (0..n)
        .map(|_| it.next().unwrap().parse().unwrap())
        .collect();
    let bids: Vec<i32> = (0..m)
        .map(|_| it.next().unwrap().parse().unwrap())
        .collect();

    let mut mst: BTreeMap<i32, usize> = BTreeMap::new();
    for ticket in tickets {
        *mst.entry(ticket).or_insert(0) += 1;
    }

    for bid in bids {
        let entry = mst.range(..=bid).next_back();
        match entry {
            Some((&val, count)) => {
                println!("{}", val);
                if *count == 1 {
                    mst.remove(&val);
                } else {
                    *mst.get_mut(&val).unwrap() -= 1;
                }
            }
            None => println!("-1"),
        }
    }
}

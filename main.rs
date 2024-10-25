#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_macros)]
#![allow(unused_mut)]

mod A_Mocha_and_Hiking;
mod B_Running_for_Gold;
mod ai_labs;
mod can_arrange;
mod find_order;
mod linkedlist;
mod min_subarray;
mod z;

fn main() {
    let vec: Vec<i32> = Vec::with_capacity(16);
    let _arr = [i32::default(); 16];
    {
        let _x = &vec;
    }
	let y = vec;
	println!("{:?} {:?}","y", y);
}

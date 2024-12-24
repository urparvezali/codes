#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(unused)]
#![allow(unused_macros)]
#![allow(unused_mut)]

mod B_Bowling_Frame;
mod C_Trinity;
mod B_Alice_s_Adventures_in_Permuting;
mod B_Black_Cells;

use std::{thread::sleep, time::{Duration, Instant}};

mod C_Preparing_for_the_Exam;
mod Playlist;
mod z;

fn main() {
    let now = Instant::now();
	sleep(Duration::from_nanos(1));
	let x = now.elapsed().as_nanos();
	println!("{}", x);
}

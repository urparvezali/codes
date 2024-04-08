#![no_main]

use std::collections::{HashMap, HashSet};
#![entry]
fn unique_numbers() -> bool {
    let arr: Vec<i32> = vec![1, 2, 3, 4, 5, 5];
    let mut map: HashMap<i32,i32> = HashMap::new();
    let mut set: HashSet<i32> = HashSet::new();
    for i in arr {
        *map.entry(i).or_insert(0)+=1;
    }
    for &i in map.values(){
		if set.contains(&i) {
			return false;
		}
		set.insert(i);
	}
	false
}

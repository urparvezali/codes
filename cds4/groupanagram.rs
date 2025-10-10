use std::collections::{BTreeMap, HashMap};

fn main() {
    let strs: Vec<String> = vec![
        "eat".to_string(),
        "tea".to_string(),
        "tan".to_string(),
        "ate".to_string(),
        "nat".to_string(),
        "bat".to_string(),
    ];
    let n = strs.len();
    let mut map: HashMap<BTreeMap<char, i32>, Vec<String>> = HashMap::new();
    for i in 0..n {
        let mut mp: BTreeMap<char, i32> = BTreeMap::new();
        strs[i].chars().for_each(|c| {
            *mp.entry(c).or_insert(0) += 1;
        });
        // println!("{:?}", mp);
        map.entry(mp).or_default().push(strs[i].clone());
    }
	let ans:Vec<Vec<String>> = map.into_iter().map(|(_, j)| j).collect();
	println!("{:?}",ans);
}

impl Solution {
    pub fn sort_array_by_parity_ii(mut a: Vec<i32>) -> Vec<i32> {
        a.sort_unstable_by_key(|v| v % 2);
        let mut b = a.iter().enumerate().collect::<Vec<(usize,&i32)>>();
        b.sort_by_key(|(i,v)| i% (a.len()/2));
        b.iter().map(|(i,v)| **v).collect::<Vec<i32>>()
    }
}
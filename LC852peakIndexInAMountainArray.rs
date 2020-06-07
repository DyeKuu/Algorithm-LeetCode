impl Solution {
    pub fn peak_index_in_mountain_array(a: Vec<i32>) -> i32 {
            a.iter().enumerate().max_by_key(|(_id,&val)| val).map(|(id,_val)| id).unwrap() as i32
    }
}
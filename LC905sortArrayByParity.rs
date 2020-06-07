impl Solution {
    pub fn sort_array_by_parity(mut a: Vec<i32>) -> Vec<i32> {
        a.sort_unstable_by_key(|x| x % 2);
    }
}
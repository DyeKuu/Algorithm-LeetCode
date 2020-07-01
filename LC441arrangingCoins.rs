impl Solution {
    pub fn arrange_coins(n: i32) -> i32 {
        ((((8 * n as i64 + 1) as f64).sqrt() - 1.) / 2.).floor() as i32
    }
}
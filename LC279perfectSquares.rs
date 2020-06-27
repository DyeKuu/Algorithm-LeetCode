use std::cmp;
impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let mut d: Vec<usize> = vec![0; (n + 1) as usize];
        d[1] = 1;
        Solution::num_squares_dp(n as usize, &mut d) as i32
    }

    pub fn num_squares_dp(n: usize, d: &mut Vec<usize>) -> usize {
        if d[n] > 0 {
            return d[n];
        }
        let m = (n as f64).sqrt().floor() as i32;
        let mut res = n - 1;
        for i in 1..m + 1 {
            res = cmp::min(res, Solution::num_squares_dp(n - (i * i) as usize, d));
        }
        d[n] = res + 1;
        d[n]
    }
}
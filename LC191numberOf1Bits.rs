impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        format!("{:b}", n).chars().map(|x| (x == '1') as i32).sum()
    }
}
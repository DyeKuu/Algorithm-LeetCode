impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::with_capacity(nums.len());
        for i in &nums{
            let sum:i32 = nums.iter().filter(|x| x < &i).map(|_x| 1).sum();
            res.push(sum);
        }
        res
    }
}
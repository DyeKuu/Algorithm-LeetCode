impl Solution {
    pub fn subsets(nums: Vec<i32>) -> Vec<Vec<i32>> {
        (0..2i32.pow(nums.len() as u32))
            .into_iter()
            .map(|x| {
                format!("{:0num$b}", x, num = nums.len())
                    .chars()
                    .enumerate()
                    .filter(|(_, c)| *c == '1')
                    .map(|(i, _)| nums[i])
                    .collect::<Vec<i32>>()
            })
            .collect::<Vec<Vec<i32>>>()
    }
}
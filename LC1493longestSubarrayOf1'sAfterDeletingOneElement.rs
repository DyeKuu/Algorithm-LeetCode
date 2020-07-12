impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let string: String = nums.into_iter().map(|i| i.to_string()).collect();
        let vector: Vec<usize> = string.split('0').map(|a| a.len()).collect();
        if vector.is_empty() {
            return 0;
        }
        if vector.len() == 1 {
            return (vector[0] - 1) as i32;
        }
        let sum: Vec<usize> = vector
            .iter()
            .zip(vector.iter().skip(1))
            .map(|(a, b)| a + b)
            .collect();
        if sum.is_empty() {
            return *vector.iter().max_by_key(|x| **x).unwrap() as i32;
        }
        *sum.iter().max_by_key(|x| **x).unwrap() as i32
    }
}
impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        for (i, &item) in arr.iter().enumerate() {
            let slice = &arr[..];
            for (j, &jtem) in slice.iter().enumerate() {
                if jtem * 2 == item && j != i {
                    return true;
                }
            }    
        }
        false
    }
}
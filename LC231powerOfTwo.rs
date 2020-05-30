impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n == 1 {
            return true;
        }
        if n == 0 {
            return false;
        }
        let mut x = n;
        while x % 2 == 0 {
            x /= 2;
        }
        if x == 1 {
            true
        }
        else {
            false
        }
    }
}
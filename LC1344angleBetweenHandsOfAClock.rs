impl Solution {
    pub fn angle_clock(hour: i32, minutes: i32) -> f64 {
        let res = (((hour % 12) as f64 + minutes as f64 / 60.) * 30. - minutes as f64 * 6.).abs();
        if res > 180. {
            360. - res
        } else {
            res
        }
    }
}
impl Solution {
    pub fn flip_and_invert_image(mut a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    a.iter_mut().map(|x| {
                            x.reverse();
                            x.iter().map(|&i| 1 - i).collect::<Vec<i32>>()})
                .collect::<Vec<Vec<i32>>>()
    }
}
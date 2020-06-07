pub fn shuffle(mut nums: Vec<i32>, n: i32) -> Vec<i32> {
    let mut a:Vec<(usize,i32)> = nums.into_iter().enumerate().collect();
    a.sort_by_key(|&(i,_)| i as i32 % n);
    let a:Vec<i32> = a.into_iter().map(|(_,e)| e).collect();
    a
}
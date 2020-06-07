impl Solution {
    pub fn is_monotonic(a: Vec<i32>) -> bool {
        a.iter().zip(a.iter().skip(1)).filter(|(&a,&b)| a >= b )
                                    .map(|(_,_)| 1)
                                    .sum::<usize>()
                                    == a.len() - 1 
        ||
        a.iter().zip(a.iter().skip(1)).filter(|(&a,&b)| a <= b )
                                    .map(|(_,_)| 1)
                                    .sum::<usize>()
                                    == a.len() - 1
    }
}
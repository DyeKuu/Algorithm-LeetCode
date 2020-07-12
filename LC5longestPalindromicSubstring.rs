impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        if s == "" {
            return String::from("");
        };
        let mut a: String = s.chars().map(|c| format!("{}{}", "*", c)).collect();
        a.push('*');
        let len = a.len();
        let mut l = vec![0; len];
        l[0] = 0;
        l[1] = 1;
        let mut c = 1;
        let mut r = 2;
        let mut imirror: i64;
        let mut expand = -1;
        let mut diff: i64;
        let mut maxLPSLength = 1;
        let mut maxLPSCenterPosition = 1;
        for i in 2..len {
            imirror = (2 * c as i64 - i as i64) as i64;
            expand = 0;
            diff = r as i64 - i as i64;

            if diff >= 0 {
                if l[imirror as usize] < diff {
                    l[i] = l[imirror as usize];
                } else if l[imirror as usize] == diff && r == len - 1 {
                    l[i] = l[imirror as usize];
                } else if l[imirror as usize] == diff && r < len - 1 {
                    l[i] = l[imirror as usize];
                    expand = 1;
                } else if l[imirror as usize] > diff {
                    l[i] = diff;
                    expand = 1;
                }
            } else {
                l[i] = 0;
                expand = 1;
            }
            if expand == 1 {
                while (i + l[i] as usize) < len - 1
                    && (i - l[i] as usize) > 0
                    && a.chars().nth(i + l[i] as usize + 1).unwrap()
                        == a.chars().nth(i - l[i] as usize - 1).unwrap()
                {
                    l[i] += 1;
                }
            }
            if l[i] > maxLPSLength {
                maxLPSLength = l[i];
                maxLPSCenterPosition = i;
            }
            if i + l[i] as usize > r {
                c = i;
                r = i + l[i] as usize;
            }
        }

        let start = (maxLPSCenterPosition - maxLPSLength as usize) / 2;
        let end = start + maxLPSLength as usize;
        //maxLPSCenterPosition as i64
        //maxLPSLength
        String::from(&s[start..end])
    }
}
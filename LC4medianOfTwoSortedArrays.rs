use std::cmp;
impl Solution {
    pub fn find_median_sorted_arrays(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> f64 {
        let (n, b, m, a) = if nums1.len() > nums2.len() {
            (nums1.len(), &mut nums1, nums2.len(), &mut nums2)
        } else {
            (nums2.len(), &mut nums2, nums1.len(), &mut nums1)
        };
        let (mut imin, mut imax, half_len) = (0, m, (m + n + 1) / 2);
        while imin <= imax {
            let i = (imin + imax) / 2;
            let j = half_len - i;
            if i < m && b[j - 1] > a[i] {
                imin = i + 1;
            } else if i > 0 && a[i - 1] > b[j] {
                imax = i - 1;
            } else {
                let max_of_left;
                let min_of_right;
                if i == 0 {
                    max_of_left = b[j - 1];
                } else if j == 0 {
                    max_of_left = a[i - 1];
                } else {
                    max_of_left = cmp::max(a[i - 1], b[j - 1]);
                }
                if (m + n) % 2 == 1 {
                    return max_of_left as f64;
                }
                if i == m {
                    min_of_right = b[j];
                } else if j == n {
                    min_of_right = a[i];
                } else {
                    min_of_right = cmp::min(a[i], b[j]);
                }
                return (max_of_left + min_of_right) as f64 / 2.;
            }
        }
        -1.
    }
}
impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.trim()
            .split_ascii_whitespace()
            .rev()
            .map(|x| x.to_string() + " ")
            .collect::<String>()
            .trim_end()
            .to_string()
    }
}
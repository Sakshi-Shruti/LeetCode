class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();   // lengths of s1 and s2

        // If s1 is longer than s2, s2 can never contain a permutation of s1
        if (n > m) return false;

        // need[c]   -> frequency of character c in s1 (fixed target pattern)
        // window[c] -> frequency of character c in the current window of s2
        vector<int> need(26, 0), window(26, 0);

        // Build both arrays together using the first n characters:
        // - 'need' gets filled from all of s1
        // - 'window' gets filled from the first n characters of s2 (the initial window)
        for (int i = 0; i < n; i++) {
            need[s1[i] - 'a']++;      // count this character of s1
            window[s2[i] - 'a']++;    // count this character of s2's first window
        }

        // Compare the two frequency arrays directly (element-by-element, 26 comparisons)
        // If they're identical, the first window is already a permutation of s1
        if (need == window) return true;

        // Slide the window one character at a time across the rest of s2
        for (int i = n; i < m; i++) {
            window[s2[i] - 'a']++;           // add new char entering window (right side)
            window[s2[i - n] - 'a']--;       // remove char leaving window (left side)

            // After each slide, compare the arrays again
            if (need == window) return true;
        }

        // No window ever matched 'need' -> s2 does not contain a permutation of s1
        return false;
    }
};
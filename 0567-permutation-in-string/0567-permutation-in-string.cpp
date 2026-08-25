class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is longer than s2, s2 can never contain a permutation of s1
        if (n > m) return false;

        vector<int> part(26,0);
        vector<int> window(26,0);

        for(int i = 0; i < n; i++) {
            part[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        if(part == window) return true;

        for(int i = n; i < m; i++) {
            window[s2[i] - 'a']++;
            window[s2[i-n] - 'a']--;

            if(part == window) return true;
        }

        return false;
    }
};
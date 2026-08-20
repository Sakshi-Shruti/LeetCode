class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCount;
        
        for(int i = 0 ; i < s.size(); i++) {
            charCount[s[i]]++; // create and increase the count 
        }

        for(int j = 0; j < t.size(); j++) {
            if(charCount.find(t[j]) != charCount.end()) {
                charCount[t[j]]--;

                // Fixed: if count drops to 0, erase the character so the map becomes empty
                if(charCount[t[j]] == 0) {
                    charCount.erase(t[j]);
                }
            } else {
                return false; // If a character in t is not found in s, it is not an anagram
            }
        }

        if(charCount.empty()) {  // now hashmap is empty so it is anargram
            return true;
        }
        return false; 
    }
};
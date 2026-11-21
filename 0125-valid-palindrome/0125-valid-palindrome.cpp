class Solution {
public:
    bool isAlphaNum(char ch) {
        // it inspects and return the ch from 0 to 9 and a to z
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }

        return false;
    }

    bool isPalindrome(string s) {
        int i = 0; int j = s.size() - 1;

        while(i < j) {
            if(!isAlphaNum(s[i])) { // check if it contains any punctuation or any space, if yes skip
                i++; continue;
            }
            if(!isAlphaNum(s[j])) {
                j--; continue;
            }

            if(tolower(s[i]) != tolower(s[j])) { //actual logic(on the actual char), convert the ch to lower case
                return false;
            }

            i++; j--;
        }
        return true;
    }
};
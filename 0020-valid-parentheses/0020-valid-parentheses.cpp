class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;

        for(int i = 0; i < n; i++) {
            if(map.find(s[i]) != map.end()) { //means we get the clos brac at the particular idx i
                //now check if the opening brac is the top of the stack, if no then return false
                if(st.empty() || st.top() != map[s[i]]) {
                    return false;
                } else {
                    st.pop();
                }
            } else { //means the idx contains the opening brac so push directly onto the stack
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
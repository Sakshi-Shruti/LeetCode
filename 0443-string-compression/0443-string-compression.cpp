class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        for(int i = 0; i < n; i++) {
            char ch = chars[i]; //store the char and then check by increasing the i whether it is correct or not
            int count = 0;

            while(i < n && ch == chars[i]) {
                count++;
                i++;
            }

            if(count == 1) {
                chars[idx++] = ch; //chars ke idx par ch ki string dalo and idx++ kar do
            } else {
                chars[idx++] = ch; //fisrt idx par char store hua next par count ko change kar diye string me then store
                string str = to_string(count);
                for(char dig : str) {
                    chars[idx++] = dig;
                }
            }
            i--; // do this or remove i++ from for loop
            //i is currently pointing to b but it should point to last of a so decrease the i
        }
        chars.resize(idx);
        return idx;
    }
};
class Solution {
public:
    int trap(vector<int>& ht) {
        int l = 0; int r = ht.size()-1;
        int lmax = 0; int rmax = 0;
        int ans = 0;
        while(l < r) {
            lmax = max(lmax, ht[l]); //left me iterate karke usme to lmax nikalo
            rmax = max(rmax, ht[r]);

            if(lmax < rmax) { //so now left will be deciding factor for trapping water no need for right boundary
                //for calc. value iske l ke liye hamesa lmax is boundary rahegi no matter what comes in right
                ans += (lmax - ht[l]); 
                l++; //Iterate for other trapped water in left
            } else { //rmax < lmax
                ans += (rmax - ht[r]);
                r--; //Iterate for other trapped water from right
            }
        }
        return ans;
    }
};
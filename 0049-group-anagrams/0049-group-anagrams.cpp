class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;
        
        for(int i = 0; i < strs.size(); i++) {
            string x = strs[i];        // pull the actual word first
            string temp = x;           // save original before sorting
            sort(x.begin(), x.end()); 
            umap[x].push_back(temp);
        }

        for(auto& p : umap) {          // range-based loop over the map
            ans.push_back(p.second);   
        }
        return ans;
    }
};
class Solution { //O(n) => so fast and optimal one
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int firstElem = nums[i];
            int secondElem = target - firstElem;

            if(map.find(secondElem) != map.end()) { //found the secondElement
                ans.push_back(i);  //have to return [i, m[sec]] => i means the first ele index and map[sec] the key/idx of second 
                ans.push_back(map[secondElem]);
                break;
            }

            map[firstElem] = i;
        }
        return ans;
    }
};

// Brute Force O(n^2)
//  class Solution { 
//  public:
//      vector<int> twoSum(vector<int>& nums, int target) {
//          int n = nums.size();
//          for(int i = 0; i < n; i++) {
//              for(int j = i+1; j < n; j++) {
//                  int sum = nums[i]+nums[j];
//                  if(sum == target) {
//                      return {i, j};
//                  }
//              }
//          }
//          return {};
//      }
//  };


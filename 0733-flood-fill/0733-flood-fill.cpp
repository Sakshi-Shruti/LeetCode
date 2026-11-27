class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int iniColor, int color) {
        int m = image.size();
        int n = image[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != iniColor) {  //out of bound condition (if image of certain position is not equal to the iniColor just return)
            return;
        }

        image[r][c] = color; //if equals then paint it with the given color

        //now recursively call this function for left, right, up and down
        dfs(image, r - 1, c, iniColor, color); // up
        dfs(image, r + 1, c, iniColor, color); // down
        dfs(image, r, c + 1, iniColor, color); // right
        dfs(image, r, c - 1, iniColor, color); // left
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc]; //store the iniColor of the starting point 

        if (iniColor == color) { //if the initial color is equals to the color given to paint then noting will change so return the image directly
            return image;
        }

        dfs(image, sr, sc, iniColor, color); //call the dfs function
        return image;
    }
};
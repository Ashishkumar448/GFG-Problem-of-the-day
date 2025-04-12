#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
        int n = image.size();
        int m = image[0].size();

        if (r < 0 || c < 0 || r >= n || c >= m || image[r][c] != color)
            return;

        image[r][c] = newColor;

        dfs(image, r + 1, c, color, newColor); // Down
        dfs(image, r - 1, c, color, newColor); // Up
        dfs(image, r, c + 1, color, newColor); // Right
        dfs(image, r, c - 1, color, newColor); // Left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor)
            return image;

        dfs(image, sr, sc, originalColor, newColor);
        return image;
    }
};

// Example usage
int main() {
    Solution obj;
    vector<vector<int>> image = {{1, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    int sr = 1, sc = 2, newColor = 2;

    vector<vector<int>> result = obj.floodFill(image, sr, sc, newColor);
    for (auto& row : result) {
        for (int pixel : row)
            cout << pixel << " ";
        cout << "\n";
    }
}

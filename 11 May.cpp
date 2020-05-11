class Solution {
public:

    // For all possible directions
    vector<pair<int, int>> direc = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};
    int n, m;

    void helper(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int cur = image[sr][sc];
        image[sr][sc] = newColor;

        for (auto p : direc)
        {
            int x = sr + p.first;
            int y = sc + p.second;

            if ( (x >= 0 && x < n) && (y >= 0 && y < m)  && image[x][y] == cur)
            {
                helper(image, x, y, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();

        // We dont need visited array because of this condition
        if (image[sr][sc] == newColor) return image;

        helper(image, sr, sc, newColor);
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        recursion(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

private:
    void recursion(vector<vector<int>>& image, int sr, int sc, int newColor, int curColor) {
        if (sr >= image.size() || sr < 0) return;
        if (sc >= image[0].size() || sc < 0) return;
        if(image[sr][sc] == newColor) return;
        
        if (image[sr][sc] == curColor) {
            image[sr][sc] = newColor;
            recursion(image, sr+1, sc, newColor, curColor);
            recursion(image, sr-1, sc, newColor, curColor);
            recursion(image, sr, sc+1, newColor, curColor);
            recursion(image, sr, sc-1, newColor, curColor);
        }
    }
};

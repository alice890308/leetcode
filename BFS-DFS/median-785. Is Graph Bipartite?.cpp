class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size()); // 1, 2兩種值
        for(int i = 0; i < color.size(); i++) {
            color[i] = 0;
        }
        
        bool ans;
        for(int i = 0; i < color.size(); i++) {
            if (color[i] == 0) {
                color[i] = 1;
                ans = coloring(graph, color, i);
                if (ans == false)
                    return false;
            }
        }
        return true;
    }
    
private:
    bool coloring(vector<vector<int>>& graph, vector<int>& color, int node) {
        bool temp;
        for(int i = 0; i < graph[node].size(); i++) {
            if (color[graph[node][i]] == color[node]) {
                return false;
            }

            else if (color[graph[node][i]] == 0) {
                color[graph[node][i]] = (color[node] == 1) ? 2 : 1;
                temp = coloring(graph, color, graph[node][i]);
                if (temp == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> visited(numCourses); // 確認這堂課是否已經被選走了，0表示沒有，1表示正在搜尋，2表示已完成
        vector<int> order;
        bool temp;
        int run = 1;
        
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; i++){
            visited[i] = 0;
        }
        
        for(int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                temp = DFS(i, graph, visited, order);
                run++;
                if (temp == false) {
                    order.clear();
                    return order;
                }
            }
        }
        return order;
    }

private:
    bool DFS(int pos, vector<vector<int> >& graph, vector<int> &visited, vector<int> &order) {
        bool temp;
        visited[pos] = 1;
        for(int i = 0; i < graph[pos].size(); i++) {
            if (visited[graph[pos][i]] == 1) {
                return false; // 產生cycle
            }
            else if (visited[graph[pos][i]] == 0){
                temp = DFS(graph[pos][i], graph, visited, order);
                if (temp == false)
                    return false; 
            }
        }
        visited[pos] = 2;
        
        order.push_back(pos);
        return true;
    }
};
